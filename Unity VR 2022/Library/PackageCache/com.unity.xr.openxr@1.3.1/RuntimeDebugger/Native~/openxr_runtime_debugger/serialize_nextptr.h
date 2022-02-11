#pragma once

template <>
void SendToCSharp<XrBaseOutStructure*>(const char* fieldname, XrBaseOutStructure* t);

template <>
void SendToCSharp<XrBaseInStructure const*>(const char* fieldname, XrBaseInStructure const* t);

template <>
void SendToCSharp<void*>(const char* fieldname, void* t)
{
    if (t != nullptr && strcmp(fieldname, "next") == 0)
    {
        SendToCSharp(fieldname, reinterpret_cast<XrBaseOutStructure*>(t));
    }
    else
    {
        SendToCSharp(fieldname, (uint64_t)t);
    }
}

template <>
void SendToCSharp<void const*>(const char* fieldname, void const* t)
{
    if (t != nullptr && strcmp(fieldname, "next") == 0)
    {
        SendToCSharp(fieldname, reinterpret_cast<XrBaseInStructure const*>(t));
    }
    else
    {
        SendToCSharp(fieldname, (uint64_t)t);
    }
}
