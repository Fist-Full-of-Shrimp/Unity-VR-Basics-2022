#pragma once

template <>
void SendToCSharp<XrEventDataBuffer*>(const char* fieldname, XrEventDataBuffer* t)
{
    XrEventDataBaseHeader* evt = reinterpret_cast<XrEventDataBaseHeader*>(t);
    SendToCSharp("varying", evt);
}

template <>
void SendToCSharp<XrDebugUtilsMessengerCreateInfoEXT const*>(const char* fieldname, XrDebugUtilsMessengerCreateInfoEXT const* t)
{
    SendToCSharp(fieldname, "<TODO: XrDebugUtilsMessengerCreateInfoEXT>");
}

template <>
void SendToCSharp<XrSpatialGraphNodeSpaceCreateInfoMSFT const*>(const char* fieldname, XrSpatialGraphNodeSpaceCreateInfoMSFT const* t)
{
    SendToCSharp(fieldname, "<TODO: XrSpatialGraphNodeSpaceCreateInfoMSFT>");
}

template <>
void SendToCSharp<XrInteractionProfileAnalogThresholdVALVE*>(const char* fieldname, XrInteractionProfileAnalogThresholdVALVE* t)
{
    SendToCSharp(fieldname, "<TODO: XrInteractionProfileAnalogThresholdVALVE>");
}
