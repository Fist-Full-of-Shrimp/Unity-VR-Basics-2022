#pragma once

template <>
void SendToCSharp<XrSystemId*>(const char* fieldname, XrSystemId* t)
{
    SendToCSharp(fieldname, *t);
}