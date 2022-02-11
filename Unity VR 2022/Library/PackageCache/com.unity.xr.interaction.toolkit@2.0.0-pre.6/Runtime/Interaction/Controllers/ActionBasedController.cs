using UnityEngine.InputSystem;
using UnityEngine.InputSystem.Controls;
using UnityEngine.InputSystem.XR;
using UnityEngine.XR.Interaction.Toolkit.Inputs;

namespace UnityEngine.XR.Interaction.Toolkit
{
    /// <summary>
    /// Interprets feature values on a tracked input controller device using actions from the Input System
    /// into XR Interaction states, such as Select. Additionally, it applies the current Pose value
    /// of a tracked device to the transform of the GameObject.
    /// </summary>
    /// <remarks>
    /// This behavior requires that the Input System is enabled in the <b>Active Input Handling</b>
    /// setting in <b>Edit &gt; Project Settings &gt; Player</b> for input values to be read.
    /// Each input action must also be enabled to read the current value of the action. Referenced
    /// input actions in an Input Action Asset are not enabled by default.
    /// </remarks>
    /// <seealso cref="XRBaseController"/>
    [AddComponentMenu("XR/XR Controller (Action-based)")]
    [HelpURL(XRHelpURLConstants.k_ActionBasedController)]
    public partial class ActionBasedController : XRBaseController
    {
        [SerializeField]
        InputActionProperty m_PositionAction;
        /// <summary>
        /// The Input System action to use for Position Tracking for this GameObject. Must be a <see cref="Vector3Control"/> Control.
        /// </summary>
        public InputActionProperty positionAction
        {
            get => m_PositionAction;
            set => SetInputActionProperty(ref m_PositionAction, value);
        }

        [SerializeField]
        InputActionProperty m_RotationAction;
        /// <summary>
        /// The Input System action to use for Rotation Tracking for this GameObject. Must be a <see cref="QuaternionControl"/> Control.
        /// </summary>
        public InputActionProperty rotationAction
        {
            get => m_RotationAction;
            set => SetInputActionProperty(ref m_RotationAction, value);
        }

        [SerializeField]
        InputActionProperty m_TrackingStateAction;
        /// <summary>
        /// The Input System action to get the Tracking State when updating this GameObject position and rotation;
        /// falls back to the tracked device's tracking state that drivies the position or rotation action when not set.
        /// Must be an <see cref="IntegerControl"/>> Control.
        /// </summary>
        /// <seealso cref="InputTrackingState"/>
        public InputActionProperty trackingStateAction
        {
            get => m_TrackingStateAction;
            set => SetInputActionProperty(ref m_TrackingStateAction, value);
        }

        [SerializeField]
        InputActionProperty m_SelectAction;
        /// <summary>
        /// The Input System action to use for Selecting an Interactable. Must be a <see cref="ButtonControl"/> Control.
        /// </summary>
        public InputActionProperty selectAction
        {
            get => m_SelectAction;
            set => SetInputActionProperty(ref m_SelectAction, value);
        }
        
        [SerializeField]
        InputActionProperty m_SelectActionValue;
        /// <summary>
        /// The Input System action to read values for Selecting an Interactable. Must be an <see cref="AxisControl"/> Control.
        /// </summary>
        public InputActionProperty selectActionValue
        {
            get => m_SelectActionValue;
            set => SetInputActionProperty(ref m_SelectActionValue, value);
        }

        [SerializeField]
        InputActionProperty m_ActivateAction;
        /// <summary>
        /// The Input System action to use for Activating a selected Interactable. Must be a <see cref="ButtonControl"/> Control.
        /// </summary>
        public InputActionProperty activateAction
        {
            get => m_ActivateAction;
            set => SetInputActionProperty(ref m_ActivateAction, value);
        }
        
        [SerializeField]
        InputActionProperty m_ActivateActionValue;
        /// <summary>
        /// The Input System action to read values for Activating a selected Interactable. Must be an <see cref="AxisControl"/> Control.
        /// </summary>
        public InputActionProperty activateActionValue
        {
            get => m_ActivateActionValue;
            set => SetInputActionProperty(ref m_ActivateActionValue, value);
        }

        [SerializeField]
        InputActionProperty m_UIPressAction;
        /// <summary>
        /// The Input System action to use for UI interaction. Must be a <see cref="ButtonControl"/> Control.
        /// </summary>
        public InputActionProperty uiPressAction
        {
            get => m_UIPressAction;
            set => SetInputActionProperty(ref m_UIPressAction, value);
        }
        
        [SerializeField]
        InputActionProperty m_UIPressActionValue;
        /// <summary>
        /// The Input System action to read values for UI interaction. Must be an <see cref="AxisControl"/> Control.
        /// </summary>
        public InputActionProperty uiPressActionValue
        {
            get => m_UIPressActionValue;
            set => SetInputActionProperty(ref m_UIPressActionValue, value);
        }

        [SerializeField]
        InputActionProperty m_HapticDeviceAction;
        /// <summary>
        /// The Input System action to use for identifying the device to send haptic impulses to.
        /// Can be any control type that will have an active control driving the action.
        /// </summary>
        public InputActionProperty hapticDeviceAction
        {
            get => m_HapticDeviceAction;
            set => SetInputActionProperty(ref m_HapticDeviceAction, value);
        }

        [SerializeField]
        InputActionProperty m_RotateAnchorAction;
        /// <summary>
        /// The Input System action to use for rotating the interactor's attach point.
        /// Must be a <see cref="Vector2Control"/> Control. Uses the X-axis as the rotation input.
        /// </summary>
        public InputActionProperty rotateAnchorAction
        {
            get => m_RotateAnchorAction;
            set => SetInputActionProperty(ref m_RotateAnchorAction, value);
        }

        [SerializeField]
        InputActionProperty m_TranslateAnchorAction;
        /// <summary>
        /// The Input System action to use for translating the interactor's attach point closer or further away from the interactor.
        /// Must be a <see cref="Vector2Control"/> Control. Uses the Y-axis as the translation input.
        /// </summary>
        public InputActionProperty translateAnchorAction
        {
            get => m_TranslateAnchorAction;
            set => SetInputActionProperty(ref m_TranslateAnchorAction, value);
        }

        bool m_HasCheckedDisabledTrackingInputReferenceActions;
        bool m_HasCheckedDisabledInputReferenceActions;

        /// <inheritdoc />
        protected override void OnEnable()
        {
            base.OnEnable();
            EnableAllDirectActions();
        }

        /// <inheritdoc />
        protected override void OnDisable()
        {
            base.OnDisable();
            DisableAllDirectActions();
        }

        /// <inheritdoc />
        protected override void UpdateTrackingInput(XRControllerState controllerState)
        {
            base.UpdateTrackingInput(controllerState);
            if (controllerState == null)
                return;

            var posAction = m_PositionAction.action;
            var rotAction = m_RotationAction.action;
            var hasPositionAction = posAction != null;
            var hasRotationAction = rotAction != null;

            // Warn the user if using referenced actions and they are disabled
            if (!m_HasCheckedDisabledTrackingInputReferenceActions && (hasPositionAction || hasRotationAction))
            {
                if (IsDisabledReferenceAction(m_PositionAction) || IsDisabledReferenceAction(m_RotationAction))
                {
                    Debug.LogWarning("'Enable Input Tracking' is enabled, but Position and/or Rotation Action is disabled." +
                        " The pose of the controller will not be updated correctly until the Input Actions are enabled." +
                        " Input Actions in an Input Action Asset must be explicitly enabled to read the current value of the action." +
                        " The Input Action Manager behavior can be added to a GameObject in a Scene and used to enable all Input Actions in a referenced Input Action Asset.",
                        this);
                }

                m_HasCheckedDisabledTrackingInputReferenceActions = true;
            }

            // Update inputTrackingState
            controllerState.inputTrackingState = InputTrackingState.None;
            var inputTrackingStateAction = m_TrackingStateAction.action;

            // Actions without bindings are considered empty and will fallback
            if (inputTrackingStateAction != null && inputTrackingStateAction.bindings.Count > 0)
            {
                controllerState.inputTrackingState = (InputTrackingState)inputTrackingStateAction.ReadValue<int>();
            }
            else
            {
                // Fallback to the device trackingState if m_TrackingStateAction is not valid
                var positionTrackedDevice = hasPositionAction ? posAction.activeControl?.device as TrackedDevice : null;
                var rotationTrackedDevice = hasRotationAction ? rotAction.activeControl?.device as TrackedDevice : null;
                var positionTrackingState = InputTrackingState.None;

                if (positionTrackedDevice != null)
                    positionTrackingState = (InputTrackingState)positionTrackedDevice.trackingState.ReadValue();

                // If the tracking devices are different only the InputTrackingState.Position and InputTrackingState.Position flags will be considered
                if (positionTrackedDevice != rotationTrackedDevice)
                {
                    var rotationTrackingState = InputTrackingState.None;
                    if (rotationTrackedDevice != null)
                        rotationTrackingState = (InputTrackingState)rotationTrackedDevice.trackingState.ReadValue();

                    positionTrackingState &= InputTrackingState.Position;
                    rotationTrackingState &= InputTrackingState.Rotation;
                    controllerState.inputTrackingState = positionTrackingState | rotationTrackingState;
                }
                else
                {
                    controllerState.inputTrackingState = positionTrackingState;
                }
            }

            // Update position
            if (hasPositionAction && (controllerState.inputTrackingState & InputTrackingState.Position) != 0)
            {
                var pos = posAction.ReadValue<Vector3>();
                controllerState.position = pos;
            }

            // Update rotation
            if (hasRotationAction && (controllerState.inputTrackingState & InputTrackingState.Rotation) != 0)
            {
                var rot = rotAction.ReadValue<Quaternion>();
                controllerState.rotation = rot;
            }
        }

        /// <inheritdoc />
        protected override void UpdateInput(XRControllerState controllerState)
        {
            base.UpdateInput(controllerState);
            if (controllerState == null)
                return;

            // Warn the user if using referenced actions and they are disabled
            if (!m_HasCheckedDisabledInputReferenceActions &&
                (m_SelectAction.action != null || m_ActivateAction.action != null || m_UIPressAction.action != null))
            {
                if (IsDisabledReferenceAction(m_SelectAction) || IsDisabledReferenceAction(m_ActivateAction) || IsDisabledReferenceAction(m_UIPressAction))
                {
                    Debug.LogWarning("'Enable Input Actions' is enabled, but Select, Activate, and/or UI Press Action is disabled." +
                        " The controller input will not be handled correctly until the Input Actions are enabled." +
                        " Input Actions in an Input Action Asset must be explicitly enabled to read the current value of the action." +
                        " The Input Action Manager behavior can be added to a GameObject in a Scene and used to enable all Input Actions in a referenced Input Action Asset.",
                        this);
                }

                m_HasCheckedDisabledInputReferenceActions = true;
            }

            controllerState.ResetFrameDependentStates();

            var selectValueAction = m_SelectActionValue.action;
            if (selectValueAction == null || selectValueAction.bindings.Count <= 0)
                selectValueAction = m_SelectAction.action;
            controllerState.selectInteractionState.SetFrameState(IsPressed(m_SelectAction.action), ReadValue(selectValueAction));

            var activateValueAction = m_ActivateActionValue.action;
            if (activateValueAction == null || activateValueAction.bindings.Count <= 0)
                activateValueAction = m_ActivateAction.action;
            controllerState.activateInteractionState.SetFrameState(IsPressed(m_ActivateAction.action), ReadValue(activateValueAction));

            var uiPressValueAction = m_UIPressActionValue.action;
            if (uiPressValueAction == null || uiPressValueAction.bindings.Count <= 0)
                uiPressValueAction = m_UIPressAction.action;
            controllerState.uiPressInteractionState.SetFrameState(IsPressed(m_UIPressAction.action), ReadValue(uiPressValueAction));
        }

        /// <summary>
        /// Evaluates whether the given input action is considered pressed.
        /// </summary>
        /// <param name="action">The input action to check.</param>
        /// <returns>Returns <see langword="true"/> when the input action is considered pressed. Otherwise, returns <see langword="false"/>.</returns>
        protected virtual bool IsPressed(InputAction action)
        {
            if (action == null)
                return false;

#if INPUT_SYSTEM_1_1_OR_NEWER || INPUT_SYSTEM_1_1_PREVIEW // 1.1.0-preview.2 or newer, including pre-release
                return action.phase == InputActionPhase.Performed;
#else
            if (action.activeControl is ButtonControl buttonControl)
                return buttonControl.isPressed;

            if (action.activeControl is AxisControl)
                return action.ReadValue<float>() >= m_ButtonPressPoint;

            return action.triggered || action.phase == InputActionPhase.Performed;
#endif
        }

        /// <summary>
        /// Reads and returns the given action value.
        /// </summary>
        /// <param name="action">The action to read the value from.</param>
        /// <returns>Returns the action value. If the action is <see langword="null"/> returns the default <see langword="float"/> value (<c>0f</c>).</returns>
        protected virtual float ReadValue(InputAction action)
        {
            if (action == null)
                return default;

            if (action.activeControl is AxisControl)
                return action.ReadValue<float>();

            if (action.activeControl is Vector2Control)
                return action.ReadValue<Vector2>().magnitude;

            return IsPressed(action) ? 1f : 0f;
        }

        /// <inheritdoc />
        public override bool SendHapticImpulse(float amplitude, float duration)
        {
            if (m_HapticDeviceAction.action?.activeControl?.device is XRControllerWithRumble rumbleController)
            {
                rumbleController.SendImpulse(amplitude, duration);
                return true;
            }

            return false;
        }

        void EnableAllDirectActions()
        {
            m_PositionAction.EnableDirectAction();
            m_RotationAction.EnableDirectAction();
            m_TrackingStateAction.EnableDirectAction();
            m_SelectAction.EnableDirectAction();
            m_SelectActionValue.EnableDirectAction();
            m_ActivateAction.EnableDirectAction();
            m_ActivateActionValue.EnableDirectAction();
            m_UIPressAction.EnableDirectAction();
            m_UIPressActionValue.EnableDirectAction();
            m_HapticDeviceAction.EnableDirectAction();
            m_RotateAnchorAction.EnableDirectAction();
            m_TranslateAnchorAction.EnableDirectAction();
        }

        void DisableAllDirectActions()
        {
            m_PositionAction.DisableDirectAction();
            m_RotationAction.DisableDirectAction();
            m_TrackingStateAction.DisableDirectAction();
            m_SelectAction.DisableDirectAction();
            m_SelectActionValue.DisableDirectAction();
            m_ActivateAction.DisableDirectAction();
            m_ActivateActionValue.DisableDirectAction();
            m_UIPressAction.DisableDirectAction();
            m_UIPressActionValue.DisableDirectAction();
            m_HapticDeviceAction.DisableDirectAction();
            m_RotateAnchorAction.DisableDirectAction();
            m_TranslateAnchorAction.DisableDirectAction();
        }

        void SetInputActionProperty(ref InputActionProperty property, InputActionProperty value)
        {
            if (Application.isPlaying)
                property.DisableDirectAction();

            property = value;

            if (Application.isPlaying && isActiveAndEnabled)
                property.EnableDirectAction();
        }

        static bool IsDisabledReferenceAction(InputActionProperty property) =>
            property.reference != null && property.reference.action != null && !property.reference.action.enabled;
    }
}
