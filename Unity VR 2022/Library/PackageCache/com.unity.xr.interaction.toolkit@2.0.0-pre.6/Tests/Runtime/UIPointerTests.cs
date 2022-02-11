using System.Collections;
using System.Collections.Generic;
using NUnit.Framework;
using UnityEngine.EventSystems;
using UnityEngine.TestTools;
using UnityEngine.UI;
using UnityEngine.XR.Interaction.Toolkit.UI;
using Unity.XR.CoreUtils;

namespace UnityEngine.XR.Interaction.Toolkit.Tests
{
    static class XRControllerRecorderExtensions
    {
        internal static void SetNextPose(this XRControllerRecorder recorder, Vector3 position, Quaternion rotation, bool selectActive, bool activateActive, bool pressActive)
        {
            XRControllerRecording currentRecording = recorder.recording;
            currentRecording.InitRecording();
            currentRecording.AddRecordingFrameNonAlloc(new XRControllerState(0.0f, position, rotation, InputTrackingState.All, selectActive, activateActive, pressActive));
            currentRecording.AddRecordingFrameNonAlloc(new XRControllerState(1000f, position, rotation, InputTrackingState.All, selectActive, activateActive, pressActive));
            recorder.recording = currentRecording;
            recorder.ResetPlayback();
            recorder.isPlaying = true;
        }
    }

    [TestFixture]
    class UIPointerTests
    {
        internal enum EventType
        {
            Click,
            Down,
            Up,
            Enter,
            Exit,
            Select,
            Deselect,
            PotentialDrag,
            BeginDrag,
            Dragging,
            Drop,
            EndDrag,
            Move,
            Submit,
            Cancel,
            Scroll,
            UpdateSelected,
        }

        struct TestObjects
        {
            public Camera camera;
            public TestEventSystem eventSystem;
            public XRControllerRecorder controllerRecorder;
            public XRRayInteractor interactor;
            public UICallbackReceiver leftUIReceiver;
            public UICallbackReceiver rightUIReceiver;
            public GlobalUIReceiver globalUIReceiver;
        }

        internal struct Event
        {
            public EventType type;
            public BaseEventData data;
            public GameObject target;

            public Event(EventType type, BaseEventData data, GameObject target = null)
            {
                this.type = type;
                this.data = data;
                this.target = target;
            }

            public override string ToString()
            {
                var dataString = data.ToString();
                dataString = dataString.Replace("\n", "\n\t");
                return $"{type} - {target}[\n\t{dataString}]";
            }
        }

        static BaseEventData CloneEventData(BaseEventData eventData)
            {
                switch (eventData)
                {
                    case AxisEventData axisEventData:
                        return new AxisEventData(EventSystem.current)
                        {
                            moveVector = axisEventData.moveVector,
                            moveDir = axisEventData.moveDir,
                        };
                    case TrackedDeviceEventData trackedEventData:
                        return new TrackedDeviceEventData(EventSystem.current)
                        {
                            pointerId = trackedEventData.pointerId,
                            position = trackedEventData.position,
                            button = trackedEventData.button,
                            clickCount = trackedEventData.clickCount,
                            clickTime = trackedEventData.clickTime,
                            eligibleForClick = trackedEventData.eligibleForClick,
                            delta = trackedEventData.delta,
                            scrollDelta = trackedEventData.scrollDelta,
                            dragging = trackedEventData.dragging,
                            hovered = new List<GameObject>(trackedEventData.hovered),
                            pointerDrag = trackedEventData.pointerDrag,
                            pointerEnter = trackedEventData.pointerEnter,
                            pointerPress = trackedEventData.pointerPress,
                            pressPosition = trackedEventData.pressPosition,
                            pointerCurrentRaycast = trackedEventData.pointerCurrentRaycast,
                            pointerPressRaycast = trackedEventData.pointerPressRaycast,
                            rawPointerPress = trackedEventData.rawPointerPress,
                            useDragThreshold = trackedEventData.useDragThreshold,

                            layerMask = trackedEventData.layerMask,
                            rayHitIndex = trackedEventData.rayHitIndex,
                            rayPoints = new List<Vector3>(trackedEventData.rayPoints),
                        };
                    case PointerEventData pointerEventData:
                        return new PointerEventData(EventSystem.current)
                        {
                            pointerId = pointerEventData.pointerId,
                            position = pointerEventData.position,
                            button = pointerEventData.button,
                            clickCount = pointerEventData.clickCount,
                            clickTime = pointerEventData.clickTime,
                            eligibleForClick = pointerEventData.eligibleForClick,
                            delta = pointerEventData.delta,
                            scrollDelta = pointerEventData.scrollDelta,
                            dragging = pointerEventData.dragging,
                            hovered = new List<GameObject>(pointerEventData.hovered),
                            pointerDrag = pointerEventData.pointerDrag,
                            pointerEnter = pointerEventData.pointerEnter,
                            pointerPress = pointerEventData.pointerPress,
                            pressPosition = pointerEventData.pressPosition,
                            pointerCurrentRaycast = pointerEventData.pointerCurrentRaycast,
                            pointerPressRaycast = pointerEventData.pointerPressRaycast,
                            rawPointerPress = pointerEventData.rawPointerPress,
                            useDragThreshold = pointerEventData.useDragThreshold,
                        };
                    default:
                        return new BaseEventData(EventSystem.current);
                }
            }

        internal class UICallbackReceiver : MonoBehaviour, IPointerClickHandler, IPointerDownHandler, IPointerEnterHandler,
            IPointerExitHandler, IPointerUpHandler, IMoveHandler, ISelectHandler, IDeselectHandler, IInitializePotentialDragHandler,
            IBeginDragHandler, IDragHandler, IEndDragHandler, IDropHandler, ISubmitHandler, ICancelHandler, IScrollHandler
        {
            public List<Event> events = new List<Event>();

            public void Reset()
            {
                events.Clear();
            }

            public void OnPointerClick(PointerEventData eventData)
            {
                events.Add(new Event(EventType.Click, CloneEventData(eventData)));
            }

            public void OnPointerDown(PointerEventData eventData)
            {
                events.Add(new Event(EventType.Down, CloneEventData(eventData)));
            }

            public void OnPointerEnter(PointerEventData eventData)
            {
                events.Add(new Event(EventType.Enter, CloneEventData(eventData)));
            }

            public void OnPointerExit(PointerEventData eventData)
            {
                events.Add(new Event(EventType.Exit, CloneEventData(eventData)));
            }

            public void OnPointerUp(PointerEventData eventData)
            {
                events.Add(new Event(EventType.Up, CloneEventData(eventData)));
            }

            public void OnMove(AxisEventData eventData)
            {
                events.Add(new Event(EventType.Move, CloneEventData(eventData)));
            }

            public void OnSubmit(BaseEventData eventData)
            {
                events.Add(new Event(EventType.Submit, CloneEventData(eventData)));
            }

            public void OnCancel(BaseEventData eventData)
            {
                events.Add(new Event(EventType.Cancel, CloneEventData(eventData)));
            }

            public void OnSelect(BaseEventData eventData)
            {
                events.Add(new Event(EventType.Select, CloneEventData(eventData)));
            }

            public void OnDeselect(BaseEventData eventData)
            {
                events.Add(new Event(EventType.Deselect, CloneEventData(eventData)));
            }

            public void OnInitializePotentialDrag(PointerEventData eventData)
            {
                events.Add(new Event(EventType.PotentialDrag, CloneEventData(eventData)));
            }

            public void OnBeginDrag(PointerEventData eventData)
            {
                events.Add(new Event(EventType.BeginDrag, CloneEventData(eventData)));
            }

            public void OnDrag(PointerEventData eventData)
            {
                events.Add(new Event(EventType.Dragging, CloneEventData(eventData)));
            }

            public void OnDrop(PointerEventData eventData)
            {
                events.Add(new Event(EventType.Drop, CloneEventData(eventData)));
            }

            public void OnEndDrag(PointerEventData eventData)
            {
                events.Add(new Event(EventType.EndDrag, CloneEventData(eventData)));
            }

            public void OnScroll(PointerEventData eventData)
            {
                events.Add(new Event(EventType.Scroll, CloneEventData(eventData)));
            }
        }

        class GlobalUIReceiver
        {
            public List<Event> events = new List<Event>();

            public GlobalUIReceiver(UIInputModule module)
            {
                // We never unsubscribe these events--Always ensure only one GlobalUIReciever is associated with one UIInputModule
                module.pointerEnter += OnPointerEnter;
                module.pointerExit += OnPointerExit;
                module.pointerDown += OnPointerDown;
                module.pointerUp += OnPointerUp;
                module.pointerClick += OnPointerClick;
                module.initializePotentialDrag += OnInitializePotentialDrag;
                module.beginDrag += OnBeginDrag;
                module.drag += OnDrag;
                module.endDrag += OnEndDrag;
                module.drop += OnDrop;
                module.scroll += OnScroll;
                module.updateSelected += OnUpdateSelected;
                module.move += OnMove;
                module.submit += OnSubmit;
                module.cancel += OnCancel;
            }

            public void Reset()
            {
                events.Clear();
            }

            void OnPointerEnter(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Enter, CloneEventData(eventData), target));
            }

            void OnPointerExit(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Exit, CloneEventData(eventData), target));
            }

            void OnPointerDown(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Down, CloneEventData(eventData), target));
            }

            void OnPointerUp(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Up, CloneEventData(eventData), target));
            }

            void OnPointerClick(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Click, CloneEventData(eventData), target));
            }

            void OnInitializePotentialDrag(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.PotentialDrag, CloneEventData(eventData), target));
            }

            void OnBeginDrag(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.BeginDrag, CloneEventData(eventData), target));
            }

            void OnDrag(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Dragging, CloneEventData(eventData), target));
            }

            void OnEndDrag(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.EndDrag, CloneEventData(eventData), target));
            }

            void OnDrop(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Drop, CloneEventData(eventData), target));
            }

            void OnScroll(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Scroll, CloneEventData(eventData), target));
            }

            void OnUpdateSelected(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.UpdateSelected, CloneEventData(eventData), target));
            }

            void OnMove(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Move, CloneEventData(eventData), target));
            }

            void OnSubmit(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Submit, CloneEventData(eventData), target));
            }

            void OnCancel(GameObject target, BaseEventData eventData)
            {
                events.Add(new Event(EventType.Cancel, CloneEventData(eventData), target));
            }
        }

        internal class TestEventSystem : EventSystem
        {
            public void InvokeUpdate()
            {
                current = this; // Needs to be current to be allowed to update.
                Update();
            }
        }

        static TestObjects SetupRig()
        {
            var testObjects = new TestObjects();

            _ = new GameObject("InteractionManager", typeof(XRInteractionManager));

            var rigGo = new GameObject("XROrigin");
            rigGo.SetActive(false);
            var rig = rigGo.AddComponent<XROrigin>();

            // Add camera offset
            var cameraOffsetGo = new GameObject();
            cameraOffsetGo.name = "CameraOffset";
            cameraOffsetGo.transform.SetParent(rig.transform,false);
            rig.CameraFloorOffsetObject = cameraOffsetGo;

            // Set up camera and canvas on which we can perform raycasts.
            var cameraGo = new GameObject("Camera");
            cameraGo.transform.parent = rigGo.transform;
            Camera camera = testObjects.camera = cameraGo.AddComponent<Camera>();
            camera.stereoTargetEye = StereoTargetEyeMask.None;
            camera.pixelRect = new Rect(0, 0, 640, 480);

            rig.Camera = cameraGo.GetComponent<Camera>();
            rigGo.SetActive(true);

            var eventSystemGo = new GameObject("EventSystem", typeof(TestEventSystem), typeof(XRUIInputModule));
            var inputModule = eventSystemGo.GetComponent<XRUIInputModule>();
            inputModule.uiCamera = camera;
            inputModule.enableXRInput = true;
            inputModule.enableMouseInput = false;
            inputModule.enableTouchInput = false;
            testObjects.eventSystem = eventSystemGo.GetComponent<TestEventSystem>();
            testObjects.eventSystem.UpdateModules();
            testObjects.eventSystem.InvokeUpdate(); // Initial update only sets current module.

            testObjects.globalUIReceiver = new GlobalUIReceiver(inputModule);

            var interactorGo = new GameObject("Interactor", typeof(XRController), typeof(XRRayInteractor), typeof(XRControllerRecorder));
            interactorGo.transform.parent = rigGo.transform;
            testObjects.controllerRecorder = interactorGo.GetComponent<XRControllerRecorder>();
            testObjects.controllerRecorder.recording = ScriptableObject.CreateInstance<XRControllerRecording>();
            testObjects.interactor = interactorGo.GetComponent<XRRayInteractor>();
            testObjects.interactor.maxRaycastDistance = int.MaxValue;
            testObjects.interactor.referenceFrame = rigGo.transform;

            return testObjects;
        }

        static TestObjects SetupUIScene()
        {
            var testObjects = SetupRig();

            var canvasGo = new GameObject("Canvas", typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster), typeof(TrackedDeviceGraphicRaycaster));
            var canvas = canvasGo.GetComponent<Canvas>();
            canvas.worldCamera = testObjects.camera;
            canvas.renderMode = RenderMode.ScreenSpaceCamera;

            // Set up a GameObject hierarchy that we send events to. In a real setup,
            // this would be a hierarchy involving UI components.
            var parentGameObject = new GameObject("Parent");
            var parentTransform = parentGameObject.AddComponent<RectTransform>();
            parentGameObject.AddComponent<UICallbackReceiver>();

            var leftChildGameObject = new GameObject("Left Child");
            var leftChildTransform = leftChildGameObject.AddComponent<RectTransform>();
            leftChildGameObject.AddComponent<Image>();
            testObjects.leftUIReceiver = leftChildGameObject.AddComponent<UICallbackReceiver>();

            var rightChildGameObject = new GameObject("Right Child");
            var rightChildTransform = rightChildGameObject.AddComponent<RectTransform>();
            rightChildGameObject.AddComponent<Image>();
            testObjects.rightUIReceiver = rightChildGameObject.AddComponent<UICallbackReceiver>();

            parentTransform.SetParent(canvas.transform, false);
            leftChildTransform.SetParent(parentTransform, false);
            rightChildTransform.SetParent(parentTransform, false);

            // Parent occupies full space of canvas.
            parentTransform.sizeDelta = new Vector2(640, 480);

            // Left child occupies left half of parent.
            const int quarterSize = 640 / 4;
            leftChildTransform.anchoredPosition = new Vector2(-quarterSize, 0);
            leftChildTransform.sizeDelta = new Vector2(320, 480);

            // Right child occupies right half of parent.
            rightChildTransform.anchoredPosition = new Vector2(quarterSize, 0);
            rightChildTransform.sizeDelta = new Vector2(320, 480);

            return testObjects;
        }

        static TestObjects SetupPhysicsScene()
        {
            var testObjects = SetupRig();

            var physicsRaycaster = new GameObject("PhysicsRaycaster", typeof(TrackedDevicePhysicsRaycaster)).GetComponent<TrackedDevicePhysicsRaycaster>();
            physicsRaycaster.SetEventCamera(testObjects.camera);

            var parentGameObject = new GameObject("Interactables");
            var parentTransform = parentGameObject.transform;

            var groupGameObject = new GameObject("Group");
            var groupTransform = groupGameObject.transform;
            groupGameObject.AddComponent<UICallbackReceiver>();

            var leftGameObject = GameObject.CreatePrimitive(PrimitiveType.Cube);
            testObjects.leftUIReceiver = leftGameObject.AddComponent<UICallbackReceiver>();
            var leftTransform = leftGameObject.transform;
            leftTransform.position = new Vector3(-0.5f, 0.0f, 1.75f);
            var rightGameObject = GameObject.CreatePrimitive(PrimitiveType.Cube);
            testObjects.rightUIReceiver = rightGameObject.AddComponent<UICallbackReceiver>();
            var rightTransform = rightGameObject.transform;
            rightTransform.position = new Vector3(0.5f, 0.0f, 1.75f);

            groupGameObject.transform.SetParent(parentTransform, false);
            leftGameObject.transform.SetParent(groupTransform, false);
            rightGameObject.transform.SetParent(groupTransform, false);

            return testObjects;
        }

        static IEnumerator CheckEvents(TestObjects testObjects)
        {
            var leftUIReceiver = testObjects.leftUIReceiver;
            var rightUIReceiver = testObjects.rightUIReceiver;
            var globalUIReceiver = testObjects.globalUIReceiver;

            var recorder = testObjects.controllerRecorder;

            // Reset to Defaults
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -90.0f, 0.0f), false, false, false);
            yield return new WaitForFixedUpdate();
            yield return null;

            leftUIReceiver.Reset();
            rightUIReceiver.Reset();
            globalUIReceiver.Reset();

            // Move over left child.
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -30.0f, 0.0f), false, false, false);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(1));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Enter));
            Assert.That(leftUIReceiver.events[0].data, Is.TypeOf<TrackedDeviceEventData>());

            var globalEvents = globalUIReceiver.events;
            var leftUIReceiverParentTransform = leftUIReceiver.transform.parent;
            Assert.That(globalEvents, Has.Count.EqualTo(3));
            Assert.That(globalEvents[0].type, Is.EqualTo(EventType.Enter));
            Assert.That(globalEvents[0].data, Is.TypeOf<TrackedDeviceEventData>());
            Assert.That(globalEvents[0].target, Is.EqualTo(leftUIReceiver.gameObject));
            Assert.That(globalEvents[1].target, Is.EqualTo(leftUIReceiverParentTransform.gameObject));
            Assert.That(globalEvents[2].target, Is.EqualTo(leftUIReceiverParentTransform.parent.gameObject));

            var eventData = (TrackedDeviceEventData)leftUIReceiver.events[0].data;
            Assert.That(eventData.interactor, Is.EqualTo(testObjects.interactor));
            leftUIReceiver.Reset();
            globalUIReceiver.Reset();

            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(0));

            // Check basic down/up
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -30.0f, 0.0f), false, false, true);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Down));
            Assert.That(leftUIReceiver.events[1].type, Is.EqualTo(EventType.PotentialDrag));
            leftUIReceiver.Reset();
            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(0));

            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(globalUIReceiver.events[0].type, Is.EqualTo(EventType.Down));
            Assert.That(globalUIReceiver.events[1].type, Is.EqualTo(EventType.PotentialDrag));
            globalUIReceiver.Reset();
            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(0));

            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -30.0f, 0.0f), false, false, false);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Up));
            Assert.That(leftUIReceiver.events[1].type, Is.EqualTo(EventType.Click));
            leftUIReceiver.Reset();
            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(0));

            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(globalUIReceiver.events[0].type, Is.EqualTo(EventType.Up));
            Assert.That(globalUIReceiver.events[1].type, Is.EqualTo(EventType.Click));
            globalUIReceiver.Reset();
            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(0));
            
            // Check down, off, back on, and up
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -30.0f, 0.0f), false, false, true);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Down));
            Assert.That(leftUIReceiver.events[1].type, Is.EqualTo(EventType.PotentialDrag));
            leftUIReceiver.Reset();
            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(0));

            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(globalUIReceiver.events[0].type, Is.EqualTo(EventType.Down));
            Assert.That(globalUIReceiver.events[1].type, Is.EqualTo(EventType.PotentialDrag));
            globalUIReceiver.Reset();
            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(0));

            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, 30.0f, 0.0f), false, false, true);
            yield return null;
            
            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(3));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Exit));
            Assert.That(leftUIReceiver.events[1].type, Is.EqualTo(EventType.BeginDrag));
            Assert.That(leftUIReceiver.events[2].type, Is.EqualTo(EventType.Dragging));
            leftUIReceiver.Reset();
            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(0));
            
            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(1));
            Assert.That(rightUIReceiver.events[0].type, Is.EqualTo(EventType.Enter));
            rightUIReceiver.Reset();
            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(0));

            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(4));
            Assert.That(globalUIReceiver.events[0].type, Is.EqualTo(EventType.Exit));
            Assert.That(globalUIReceiver.events[1].type, Is.EqualTo(EventType.Enter));
            Assert.That(globalUIReceiver.events[2].type, Is.EqualTo(EventType.BeginDrag));
            Assert.That(globalUIReceiver.events[3].type, Is.EqualTo(EventType.Dragging));
            globalUIReceiver.Reset();
            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(0));

            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -30.0f, 0.0f), false, false, false);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(4));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Up));
            Assert.That(leftUIReceiver.events[1].type, Is.EqualTo(EventType.Click));
            Assert.That(leftUIReceiver.events[2].type, Is.EqualTo(EventType.EndDrag));
            Assert.That(leftUIReceiver.events[3].type, Is.EqualTo(EventType.Enter));
            leftUIReceiver.Reset();
            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(0));

            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(1));
            Assert.That(rightUIReceiver.events[0].type, Is.EqualTo(EventType.Exit));
            rightUIReceiver.Reset();
            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(0));

            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(5));
            Assert.That(globalUIReceiver.events[0].type, Is.EqualTo(EventType.Up));
            Assert.That(globalUIReceiver.events[1].type, Is.EqualTo(EventType.Click));
            Assert.That(globalUIReceiver.events[2].type, Is.EqualTo(EventType.EndDrag));
            Assert.That(globalUIReceiver.events[3].type, Is.EqualTo(EventType.Exit));
            Assert.That(globalUIReceiver.events[4].type, Is.EqualTo(EventType.Enter));
            globalUIReceiver.Reset();
            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(0));

            // Check down and drag
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -30.0f, 0.0f), false, false, true);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Down));
            Assert.That(leftUIReceiver.events[1].type, Is.EqualTo(EventType.PotentialDrag));
            leftUIReceiver.Reset();
            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(0));

            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(globalUIReceiver.events[0].type, Is.EqualTo(EventType.Down));
            Assert.That(globalUIReceiver.events[1].type, Is.EqualTo(EventType.PotentialDrag));
            globalUIReceiver.Reset();
            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(0));

            // Move to new location on left child
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -10.0f, 0.0f), false, false, true);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.BeginDrag));
            Assert.That(leftUIReceiver.events[1].type, Is.EqualTo(EventType.Dragging));
            leftUIReceiver.Reset();
            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(0));

            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(globalUIReceiver.events[0].type, Is.EqualTo(EventType.BeginDrag));
            Assert.That(globalUIReceiver.events[1].type, Is.EqualTo(EventType.Dragging));
            globalUIReceiver.Reset();
            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(0));

            // Move children
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, 30.0f, 0.0f), false, false, true);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Exit));
            Assert.That(leftUIReceiver.events[1].type, Is.EqualTo(EventType.Dragging));
            leftUIReceiver.Reset();
            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(1));
            Assert.That(rightUIReceiver.events[0].type, Is.EqualTo(EventType.Enter));
            rightUIReceiver.Reset();

            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(3));
            Assert.That(globalUIReceiver.events[0].type, Is.EqualTo(EventType.Exit));
            Assert.That(globalUIReceiver.events[1].type, Is.EqualTo(EventType.Enter));
            Assert.That(globalUIReceiver.events[2].type, Is.EqualTo(EventType.Dragging));
            globalUIReceiver.Reset();

            // Deselect
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, 30.0f, 0.0f), false, false, false);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(2));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Up));
            Assert.That(leftUIReceiver.events[1].type, Is.EqualTo(EventType.EndDrag));
            leftUIReceiver.Reset();
            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(1));
            Assert.That(rightUIReceiver.events[0].type, Is.EqualTo(EventType.Drop));
            rightUIReceiver.Reset();

            Assert.That(globalUIReceiver.events, Has.Count.EqualTo(3));
            Assert.That(globalUIReceiver.events[0].type, Is.EqualTo(EventType.Up));
            Assert.That(globalUIReceiver.events[1].type, Is.EqualTo(EventType.Drop));
            Assert.That(globalUIReceiver.events[2].type, Is.EqualTo(EventType.EndDrag));
            globalUIReceiver.Reset();
        }

        [UnityTest]
        public IEnumerator TrackedDevicesCanDriveUIGraphics()
        {
            TestObjects testObjects = SetupUIScene();

            yield return CheckEvents(testObjects);

            // This suppresses a warning that would be logged by TrackedDeviceGraphicRaycaster if the Camera is destroyed first
            Object.Destroy(testObjects.eventSystem.gameObject);
        }

        [UnityTest]
        public IEnumerator TrackedDevicesCanDriveUIPhysics()
        {
            var testObjects = SetupPhysicsScene();

            yield return CheckEvents(testObjects);

            // This suppresses a warning that would be logged by TrackedDeviceGraphicRaycaster if the Camera is destroyed first
            Object.Destroy(testObjects.eventSystem.gameObject);
        }

        [UnityTest]
        public IEnumerator PointerEnterBubblesUp()
        {
            var testObjects = SetupPhysicsScene();

            var leftUIReceiver = testObjects.leftUIReceiver;
            var rightUIReceiver = testObjects.rightUIReceiver;
            var globalUIReceiver = testObjects.globalUIReceiver;

            // Have the event receiver on a parent of the Collider child
            // to test that pointer enter events are bubbled up to parent objects
            // even when the hit GameObject does not have any event handlers itself.
            Object.Destroy(leftUIReceiver.GetComponent<Collider>());
            var leftUIColliderGameObject = new GameObject("Collider", typeof(BoxCollider));
            leftUIColliderGameObject.transform.SetParent(leftUIReceiver.transform, false);

            var recorder = testObjects.controllerRecorder;

            // Reset to Defaults
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -90.0f, 0.0f), false, false, false);
            yield return new WaitForFixedUpdate();
            yield return null;

            leftUIReceiver.Reset();
            rightUIReceiver.Reset();
            globalUIReceiver.Reset();

            // Move over left child.
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -30.0f, 0.0f), false, false, false);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(1));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Enter));
            Assert.That(leftUIReceiver.events[0].data, Is.TypeOf<TrackedDeviceEventData>());

            var globalEvents = globalUIReceiver.events;
            var leftUIReceiverParentTransform = leftUIReceiver.transform.parent;
            Assert.That(globalEvents, Has.Count.EqualTo(4));
            Assert.That(globalEvents[0].type, Is.EqualTo(EventType.Enter));
            Assert.That(globalEvents[0].data, Is.TypeOf<TrackedDeviceEventData>());
            Assert.That(globalEvents[0].target, Is.EqualTo(leftUIColliderGameObject));
            Assert.That(globalEvents[1].target, Is.EqualTo(leftUIReceiver.gameObject));
            Assert.That(globalEvents[2].target, Is.EqualTo(leftUIReceiverParentTransform.gameObject));
            Assert.That(globalEvents[3].target, Is.EqualTo(leftUIReceiverParentTransform.parent.gameObject));

            var eventData = (TrackedDeviceEventData)leftUIReceiver.events[0].data;
            Assert.That(eventData.interactor, Is.EqualTo(testObjects.interactor));
            leftUIReceiver.Reset();
            globalUIReceiver.Reset();

            Assert.That(rightUIReceiver.events, Has.Count.EqualTo(0));

            // Move off left child.
            recorder.SetNextPose(Vector3.zero, Quaternion.Euler(0.0f, -90.0f, 0.0f), false, false, false);
            yield return null;

            Assert.That(leftUIReceiver.events, Has.Count.EqualTo(1));
            Assert.That(leftUIReceiver.events[0].type, Is.EqualTo(EventType.Exit));
            Assert.That(leftUIReceiver.events[0].data, Is.TypeOf<TrackedDeviceEventData>());

            Assert.That(globalEvents, Has.Count.EqualTo(4));
            Assert.That(globalEvents[0].type, Is.EqualTo(EventType.Exit));
            Assert.That(globalEvents[0].data, Is.TypeOf<TrackedDeviceEventData>());
            Assert.That(globalEvents[0].target, Is.EqualTo(leftUIColliderGameObject));
            Assert.That(globalEvents[1].target, Is.EqualTo(leftUIReceiver.gameObject));
            Assert.That(globalEvents[2].target, Is.EqualTo(leftUIReceiverParentTransform.gameObject));
            Assert.That(globalEvents[3].target, Is.EqualTo(leftUIReceiverParentTransform.parent.gameObject));

            // This suppresses a warning that would be logged by TrackedDeviceGraphicRaycaster if the Camera is destroyed first
            Object.Destroy(testObjects.eventSystem.gameObject);
        }

        [TearDown]
        public void TearDown()
        {
            TestUtilities.DestroyAllSceneObjects();
        }
    }
}
