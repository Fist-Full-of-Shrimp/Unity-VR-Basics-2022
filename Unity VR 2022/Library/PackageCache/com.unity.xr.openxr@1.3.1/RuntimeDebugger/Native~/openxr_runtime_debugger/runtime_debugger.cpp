#include "platform_includes.h"

#define XR_NO_PROTOTYPES
#include <openxr/openxr.h>
#include <openxr/openxr_platform.h>

#include "openxr/openxr_reflection_full.h"

#include <cstring>
#include <type_traits>

#include "api_exports.h"

#include "serialize_data.h"
#include "serialize_data_access.h"

#define CATCH_MISSING_TEMPLATES 0

template <typename T>
void SendToCSharp(const char* fieldname, T t)
#if !CATCH_MISSING_TEMPLATES
{
    SendString(fieldname, "<Unknown>");
}
#else
    ;
#endif

// Arrays of base structs
template <typename structType>
bool SendToCSharpBaseStructArray(const char* fieldname, structType t, int lenParam)
{
    return false;
}

// These includes are order-sensitive
// clang-format off
#include "serialize_primitives.h"
#include "serialize_enums.h"
#include "serialize_handles.h"
#include "serialize_atoms.h"
#include "serialize_nextptr.h"
#include "serialize_structs.h"
#include "serialize_todo.h"
#include "serialize_nextptr_impl.h"

#include "serialize_funcs.h"
#include "serialize_funcs_specialization.h"
// clang-format on

extern "C" XrResult UNITY_INTERFACE_EXPORT XRAPI_PTR xrGetInstanceProcAddr(XrInstance instance, const char* name, PFN_xrVoidFunction* function)
{
    StartFunctionCall("xrGetInstanceProcAddr");
    SendToCSharp("instance", instance);
    SendToCSharp("name", name);
    SendToCSharp("function", "<func>");

    XR_LIST_FUNCS(GEN_FUNC_LOAD)

    SPECIALIZED_FUNCS(GEN_FUNC_LOAD)

    EndFunctionCall("xrGetInstanceProcAddr", "UNKNOWN FUNC");

    return orig_xrGetInstanceProcAddr(instance, name, function);
}

extern "C" PFN_xrGetInstanceProcAddr UNITY_INTERFACE_EXPORT XRAPI_PTR HookXrInstanceProcAddr(PFN_xrGetInstanceProcAddr func, uint32_t cacheSize, uint32_t perThreadCacheSize)
{
    s_CacheSize = cacheSize;
    s_PerThreadCacheSize = perThreadCacheSize;
    orig_xrGetInstanceProcAddr = func;
    return xrGetInstanceProcAddr;
}
