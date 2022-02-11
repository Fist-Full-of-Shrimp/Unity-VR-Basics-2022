#include "mock.h"

typedef XrResult(XRAPI_PTR* PFN_BeforeFunctionCallback)(const char* name);
typedef void(XRAPI_PTR* PFN_AfterFunctionCallback)(const char* name, XrResult result);

PFN_BeforeFunctionCallback s_BeforeFunctionCallback = nullptr;
PFN_AfterFunctionCallback s_AfterFunctionCallback = nullptr;

XrResult MockRuntime_BeforeFunction(const char* name)
{
    if (s_BeforeFunctionCallback == nullptr)
        return XR_SUCCESS;

    return s_BeforeFunctionCallback(name);
}

void MockRuntime_AfterFunction(const char* name, XrResult result)
{
    if (s_AfterFunctionCallback == nullptr)
        return;

    s_AfterFunctionCallback(name, result);
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_SetView(XrViewConfigurationType viewConfigurationType, int viewIndex, UnityVector3 position, UnityVector4 orientation, UnityVector4 fov)
{
    if (nullptr == s_runtime)
        return;

    s_runtime->SetViewPose(viewConfigurationType, viewIndex, {orientation, position}, fov);
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_SetViewState(XrViewConfigurationType viewConfigurationType, XrViewStateFlags stateFlags)
{
    if (nullptr == s_runtime)
        return;

    s_runtime->SetViewStateFlags(viewConfigurationType, stateFlags);
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_SetReferenceSpace(XrReferenceSpaceType referenceSpace, UnityVector3 position, UnityVector4 orientation, XrSpaceLocationFlags locationFlags)
{
    if (nullptr == s_runtime)
        return;

    s_runtime->SetSpace(referenceSpace, {orientation, position}, locationFlags);
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_SetActionSpace(XrAction action, UnityVector3 position, UnityVector4 orientation, XrSpaceLocationFlags locationFlags)
{
    if (nullptr == s_runtime)
        return;

    s_runtime->SetSpace(action, {orientation, position}, locationFlags);
}

extern "C" XrSessionState UNITY_INTERFACE_EXPORT MockRuntime_GetSessionState()
{
    if (nullptr == s_runtime)
        return XR_SESSION_STATE_UNKNOWN;

    return s_runtime->GetSessionState();
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_RequestExitSession()
{
    if (nullptr == s_runtime)
        return;

    s_runtime->RequestExitSession();
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_CauseInstanceLoss()
{
    if (nullptr == s_runtime)
        return;

    s_runtime->CauseInstanceLoss();
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_SetEnvironmentBlendMode(XrEnvironmentBlendMode environmentBlendMode)
{
    if (nullptr == s_runtime)
        return;

    s_runtime->SetEnvironmentBlendMode(environmentBlendMode);
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_SetReferenceSpaceBounds(XrReferenceSpaceType referenceSpaceType, XrExtent2Df bounds)
{
    if (nullptr == s_runtime)
        return;

    s_runtime->SetExtentsForReferenceSpace(referenceSpaceType, bounds);
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_GetEndFrameStats(int* primaryLayerCount, int* secondaryLayerCount)
{
    *primaryLayerCount = 0;
    *secondaryLayerCount = 0;

    if (nullptr == s_runtime)
        return;

    s_runtime->GetEndFrameStats(primaryLayerCount, secondaryLayerCount);
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_ActivateSecondaryView(XrViewConfigurationType viewConfigurationType, bool activate)
{
    if (nullptr == s_runtime)
        return;

    s_runtime->ActivateSecondaryView(viewConfigurationType, activate);
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_RegisterScriptEventCallback(PFN_ScriptEventCallback callback)
{
    if (nullptr == s_runtime)
        return;

    s_runtime->RegisterScriptEventCallback(callback);
}

extern "C" void UNITY_INTERFACE_EXPORT MockRuntime_RegisterFunctionCallbacks(PFN_BeforeFunctionCallback before, PFN_AfterFunctionCallback after)
{
    s_BeforeFunctionCallback = before;
    s_AfterFunctionCallback = after;
}

extern "C" bool UNITY_INTERFACE_EXPORT XRAPI_PTR MockRuntime_TransitionToState(XrSessionState requestedState, bool forceTransition)
{
    if (nullptr == s_runtime)
        return false;

    if (!forceTransition && !s_runtime->IsStateTransitionValid(requestedState))
    {
        MOCK_TRACE_ERROR("Failed to request state. Was transition valid: %s with force %s",
            s_runtime->IsStateTransitionValid(requestedState) ? "TRUE" : "FALSE",
            forceTransition ? "TRUE" : "FALSE");
        return false;
    }

    s_runtime->ChangeSessionState(requestedState);

    return true;
}
