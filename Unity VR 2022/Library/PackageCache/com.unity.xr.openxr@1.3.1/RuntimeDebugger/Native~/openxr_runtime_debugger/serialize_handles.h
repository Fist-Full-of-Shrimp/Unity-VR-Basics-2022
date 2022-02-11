#pragma once

// Handles are defined as uin64_t on 32-bit builds.  They already have a template defined, so we need to exclude this block from 32-bit builds.
// (and remember that _WIN32 is defined on 64-bit windows builds)
#if (_WIN32 && _WIN64) || (!_WIN32 && !_WIN64)
#define SEND_TO_CSHARP_HANDLES(handlename)                             \
    template <>                                                        \
    void SendToCSharp<handlename>(const char* fieldname, handlename t) \
    {                                                                  \
        SendToCSharp(fieldname, (uint64_t)t);                          \
    }

XR_LIST_HANDLES(SEND_TO_CSHARP_HANDLES)

#define SEND_TO_CSHARP_HANDLES_PTRS(handlename)                          \
    template <>                                                          \
    void SendToCSharp<handlename*>(const char* fieldname, handlename* t) \
    {                                                                    \
        if (t != nullptr)                                                \
            SendToCSharp(fieldname, (uint64_t)*t);                       \
        else                                                             \
            SendToCSharp(fieldname, (uint64_t)0);                        \
    }

XR_LIST_HANDLES(SEND_TO_CSHARP_HANDLES_PTRS)
#endif
