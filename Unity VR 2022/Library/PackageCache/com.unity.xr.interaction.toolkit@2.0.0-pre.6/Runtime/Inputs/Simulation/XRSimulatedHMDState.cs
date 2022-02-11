using System.Runtime.InteropServices;
using UnityEngine.InputSystem.Layouts;
using UnityEngine.InputSystem.LowLevel;
using UnityEngine.InputSystem.Utilities;

namespace UnityEngine.XR.Interaction.Toolkit.Inputs.Simulation
{
    /// <summary>
    /// State for input device representing a simulated XR HMD.
    /// </summary>
    [StructLayout(LayoutKind.Explicit, Size = 117)]
    public struct XRSimulatedHMDState : IInputStateTypeInfo
    {
        /// <summary>
        /// Memory format identifier for <see cref="XRSimulatedHMDState"/>.
        /// </summary>
        /// <seealso cref="InputStateBlock.format"/>
        public static FourCC formatId => new FourCC('X', 'R', 'S', 'H');

        /// <summary>
        /// See <a href="https://docs.unity3d.com/Packages/com.unity.inputsystem@1.2/api/UnityEngine.InputSystem.LowLevel.IInputStateTypeInfo.html">IInputStateTypeInfo</a>.format.
        /// </summary>
        public FourCC format => formatId;

        /// <summary>
        /// The position of the left eye on this device.
        /// </summary>
        [InputControl(usage = "LeftEyePosition")]
        [FieldOffset(0)]
        public Vector3 leftEyePosition;

        /// <summary>
        /// The rotation of the left eye on this device.
        /// </summary>
        [InputControl(usage = "LeftEyeRotation")]
        [FieldOffset(12)]
        public Quaternion leftEyeRotation;

        /// <summary>
        /// The position of the right eye on this device.
        /// </summary>
        [InputControl(usage = "RightEyePosition")]
        [FieldOffset(28)]
        public Vector3 rightEyePosition;

        /// <summary>
        /// The rotation of the right eye on this device.
        /// </summary>
        [InputControl(usage = "RightEyeRotation")]
        [FieldOffset(40)]
        public Quaternion rightEyeRotation;

        /// <summary>
        /// The position of the center eye on this device.
        /// </summary>
        [InputControl(usage = "CenterEyePosition")]
        [FieldOffset(56)]
        public Vector3 centerEyePosition;

        /// <summary>
        /// The rotation of the center eye on this device.
        /// </summary>
        [InputControl(usage = "CenterEyeRotation")]
        [FieldOffset(68)]
        public Quaternion centerEyeRotation;

        /// <summary>
        /// Represents the values being tracked for this device.
        /// </summary>
        [InputControl(usage = "TrackingState", layout = "Integer")]
        [FieldOffset(84)]
        public int trackingState;

        /// <summary>
        /// Informs to the developer whether the device is currently being tracked.
        /// </summary>
        [InputControl(usage = "IsTracked", layout = "Button")]
        [FieldOffset(88)]
        public bool isTracked;

        /// <summary>
        /// The position of the device.
        /// </summary>
        [InputControl(usage = "DevicePosition")]
        [FieldOffset(89)]
        public Vector3 devicePosition;

        /// <summary>
        /// The rotation of this device.
        /// </summary>
        [InputControl(usage = "DeviceRotation")]
        [FieldOffset(101)]
        public Quaternion deviceRotation;

        /// <summary>
        /// See <see cref="MonoBehaviour"/>.
        /// </summary>
        public void Reset()
        {
            leftEyePosition = default;
            leftEyeRotation = Quaternion.identity;
            rightEyePosition = default;
            rightEyeRotation = Quaternion.identity;
            centerEyePosition = default;
            centerEyeRotation = Quaternion.identity;
            trackingState = default;
            isTracked = default;
            devicePosition = default;
            deviceRotation = Quaternion.identity;
        }
    }
}
