#pragma once

#define SPECIALIZED_FUNCS(_) \
    _(xrLoadControllerModelMSFT, void)

static PFN_xrLoadControllerModelMSFT orig_xrLoadControllerModelMSFT;
XrResult UNITY_INTERFACE_EXPORT XRAPI_PTR xrLoadControllerModelMSFT(XrSession session, XrControllerModelKeyMSFT modelKey, uint32_t bufferCapacityInput, uint32_t* bufferCountOutput, uint8_t* buffer)
{
    StartFunctionCall("xrLoadControllerModelMSFT");
    XrResult result = orig_xrLoadControllerModelMSFT(session, modelKey, bufferCapacityInput, bufferCountOutput, buffer);
    SendToCSharp("session", session);
    SendToCSharp("modelKey", modelKey);
    SendToCSharp("bufferCapacityInput", bufferCapacityInput);
    SendToCSharp("bufferCountOutput", bufferCountOutput);
    SendToCSharp("buffer", "<TODO>");
    EndFunctionCall("xrLoadControllerModelMSFT", XrEnumStr(result));
    return result;
}