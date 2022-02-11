#include "plugin_load.h"

#include <string>

#if defined(XR_USE_PLATFORM_WIN32) && !defined(XR_USE_PLATFORM_UWP)

PluginHandle Plugin_LoadLibrary(const char* libName)
{
    std::string lib(libName);
    if ((lib.size() >= 1 && lib[0] == '.') ||
        lib.find('/') == std::string::npos && lib.find('\\') == std::string::npos)
    {
        // Look up path of current dll
        char path[MAX_PATH];
        HMODULE hm = NULL;
        if (GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                    GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                (LPCWSTR)&Plugin_LoadLibrary, &hm) == 0)
        {
            int ret = GetLastError();
            fprintf(stderr, "GetModuleHandle failed, error = %d\n", ret);
            return NULL;
        }
        if (GetModuleFileNameA(hm, path, sizeof(path)) == 0)
        {
            int ret = GetLastError();
            fprintf(stderr, "GetModuleFileName failed, error = %d\n", ret);
            return NULL;
        }

        std::string basePath(path);
        basePath = basePath.substr(0, basePath.find_last_of('\\') + 1);

        lib = basePath + lib + ".dll";
    }

    HMODULE handle = LoadLibraryA(lib.c_str());
    if (handle == NULL)
    {
        int ret = GetLastError();
        fprintf(stderr, "LoadLibraryA failed, error = %d\n", ret);
    }
    return handle;
}

void Plugin_FreeLibrary(PluginHandle handle)
{
    FreeLibrary(handle);
}

PluginFunc Plugin_GetSymbol(PluginHandle handle, const char* symbol)
{
    return GetProcAddress(handle, symbol);
}

#elif defined(XR_USE_PLATFORM_UWP)

PluginHandle Plugin_LoadLibrary(const char* libName)
{
    std::wstring lib(&libName[0], &libName[strlen(libName)]);
    HMODULE handle = LoadPackagedLibrary(lib.c_str(), 0);
    if (handle == NULL)
    {
        int ret = GetLastError();
        fprintf(stderr, "LoadPackagedLibrary failed, error = %d\n", ret);
    }
    return handle;
}

void Plugin_FreeLibrary(PluginHandle handle)
{
    FreeLibrary(handle);
}

PluginFunc Plugin_GetSymbol(PluginHandle handle, const char* symbol)
{
    return GetProcAddress(handle, symbol);
}

#else // Posix

PluginHandle Plugin_LoadLibrary(const char* libName)
{
    std::string lib(libName);
    if ((lib.size() >= 1 && lib[0] == '.') ||
        (lib.find('/') == std::string::npos && lib.find('\\') == std::string::npos))
    {
        Dl_info info;
        if (dladdr((const void*)&Plugin_LoadLibrary, &info) != 0)
        {
            std::string basePath(info.dli_fname);
            basePath = basePath.substr(0, basePath.find_last_of('/') + 1);

#if !defined(XR_USE_PLATFORM_OSX)
            if (lib[0] != '.')
                lib = basePath + "lib" + lib;
            else
#endif
                lib = basePath + lib;
#if defined(XR_USE_PLATFORM_OSX)
            lib += ".dylib";
#else
            lib += ".so";
#endif
        }
    }
    return dlopen(lib.c_str(), RTLD_LAZY);
}

void Plugin_FreeLibrary(PluginHandle handle)
{
    dlclose(handle);
}

PluginFunc Plugin_GetSymbol(PluginHandle handle, const char* symbol)
{
    return dlsym(handle, symbol);
}
#endif
