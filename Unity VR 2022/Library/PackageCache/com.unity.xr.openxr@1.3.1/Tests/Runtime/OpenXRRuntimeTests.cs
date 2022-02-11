using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using NUnit.Framework;
using UnityEngine.XR.OpenXR.Features;
using UnityEngine.XR.OpenXR.Features.Mock;
using UnityEngine.TestTools;
using UnityEngine.XR.OpenXR.NativeTypes;

namespace UnityEngine.XR.OpenXR.Tests
{
    internal class OpenXRRuntimeTests : OpenXRLoaderSetup
    {
        [UnityTest]
        public IEnumerator SystemIdRetrieved()
        {
            bool systemIdReceived = false;
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                if (methodName == nameof(OpenXRFeature.OnSystemChange))
                {
                    systemIdReceived = true;
                    Assert.AreEqual(2, param);
                }

                return true;
            };

            base.InitializeAndStart();
            yield return null;

            Assert.IsTrue(systemIdReceived);
        }

        [UnityTest]
        public IEnumerator SessionBegan()
        {
            bool sessionBegan = false;
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                if (methodName == nameof(OpenXRFeature.OnSessionBegin))
                {
                    sessionBegan = true;
                    Assert.AreEqual(3, param);
                }

                return true;
            };

            base.InitializeAndStart();
            yield return null;

            Assert.IsTrue(sessionBegan);
        }

        [UnityTest]
        public IEnumerator SessionEnded()
        {
            bool sessionStarted = false;
            bool sessionEnded = false;
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                switch (methodName)
                {
                    case nameof(OpenXRFeature.OnSessionBegin):
                        Assert.IsFalse(sessionStarted);
                        sessionStarted = true;
                        Assert.AreEqual(3, param);
                        break;
                    case nameof(OpenXRFeature.OnSessionEnd):
                        Assert.IsTrue(sessionStarted);
                        Assert.AreEqual(3, param);
                        sessionStarted = false;
                        sessionEnded = true;
                        break;
                }

                return true;
            };

            base.InitializeAndStart();

            const int ITERATION_MAX_COUNT = 10;
            int waitCount = 0;
            while (!sessionStarted && waitCount++ < ITERATION_MAX_COUNT)
                yield return null;

            Assert.IsTrue(sessionStarted);

            base.StopAndShutdown();

            Assert.IsTrue(sessionEnded);
        }

        [Test]
        public void SessionDestroyed()
        {
            bool sessionDestroyed = false;
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                if (methodName == nameof(OpenXRFeature.OnSessionDestroy))
                {
                    sessionDestroyed = true;
                    Assert.AreEqual(3, param);
                }

                return true;
            };

            base.InitializeAndStart();
            base.StopAndShutdown();

            Assert.IsTrue(sessionDestroyed);
        }

        [Test]
        public void InstanceDestroyed()
        {
            object instance = null;
            bool instanceDestroyed = false;
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                if (methodName == nameof(OpenXRFeature.OnInstanceCreate))
                {
                    instance = param;
                }

                if (methodName == nameof(OpenXRFeature.OnInstanceDestroy))
                {
                    instanceDestroyed = true;
                    Assert.AreEqual(instance, param);
                }

                return true;
            };

            base.InitializeAndStart();
            base.StopAndShutdown();

            Assert.IsTrue(instanceDestroyed);
        }

        [UnityTest]
        public IEnumerator XrSpaceApp()
        {
            bool spaceAppSet = false;
            bool spaceAppRemoved = false;
            ulong oldSpaceApp = 0;

            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                // this function checks to see if the initial SetAppSpace call
                // from unity_session.cpp. if you change the default setup in unity_session.cpp
                // you will need to update the value here so that the handle matches.
                // this also makes an assumption that the 3rd space we create is the "Stage"
                // space and that the handles are deterministic.
                if (methodName == nameof(OpenXRFeature.OnAppSpaceChange))
                {
                    spaceAppSet = (oldSpaceApp == 0 && (ulong) param == 3);
                    spaceAppRemoved = (oldSpaceApp == 3 && (ulong) param == 0);
                    oldSpaceApp = (ulong) param;
                }

                return true;
            };

            base.InitializeAndStart();
            yield return null;

            Assert.IsTrue(spaceAppSet);
            Assert.IsFalse(spaceAppRemoved);

            base.StopAndShutdown();
            yield return null;
        }

        [UnityTest]
        public IEnumerator RuntimeName()
        {
            base.InitializeAndStart();
            yield return null;
            Assert.AreEqual(OpenXRRuntime.name, "Unity Mock Runtime");
        }

        [UnityTest]
        public IEnumerator ExtensionCallbackOrder()
        {
            var callbackQueue = new List<string>();
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                // xrSessionStateChanged is called multiple times, we won't validate it here.
                if (methodName != nameof(OpenXRFeature.OnSessionStateChange))
                    callbackQueue.Add(methodName);
                return true;
            };

            base.InitializeAndStart();
            yield return null;
            base.StopAndShutdown();
            yield return null;

            var expectedCallbackOrder = new List<string>()
            {
#if UNITY_EDITOR
                nameof(OpenXRFeature.GetValidationChecks),
#endif
                nameof(OpenXRFeature.HookGetInstanceProcAddr),
                nameof(OpenXRFeature.OnInstanceCreate),
                nameof(OpenXRFeature.OnSystemChange),
                nameof(OpenXRFeature.OnSubsystemCreate),
                nameof(OpenXRFeature.OnSessionCreate),
                nameof(OpenXRFeature.OnSessionBegin),
                nameof(OpenXRFeature.OnFormFactorChange),
                nameof(OpenXRFeature.OnEnvironmentBlendModeChange),
                nameof(OpenXRFeature.OnViewConfigurationTypeChange),
                nameof(OpenXRFeature.OnAppSpaceChange),
                nameof(OpenXRFeature.OnSubsystemStart),
                nameof(OpenXRFeature.OnSubsystemStop),
                nameof(OpenXRFeature.OnSessionEnd),
                nameof(OpenXRFeature.OnSessionExiting),
                nameof(OpenXRFeature.OnSubsystemDestroy),
                nameof(OpenXRFeature.OnSessionDestroy),
                nameof(OpenXRFeature.OnInstanceDestroy)
            };

            Assert.AreEqual(expectedCallbackOrder, callbackQueue);
        }

        [UnityTest]
        public IEnumerator XrSessionStateChanged()
        {
            var states = new List<XrSessionState>();
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                if (methodName == nameof(OpenXRFeature.OnSessionStateChange))
                {
                    var oldState = (XrSessionState) ((MockRuntime.XrSessionStateChangedParams) param).OldState;
                    var newState = (XrSessionState) ((MockRuntime.XrSessionStateChangedParams) param).NewState;
                    CheckValidStateTransition(oldState, newState);
                    states.Add(newState);
                }

                return true;
            };

            Assert.AreEqual(XrSessionState.Unknown, MockRuntime.sessionState);
            base.InitializeAndStart();
            yield return null;
            Assert.AreEqual(XrSessionState.Focused, MockRuntime.sessionState);
            base.StopAndShutdown();
            yield return null;
            Assert.AreEqual(XrSessionState.Unknown, MockRuntime.sessionState);

            var expected = new List<XrSessionState>()
            {
                XrSessionState.Idle,
                XrSessionState.Ready,
                XrSessionState.Synchronized,
                XrSessionState.Visible,
                XrSessionState.Focused,
                XrSessionState.Visible,
                XrSessionState.Synchronized,
                XrSessionState.Stopping,
                XrSessionState.Idle,
                XrSessionState.Exiting,
            };

            Assert.AreEqual(states, expected);
        }

        [UnityTest]
        public IEnumerator EnableSpecExtension()
        {
            AddExtension(MockRuntime.XR_UNITY_mock_test);

            base.InitializeAndStart();

            yield return null;

            Assert.AreEqual(10, MockRuntime.Instance.XrInstance);
        }

        [UnityTest]
        public IEnumerator CheckSpecExtensionVersion()
        {
            AddExtension(MockRuntime.XR_UNITY_mock_test);

            base.InitializeAndStart();

            yield return null;

            Assert.AreEqual(123, OpenXRRuntime.GetExtensionVersion(MockRuntime.XR_UNITY_mock_test));
        }

        [UnityTest]
        public IEnumerator CheckSpecExtensionEnabled()
        {
            MockRuntime.Instance.openxrExtensionStrings = MockRuntime.XR_UNITY_mock_test;

            base.InitializeAndStart();

            yield return null;

            Assert.AreEqual(true, OpenXRRuntime.IsExtensionEnabled(MockRuntime.XR_UNITY_mock_test));
        }

        static OpenXRSettings.DepthSubmissionMode[] depthModes = new OpenXRSettings.DepthSubmissionMode[]
        {
            OpenXRSettings.DepthSubmissionMode.None,
            OpenXRSettings.DepthSubmissionMode.Depth16Bit,
            OpenXRSettings.DepthSubmissionMode.Depth24Bit
        };

        [UnityTest]
        public IEnumerator CheckDepthSubmissionMode([ValueSource("depthModes")] OpenXRSettings.DepthSubmissionMode depthMode)
        {
            base.InitializeAndStart();
            yield return null;
            OpenXRSettings.Instance.depthSubmissionMode = depthMode;
            yield return null;
            Assert.AreEqual(depthMode, OpenXRSettings.Instance.depthSubmissionMode);
        }

        [UnityTest]
        public IEnumerator CheckRenderMode()
        {
            base.InitializeAndStart();

            yield return null;

            OpenXRSettings.Instance.renderMode = OpenXRSettings.RenderMode.SinglePassInstanced;
            yield return null;
            Assert.AreEqual(OpenXRSettings.Instance.renderMode, OpenXRSettings.RenderMode.SinglePassInstanced);

            OpenXRSettings.Instance.renderMode = OpenXRSettings.RenderMode.MultiPass;
            yield return null;
            Assert.AreEqual(OpenXRSettings.Instance.renderMode, OpenXRSettings.RenderMode.MultiPass);
        }

        [UnityTest]
        public IEnumerator CheckSpecExtensionEnabledAtXrInstanceCreated()
        {
            AddExtension(MockRuntime.XR_UNITY_mock_test);

            bool xrCreateInstanceCalled = false;
            bool containsMockExt = false;
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                if (methodName == nameof(OpenXRFeature.OnInstanceCreate))
                {
                    containsMockExt = OpenXRRuntime.IsExtensionEnabled(MockRuntime.XR_UNITY_mock_test);
                    xrCreateInstanceCalled = true;
                }

                return true;
            };

            base.InitializeAndStart();
            yield return null;
            Assert.IsTrue(xrCreateInstanceCalled);
            Assert.IsTrue(containsMockExt);
        }


        [UnityTest]
        public IEnumerator CheckDisplayRestartAfterStopSendRestartEvent()
        {
            // Initialize and make sure the frame loop is running
            InitializeAndStart();
            yield return new WaitForXrFrame();

            // Stop the session and make sure xrEndSession is called
            var endSessionCalled = false;
            MockRuntime.SetFunctionCallback("xrEndSession", (func, result) => endSessionCalled = true);

            Stop();

            Assert.IsTrue(endSessionCalled);

            // Restart the display subsystem which should force a restart
            loader.displaySubsystem.Start();

            // Wait for the restart to finish and then wait for a single Xr Frame, if things restarted
            // properly then the frame loop should be back up and running
            yield return new WaitForLoaderRestart();
            yield return new WaitForXrFrame();
        }

        [UnityTest]
        public IEnumerator SimulatePause ()
        {
            // Initialize and make sure the frame loop is running
            InitializeAndStart();
            yield return new WaitForXrFrame();

            // Pause..
            loader.displaySubsystem.Stop();
            loader.inputSubsystem.Stop();

            yield return null;
            yield return null;

            // Unpause
            loader.displaySubsystem.Start();
            loader.inputSubsystem.Start();

            yield return new WaitForXrFrame();
        }

        void DisableHandInteraction()
        {
            foreach (var ext in OpenXRSettings.Instance.features)
            {
                if (ext.nameUi == "Hand Interaction Profile")
                {
                    ext.enabled = false;
                    return;
                }
            }
        }

        [Category("HMD")]
        [UnityTest]
        public IEnumerator UserPresence()
        {
            List<InputDevice> hmdDevices = new List<InputDevice>();
            InputDevices.GetDevicesWithCharacteristics(InputDeviceCharacteristics.HeadMounted, hmdDevices);
            Assert.That(hmdDevices.Count == 0, Is.True);

            InitializeAndStart();

            // Wait two frames to let the input catch up with the renderer
            yield return new WaitForXrFrame(2);

            InputDevices.GetDevicesWithCharacteristics(InputDeviceCharacteristics.HeadMounted, hmdDevices);
            Assert.That(hmdDevices.Count > 0, Is.True);

            bool hasValue = hmdDevices[0].TryGetFeatureValue(CommonUsages.userPresence, out bool isUserPresent);
            Assert.That(hasValue, Is.True);
            Assert.That(isUserPresent, Is.True);

            MockRuntime.TransitionToState(XrSessionState.Visible, true);

            // State transition doesnt happen immediately so make doubly sure it has happened before we try to get the new feature value
            yield return new WaitForXrFrame(2);

            hasValue = hmdDevices[0].TryGetFeatureValue(CommonUsages.userPresence, out isUserPresent);
            Assert.That(hasValue, Is.True);
            Assert.That(isUserPresent, Is.False);
        }

        [UnityTest]
        public IEnumerator RefreshRate()
        {
            Assert.AreEqual(0.0f, XRDevice.refreshRate);
            base.InitializeAndStart();

            yield return null;
            // TODO: 19.4 has an additional frame of latency until fix is backported.
            yield return null;

            Assert.That(XRDevice.refreshRate, Is.EqualTo(60.0f).Within(0.01f));
        }

        [UnityTest]
        [UnityPlatform(RuntimePlatform.WindowsEditor, RuntimePlatform.WindowsPlayer)]
        public IEnumerator PreInitRealGfxAPI()
        {
            // remove the null gfx device from requested extensions
            MockRuntime.Instance.openxrExtensionStrings = "";

            bool initedRealGfxApi = false;
            MockRuntime.Instance.TestCallback = (s, o) =>
            {
                if (s == nameof(OpenXRFeature.OnInstanceCreate))
                {
                    initedRealGfxApi = new[]
                    {
                        "XR_KHR_D3D11_enable",
                        "XR_KHR_D3D12_enable",
                        "XR_KHR_opengl_enable",
                        "XR_KHR_opengl_es_enable",
                        "XR_KHR_vulkan_enable",
                        "XR_KHR_vulkan_enable2",
                    }.Any(OpenXRRuntime.IsExtensionEnabled);
                }

                return true;
            };

            base.InitializeAndStart();
            yield return null;

            Assert.That(initedRealGfxApi, Is.True);
        }

        [UnityPlatform(exclude = new[] {RuntimePlatform.OSXEditor, RuntimePlatform.OSXPlayer})] // OSX doesn't support single-pass very well, disable for test.
        [UnityTest]
        public IEnumerator CombinedFrustum()
        {
            var cameraGO = new GameObject("Test Cam");
            var camera = cameraGO.AddComponent<Camera>();

            base.InitializeAndStart();
            OpenXRSettings.Instance.renderMode = OpenXRSettings.RenderMode.SinglePassInstanced;

            yield return new WaitForXrFrame(2);

            var displays = new List<XRDisplaySubsystem>();
            SubsystemManager.GetInstances(displays);

            Assert.That(displays.Count, Is.EqualTo(1));

            Assert.That(displays[0].GetRenderPassCount(), Is.EqualTo(1));

            displays[0].GetRenderPass(0, out var renderPass);

            renderPass.GetRenderParameter(camera, 0, out var renderParam0);
            renderPass.GetRenderParameter(camera, 1, out var renderParam1);
            displays[0].GetCullingParameters(camera, renderPass.cullingPassIndex, out var cullingParams);

            // no sense in re-implementing the combining logic here, just the fact they're different shows that we're not using left eye or right eye for culling.
            Assert.That(cullingParams.stereoViewMatrix, Is.Not.EqualTo(renderParam0.view));
            Assert.That(cullingParams.stereoProjectionMatrix, Is.Not.EqualTo(renderParam0.projection));

            Assert.That(cullingParams.stereoViewMatrix, Is.Not.EqualTo(renderParam1.view));
            Assert.That(cullingParams.stereoProjectionMatrix, Is.Not.EqualTo(renderParam0.projection));

            Object.Destroy(cameraGO);
        }

        [UnityTest]
        public IEnumerator InvalidLocateSpace()
        {
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                switch (methodName)
                {
                    case nameof(OpenXRFeature.OnInstanceCreate):
                        // Set the location space to invalid data
                        MockRuntime.SetSpace(XrReferenceSpaceType.View, Vector3.zero, Quaternion.identity, XrSpaceLocationFlags.None);
                        MockRuntime.SetViewState(XrViewConfigurationType.PrimaryStereo, XrViewStateFlags.None);
                        break;
                }

                return true;
            };

            base.InitializeAndStart();

            // Wait a few frames to let the input catch up with the renderer
            yield return new WaitForXrFrame(2);

            MockRuntime.GetEndFrameStats(out var primaryLayerCount, out var secondaryLayerCount);
            Assert.IsTrue(primaryLayerCount == 0);
        }

        [UnityTest]
        public IEnumerator FirstPersonObserver()
        {
            base.InitializeAndStart();

            MockRuntime.ActivateSecondaryView(XrViewConfigurationType.SecondaryMonoFirstPersonObserver, true);

            yield return new WaitForXrFrame(2);

            MockRuntime.GetEndFrameStats(out var primaryLayerCount, out var secondaryLayerCount);
            Assert.IsTrue(secondaryLayerCount == 1);

            MockRuntime.ActivateSecondaryView(XrViewConfigurationType.SecondaryMonoFirstPersonObserver, false);

            yield return new WaitForXrFrame(2);

            MockRuntime.GetEndFrameStats(out primaryLayerCount, out secondaryLayerCount);
            Assert.IsTrue(secondaryLayerCount == 0);
        }

        [UnityTest]
        public IEnumerator FirstPersonObserverRestartWhileActive()
        {
            base.InitializeAndStart();

            MockRuntime.ActivateSecondaryView(XrViewConfigurationType.SecondaryMonoFirstPersonObserver, true);
            yield return new WaitForXrFrame(1);

            MockRuntime.GetEndFrameStats(out var primaryLayerCount, out var secondaryLayerCount);
            Assert.IsTrue(secondaryLayerCount == 1);

            // Transition to ready, which was causing a crash.
            MockRuntime.TransitionToState(XrSessionState.Visible, false);
            yield return null;
            MockRuntime.TransitionToState(XrSessionState.Synchronized, false);
            yield return null;
            MockRuntime.TransitionToState(XrSessionState.Stopping, false);
            yield return null;
            MockRuntime.TransitionToState(XrSessionState.Idle, false);
            yield return null;
            MockRuntime.TransitionToState(XrSessionState.Ready, false);
            yield return null;

            // Check that secondary layer is still there
            MockRuntime.GetEndFrameStats(out primaryLayerCount, out secondaryLayerCount);
            Assert.IsTrue(secondaryLayerCount == 1);

            // Transition back to focused
            MockRuntime.TransitionToState(XrSessionState.Synchronized, false);
            yield return null;
            MockRuntime.TransitionToState(XrSessionState.Visible, false);
            yield return null;
            MockRuntime.TransitionToState(XrSessionState.Focused, false);
            yield return null;

            yield return new WaitForXrFrame(2);

            // Verify secondary layer is still up and running
            MockRuntime.GetEndFrameStats(out primaryLayerCount, out secondaryLayerCount);
            Assert.IsTrue(secondaryLayerCount == 1);

            // Make sure we can turn it off
            MockRuntime.ActivateSecondaryView(XrViewConfigurationType.SecondaryMonoFirstPersonObserver, false);
            yield return new WaitForXrFrame(2);

            MockRuntime.GetEndFrameStats(out primaryLayerCount, out secondaryLayerCount);
            Assert.IsTrue(secondaryLayerCount == 0);
        }

        [UnityTest]
        public IEnumerator NullFeature()
        {
            // Insert a null entry into the features list
            var features = OpenXRSettings.Instance.features.ToList();
            features.Insert(1, null);
            OpenXRSettings.Instance.features = features.ToArray();

            base.InitializeAndStart();

            // Wait two frames to make sure nothing else shakes out
            yield return null;
            yield return null;

            base.StopAndShutdown();
        }

        /// <summary>
        /// Tests whether or not the Initialize method of OpenXRLoader will properly handle an exception being thrown
        /// </summary>
        [Test]
        public void InitializeException()
        {
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                switch (methodName)
                {
                    case nameof(OpenXRFeature.HookGetInstanceProcAddr):
                        throw new Exception("Testing exception within Initialize");
                }

                return true;
            };

            LogAssert.ignoreFailingMessages = true;
            base.InitializeAndStart();
            LogAssert.ignoreFailingMessages = false;

            // The static instance should not be set if initialize failed
            Assert.IsTrue(OpenXRLoaderBase.Instance == null);
        }

        [UnityTest]
        public IEnumerator WantsToRestartTrue ()
        {
            OpenXRRuntime.wantsToRestart += () => true;
            OpenXRRuntime.wantsToRestart += () => true;
            OpenXRRuntime.wantsToRestart += () => true;

            InitializeAndStart();

            yield return new WaitForXrFrame(2);

            MockRuntime.TransitionToState(XrSessionState.LossPending, true);

            yield return new WaitForLoaderRestart();
            yield return new WaitForXrFrame(1);
        }

        [UnityTest]
        public IEnumerator WantsToRestartFalse()
        {
            OpenXRRuntime.wantsToRestart += () => true;
            OpenXRRuntime.wantsToRestart += () => false;
            OpenXRRuntime.wantsToRestart += () => true;

            InitializeAndStart();
            yield return new WaitForXrFrame(2);

            MockRuntime.TransitionToState(XrSessionState.LossPending, true);

            yield return new WaitForLoaderShutdown();
        }

        [UnityTest]
        public IEnumerator WantsToQuitTrue ()
        {
            var onQuit = false;
            OpenXRRuntime.wantsToQuit += () => true;
            OpenXRRuntime.wantsToQuit += () => true;
            OpenXRRuntime.wantsToQuit += () => true;
            OpenXRRestarter.Instance.onQuit += () => onQuit = true;

            InitializeAndStart();
            yield return new WaitForXrFrame(2);

            MockRuntime.CauseInstanceLoss();

            yield return new WaitForLoaderShutdown();

            Assert.IsTrue(OpenXRLoader.Instance == null, "OpenXR should not be running");
            Assert.IsTrue(onQuit, "Quit was not called");
        }

        [UnityTest]
        public IEnumerator WantsToQuitFalse ()
        {
            var onQuit = false;
            OpenXRRuntime.wantsToQuit += () => true;
            OpenXRRuntime.wantsToQuit += () => false;
            OpenXRRuntime.wantsToQuit += () => true;
            OpenXRRestarter.Instance.onQuit += () => onQuit = true;

            InitializeAndStart();
            yield return new WaitForXrFrame(2);

            MockRuntime.CauseInstanceLoss();

            yield return new WaitForLoaderShutdown();

            Assert.IsTrue(OpenXRLoader.Instance == null, "OpenXR should not be running");
            Assert.IsFalse (onQuit, "Quit was not called");
        }

        [UnityTest]
        public IEnumerator LossPendingCausesRestart ()
        {
            bool lossPendingReceived = false;
            MockRuntime.Instance.TestCallback = (methodName, param) =>
            {
                switch (methodName)
                {
                    case nameof(OpenXRFeature.OnSessionLossPending):
                        lossPendingReceived = true;
                        break;
                }

                return true;
            };

            InitializeAndStart();

            yield return new WaitForXrFrame(1);

            Assert.IsTrue(MockRuntime.TransitionToState(XrSessionState.LossPending, true), "Failed to transition to loss pending state");

            yield return new WaitForLoaderRestart();

            Assert.IsTrue(lossPendingReceived);
        }

        [UnityTest]
        public IEnumerator CreateSwapChainRuntimeError()
        {
            MockRuntime.SetFunctionCallback("xrCreateSwapchain", (func) => XrResult.RuntimeFailure);

            InitializeAndStart();

            yield return new WaitForLoaderShutdown();

            Assert.IsTrue(OpenXRLoader.Instance == null, "OpenXR should not be initialized");
        }

        [UnityTest]
        public IEnumerator CreateSessionRuntimeError ()
        {
            MockRuntime.SetFunctionCallback("xrCreateSession", (func) => XrResult.RuntimeFailure);

            InitializeAndStart();

            yield return null;

            Assert.IsTrue(DoesDiagnosticReportContain(new System.Text.RegularExpressions.Regex(@"xrCreateSession: XR_ERROR_RUNTIME_FAILURE")));
            Assert.IsTrue(OpenXRLoader.Instance.currentLoaderState == OpenXRLoaderBase.LoaderState.Stopped, "OpenXR should be stopped");
        }

        [UnityTest]
        public IEnumerator MultipleRestart()
        {
            InitializeAndStart();
            yield return new WaitForXrFrame();

            OpenXRRestarter.Instance.ShutdownAndRestart();
            yield return new WaitForXrFrame();

            OpenXRRestarter.Instance.ShutdownAndRestart();
            yield return new WaitForXrFrame();
        }
    }
}
