using System;
using System.Collections.Generic;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using UnityEngine.XR.OpenXR.NativeTypes;
#if UNITY_EDITOR
using UnityEditor;
using UnityEditor.XR.OpenXR.Features;
#endif

[assembly:InternalsVisibleTo("Unity.XR.OpenXR.Tests")]
[assembly:InternalsVisibleTo("Unity.XR.OpenXR.Tests.Editor")]
namespace UnityEngine.XR.OpenXR.Features.Mock
{
#if UNITY_EDITOR
    [OpenXRFeature(UiName = "Mock Runtime",
        BuildTargetGroups = new []{UnityEditor.BuildTargetGroup.Standalone},
        Company = "Unity",
        Desc = "Mock runtime extension for automated testing.",
        DocumentationLink = Constants.k_DocumentationURL,
        CustomRuntimeLoaderBuildTargets = new [] { UnityEditor.BuildTarget.StandaloneWindows64, UnityEditor.BuildTarget.StandaloneOSX },
        OpenxrExtensionStrings = MockRuntime.XR_UNITY_null_gfx,
        Version = "0.0.2",
        FeatureId = featureId)]
#endif
    internal class MockRuntime : OpenXRFeature
    {
        public enum ScriptEvent
        {
            Unknown,
            EndFrame,
            HapticImpulse,
            HapticStop
        }

        public delegate void ScriptEventDelegate(ScriptEvent evt, ulong param);
        public delegate XrResult BeforeFunctionDelegate(string functionName);
        public delegate void AfterFunctionDelegate(string functionName, XrResult result);

        private static Dictionary<string, AfterFunctionDelegate> s_AfterFunctionCallbacks = null;
        private static Dictionary<string, BeforeFunctionDelegate> s_BeforeFunctionCallbacks = null;

        public static event ScriptEventDelegate onScriptEvent;

        /// <summary>
        /// The feature id string. This is used to give the feature a well known id for reference.
        /// </summary>
        public const string featureId = "com.unity.openxr.feature.mockruntime";

        /// <summary>
        /// Don't fail to build if there are validation errors.
        /// </summary>
        public bool ignoreValidationErrors = false;

        /// <summary>
        /// Return the singleton instance of the Mock Runtime feature.
        /// </summary>
        public static MockRuntime Instance => OpenXRSettings.Instance.GetFeature<MockRuntime>();

        [AOT.MonoPInvokeCallback(typeof(ScriptEventDelegate))]
        private static void ReceiveScriptEvent(ScriptEvent evt, ulong param) => onScriptEvent?.Invoke(evt, param);

        [AOT.MonoPInvokeCallback(typeof(BeforeFunctionDelegate))]
        private static XrResult BeforeFunctionCallback (string function)
        {
            var callback = GetBeforeFunctionCallback(function);
            if(null == callback)
                return XrResult.Success;

            return callback(function);
        }

        [AOT.MonoPInvokeCallback(typeof(BeforeFunctionDelegate))]
        private static void AfterFunctionCallback(string function, XrResult result)
        {
            var callback = GetAfterFunctionCallback(function);
            if (null == callback)
                return;

            callback(function, result);
        }

        /// <summary>
        /// Set the callbacks to call before and after the given OpenXR function is called within the Mock Runtime
        ///
        /// Note that since some OpenXR functions are called from within the graphics thread that care should
        /// be taken to maintain thread safety from within the callbacks.
        ///
        /// Note that function callbacks can be set prior to the MockRuntime being initialized but will be
        /// reset when the mock runtime is shutdown.
        /// </summary>
        /// <param name="function">OpenXR function name</param>
        /// <param name="beforeCallback">Callback to call before the OpenXR function is called (null to clear)</param>
        /// <param name="afterCallback">Callback to call after the OpenXR function is called (null to clear)</param>
        public static void SetFunctionCallback(string function, BeforeFunctionDelegate beforeCallback, AfterFunctionDelegate afterCallback)
        {
            if (beforeCallback != null)
            {
                if (null == s_BeforeFunctionCallbacks)
                    s_BeforeFunctionCallbacks = new Dictionary<string, BeforeFunctionDelegate>();

                s_BeforeFunctionCallbacks[function] = beforeCallback;
            }
            else if (s_BeforeFunctionCallbacks != null)
            {
                s_BeforeFunctionCallbacks.Remove(function);
                if (s_BeforeFunctionCallbacks.Count == 0)
                    s_BeforeFunctionCallbacks = null;
            }

            if (afterCallback != null)
            {
                if (null == s_AfterFunctionCallbacks)
                    s_AfterFunctionCallbacks = new Dictionary<string, AfterFunctionDelegate>();

                s_AfterFunctionCallbacks[function] = afterCallback;
            }
            else if (s_AfterFunctionCallbacks != null)
            {
                s_AfterFunctionCallbacks.Remove(function);
                if (s_AfterFunctionCallbacks.Count == 0)
                    s_AfterFunctionCallbacks = null;
            }

            MockRuntime_RegisterFunctionCallbacks(
                s_BeforeFunctionCallbacks != null ? BeforeFunctionCallback : (BeforeFunctionDelegate)null,
                s_AfterFunctionCallbacks != null ? AfterFunctionCallback : (AfterFunctionDelegate)null);
        }

        /// <summary>
        /// Set a callback to call before the given OpenXR function is called within the Mock Runtime
        ///
        /// Note that since some OpenXR functions are called from within the graphics thread that care should
        /// be taken to maintain thread safety from within the callbacks.
        ///
        /// Note that function callbacks can be set prior to the MockRuntime being initialized but will be
        /// reset when the mock runtime is shutdown.
        /// </summary>
        /// <param name="function">OpenXR function name</param>
        /// <param name="beforeCallback">Callback to call before the OpenXR function is called (null to clear)</param>
        public static void SetFunctionCallback(string function, BeforeFunctionDelegate beforeCallback) =>
            SetFunctionCallback(function, beforeCallback, GetAfterFunctionCallback(function));

        /// <summary>
        /// Set a callback to call before the given OpenXR function is called within the Mock Runtime
        /// </summary>
        /// <param name="function">OpenXR function name</param>
        /// <param name="afterCallback">Callback to call after the OpenXR function is called (null to clear)</param>
        public static void SetFunctionCallback(string function, AfterFunctionDelegate afterCallback) =>
            SetFunctionCallback(function, GetBeforeFunctionCallback(function), afterCallback);

        /// <summary>
        /// Return the callback set to be called before the given OpenXR function is called
        /// </summary>
        /// <param name="function">OpenXR function name</param>
        /// <returns>Callback or null if no callback is set</returns>
        public static BeforeFunctionDelegate GetBeforeFunctionCallback(string function)
        {
            if (null == s_BeforeFunctionCallbacks)
                return null;

            if (!s_BeforeFunctionCallbacks.TryGetValue(function, out var callback))
                return null;

            return callback;
        }

        /// <summary>
        /// Return the callback set to be called after the given OpenXR function is called
        /// </summary>
        /// <param name="function">OpenXR function name</param>
        /// <returns>Callback or null if no callback is set</returns>
        public static AfterFunctionDelegate GetAfterFunctionCallback(string function)
        {
            if (null == s_AfterFunctionCallbacks)
                return null;

            if (!s_AfterFunctionCallbacks.TryGetValue(function, out var callback))
                return null;

            return callback;
        }

        /// <summary>
        /// Remove all OpenXR function callbacks
        /// </summary>
        public static void ClearFunctionCallbacks ()
        {
            s_BeforeFunctionCallbacks = null;
            s_AfterFunctionCallbacks = null;
            MockRuntime_RegisterFunctionCallbacks(null, null);
        }

        /// <summary>
        /// Reset the MockRuntime testing settings back to defaults
        /// </summary>
        public static void ResetDefaults()
        {
#if UNITY_INCLUDE_TESTS
            var instance = Instance;
            instance.TestCallback = (methodName, param) => true;
#endif

            onScriptEvent = null;

            ClearFunctionCallbacks();
        }

        protected internal override void OnInstanceDestroy(ulong instance)
        {
#if UNITY_INCLUDE_TESTS
            TestCallback(MethodBase.GetCurrentMethod().Name, instance);
            XrInstance = 0ul;
#endif

            // When the mock runtime instance shuts down we remove any callbacks that
            // were set up to ensure they do not linger around for the next usage of the mock runtime.
            ClearFunctionCallbacks();
        }


#if UNITY_INCLUDE_TESTS
        [NonSerialized] public Func<string, object, object> TestCallback = (methodName, param) => true;

        public const string XR_UNITY_mock_test = "XR_UNITY_mock_test";

        public const string XR_UNITY_null_gfx = "XR_UNITY_null_gfx";

        public ulong XrInstance { get; private set; } = 0ul;

        public ulong XrSession { get; private set; } = 0ul;

        /// <summary>
        /// Return the current session state of the MockRuntime
        /// </summary>
        public static XrSessionState sessionState => Internal_GetSessionState();

        protected internal override IntPtr HookGetInstanceProcAddr(IntPtr func)
        {
            var ret = TestCallback(MethodBase.GetCurrentMethod().Name, func);
            if (!(ret is IntPtr))
                return func;
            return (IntPtr)ret;
        }

        protected internal override void OnSystemChange(ulong xrSystem)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, xrSystem);
        }

        protected internal override bool OnInstanceCreate(ulong xrInstance)
        {
            var result = (bool)TestCallback(MethodBase.GetCurrentMethod().Name, xrInstance);
            if (result)
                XrInstance = xrInstance;

            Internal_RegisterScriptEventCallback(ReceiveScriptEvent);

            return result;
        }

        protected internal override void OnSessionCreate(ulong xrSession)
        {
            XrSession = xrSession;
            TestCallback(MethodBase.GetCurrentMethod().Name, xrSession);
        }

        protected internal override void OnSessionBegin (ulong xrSession)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, xrSession);
        }

        protected internal override void OnAppSpaceChange (ulong xrSpace)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, xrSpace);
        }

        protected internal override void OnSessionEnd (ulong xrSession)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, xrSession);
        }

        protected internal override void OnSessionDestroy (ulong session)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, session);
            XrSession = 0ul;
        }

        protected internal override void OnSessionLossPending (ulong xrSession)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, xrSession);
        }

        protected internal override void OnInstanceLossPending (ulong xrInstance)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, xrInstance);
        }

        protected internal override void OnSubsystemCreate()
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, 0);
        }

        protected internal override void OnSubsystemStart()
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, 0);
        }

        protected internal override void OnSessionExiting(ulong xrSession)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, 0);
        }

        protected internal override void OnSubsystemDestroy()
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, 0);
        }

        protected internal override void OnSubsystemStop()
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, 0);
        }

        protected internal override void OnFormFactorChange(int xrFormFactor)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, xrFormFactor);
        }

        protected internal override void OnEnvironmentBlendModeChange(int xrEnvironmentBlendMode)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, xrEnvironmentBlendMode);
        }

        protected internal override void OnViewConfigurationTypeChange(int xrViewConfigurationType)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, xrViewConfigurationType);
        }

        internal class XrSessionStateChangedParams
        {
            public int OldState;
            public int NewState;
        }

        protected internal override void OnSessionStateChange(int oldState, int newState)
        {
            TestCallback(MethodBase.GetCurrentMethod().Name, new XrSessionStateChangedParams() {OldState = oldState, NewState = newState});
        }

        public static bool TransitionToState(XrSessionState state, bool forceTransition)
        {
            var instance = Instance;
            if (instance.XrSession == 0)
                return false;

            return Internal_TransitionToState(state, forceTransition);
        }

#if UNITY_EDITOR
        protected internal override void GetValidationChecks(List<ValidationRule> results, BuildTargetGroup target)
        {
            if (ignoreValidationErrors)
                results.Clear();
            TestCallback(MethodBase.GetCurrentMethod().Name, results);
        }
#endif
#endif

        const string extLib = "mock_runtime";

        [DllImport(extLib, EntryPoint = "MockRuntime_SetView")]
        public static extern void SetViewPose(XrViewConfigurationType viewConfigurationType, int viewIndex, Vector3 position, Quaternion orientation, Vector4 fov);

        [DllImport(extLib, EntryPoint = "MockRuntime_SetViewState")]
        public static extern void SetViewState(XrViewConfigurationType viewConfigurationType, XrViewStateFlags viewStateFlags);

        [DllImport(extLib, EntryPoint = "MockRuntime_SetReferenceSpace")]
        public static extern void SetSpace(XrReferenceSpaceType referenceSpace, Vector3 position, Quaternion orientation, XrSpaceLocationFlags locationFlags);

        [DllImport(extLib, EntryPoint = "MockRuntime_SetActionSpace")]
        public static extern void SetSpace(ulong actionHandle, Vector3 position, Quaternion orientation, XrSpaceLocationFlags locationFlags);

        [DllImport(extLib, EntryPoint = "MockRuntime_RegisterScriptEventCallback")]
        private static extern XrResult Internal_RegisterScriptEventCallback(ScriptEventDelegate callback);

        [DllImport(extLib, EntryPoint = "MockRuntime_TransitionToState")]
        private static extern bool Internal_TransitionToState(XrSessionState state, bool forceTransition);

        [DllImport(extLib, EntryPoint = "MockRuntime_GetSessionState")]
        private static extern XrSessionState Internal_GetSessionState ();

        [DllImport(extLib, EntryPoint = "MockRuntime_RequestExitSession")]
        public static extern void RequestExitSession();

        [DllImport(extLib, EntryPoint = "MockRuntime_CauseInstanceLoss")]
        public static extern void CauseInstanceLoss();

        [DllImport(extLib, EntryPoint = "MockRuntime_SetEnvironmentBlendMode")]
        public static extern void SetEnvironmentBlendMode(XrEnvironmentBlendMode environmentBlendMode);

        [DllImport(extLib, EntryPoint = "MockRuntime_SetReferenceSpaceBounds")]
        internal static extern void SetReferenceSpaceBounds (XrReferenceSpaceType referenceSpace, Vector2 bounds);

        [DllImport(extLib, EntryPoint = "MockRuntime_GetEndFrameStats")]
        internal static extern void GetEndFrameStats(out int primaryLayerCount, out int secondaryLayerCount);

        [DllImport(extLib, EntryPoint = "MockRuntime_ActivateSecondaryView")]
        internal static extern void ActivateSecondaryView(XrViewConfigurationType viewConfigurationType, bool activate);

        [DllImport(extLib, EntryPoint = "MockRuntime_RegisterFunctionCallbacks")]
        private static extern void MockRuntime_RegisterFunctionCallbacks(BeforeFunctionDelegate hookBefore, AfterFunctionDelegate hookAfter);
    }
}
