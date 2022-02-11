using System;
using UnityEngine;
using UnityEditor;
using UnityEditor.SceneManagement;

#if INCLUDE_INPUT_SYSTEM
using UnityEngine.InputSystem;
using UnityEngine.InputSystem.XR;
#endif


namespace Unity.XR.CoreUtils.Editor
{
    static class CreateUtils
    {
        [MenuItem("GameObject/XR/XR Origin", false, 10)]
        static void CreateXROrigin(MenuCommand menuCommand)
        {
            Transform parentOfNewGameObject = menuCommand.GetContextTransform();
            var xrOrigin = CreateXROriginBase(parentOfNewGameObject);
            Selection.activeGameObject = xrOrigin.gameObject;
        }

        static XROrigin CreateXROriginBase(Transform parentOfNewGameObject)
        {
            var xrCamera = Camera.main;

            // Don't use if the MainCamera is not part of the current stage being edited.
            if (xrCamera != null && !StageUtility.GetCurrentStageHandle().Contains(xrCamera.gameObject))
                xrCamera = null;

            // If the existing MainCamera is already part of an XR Origin,
            // create a new camera instead of trying to reuse it.
            if (xrCamera != null && xrCamera.GetComponentInParent<XROrigin>() != null)
                xrCamera = null;

            // If the existing MainCamera is selected, the hierarchy would be invalid
            // since the camera should be a child of the rig.
            if (xrCamera != null && xrCamera.transform == parentOfNewGameObject)
                parentOfNewGameObject = parentOfNewGameObject.parent;

            var xrOriginGO = CreateAndPlaceGameObject("XR Origin", parentOfNewGameObject, typeof(XROrigin));

            var cameraOffsetGO = ObjectFactory.CreateGameObject("Camera Offset");
            Place(cameraOffsetGO, xrOriginGO.transform);

            if (xrCamera == null)
            {
#if INCLUDE_INPUT_SYSTEM
                var xrCameraGO = ObjectFactory.CreateGameObject("Main Camera",
                    typeof(Camera),
                    typeof(AudioListener),
                    typeof(TrackedPoseDriver));
#else
                var xrCameraGO = ObjectFactory.CreateGameObject("Main Camera",
                    typeof(Camera),
                    typeof(AudioListener));
#endif
                xrCamera = xrCameraGO.GetComponent<Camera>();
            }

            Undo.RecordObject(xrCamera, "Configure Camera");
            xrCamera.tag = "MainCamera";
            xrCamera.nearClipPlane = 0.01f;
            Place(xrCamera.gameObject, cameraOffsetGO.transform);

#if INCLUDE_INPUT_SYSTEM
            var trackedPoseDriver = xrCamera.GetComponent<TrackedPoseDriver>();
            if (trackedPoseDriver == null)
                trackedPoseDriver = Undo.AddComponent<TrackedPoseDriver>(xrCamera.gameObject);

            Undo.RecordObject(trackedPoseDriver, "Configure Tracked Pose Driver");
            var positionAction = new InputAction("Position", binding: "<XRHMD>/centerEyePosition", expectedControlType: "Vector3");
            positionAction.AddBinding("<HandheldARInputDevice>/devicePosition");
            var rotationAction = new InputAction("Rotation", binding: "<XRHMD>/centerEyeRotation", expectedControlType: "Quaternion");
            rotationAction.AddBinding("<HandheldARInputDevice>/deviceRotation");
#if INPUT_SYSTEM_1_1_OR_NEWER && !INPUT_SYSTEM_1_1_PREVIEW // 1.1.0-pre.6 or newer, excluding older preview
            trackedPoseDriver.positionInput = new InputActionProperty(positionAction);
            trackedPoseDriver.rotationInput = new InputActionProperty(rotationAction);
#else

            trackedPoseDriver.positionAction = positionAction;
            trackedPoseDriver.rotationAction = rotationAction;
#endif
#else
             Debug.LogWarning(
                        $"Camera \"{xrCamera.name}\" does not use a Tracked Pose Driver and com.unity.inputsystem is not installed, " +
                        "so its transform will not be updated by an XR device.  In order for this to be " +
                        "updated, please install com.unity.inputsystem and add a Tracked Pose Driver.", xrCamera);
#endif
            var xrOrigin = xrOriginGO.GetComponent<XROrigin>();
            Undo.RecordObject(xrOrigin, "Configure XR Origin");
            xrOrigin.CameraFloorOffsetObject = cameraOffsetGO;
            xrOrigin.Camera = xrCamera;
            return xrOrigin;
        }


        static GameObject CreateAndPlaceGameObject(string name, Transform parent, params Type[] types)
        {
            var go = ObjectFactory.CreateGameObject(name, types);

            Place(go, parent);
            Undo.SetCurrentGroupName("Create " + go.name);
            Selection.activeGameObject = go;

            return go;
        }

        static void Place(GameObject go, Transform parent)
        {
            var transform = go.transform;

            if (parent != null)
            {
                // Must call RecordObject and reset values before SetTransformParent to ensure the
                // Transform values are correct upon undo in the case that it's a root object.
                // Undo.SetTransformParent did not have parameter worldPositionStays to be able
                // to set false until 2020.2.0a17 (fb# 1247086).
                Undo.RecordObject(transform, "Reset Transform");
                ResetTransform(transform);
                Undo.SetTransformParent(transform, parent, "Reparenting");
                ResetTransform(transform);
                Undo.RegisterCompleteObjectUndo(go, "Change Layer");
                go.layer = parent.gameObject.layer;
            }
            else
            {
                // Puts it at the scene pivot, and otherwise world origin if there is no Scene view.
                var view = SceneView.lastActiveSceneView;
                if (view != null)
                    view.MoveToView(transform);
                else
                    transform.position = Vector3.zero;

                StageUtility.PlaceGameObjectInCurrentStage(go);
            }

            // Only at this point do we know the actual parent of the object and can modify its name accordingly.
            GameObjectUtility.EnsureUniqueNameForSibling(go);
        }
        static void ResetTransform(Transform transform)
        {
            transform.localPosition = Vector3.zero;
            transform.localRotation = Quaternion.identity;
            transform.localScale = Vector3.one;

            if (transform.parent is RectTransform rectTransform)
            {
                rectTransform = transform as RectTransform;
                if (rectTransform != null)
                {
                    rectTransform.anchorMin = Vector2.zero;
                    rectTransform.anchorMax = Vector2.one;
                    rectTransform.anchoredPosition = Vector2.zero;
                    rectTransform.sizeDelta = Vector2.zero;
                }
            }
        }

        /// <summary>
        /// Gets the <see cref="Transform"/> associated with the <see cref="MenuCommand.context"/>.
        /// </summary>
        /// <param name="menuCommand">The object passed to custom menu item functions to operate on.</param>
        /// <returns>Returns the <see cref="Transform"/> of the object that is the target of a menu command,
        /// or <see langword="null"/> if there is no context.</returns>
        static Transform GetContextTransform(this MenuCommand menuCommand)
        {
            var context = menuCommand.context as GameObject;
            if (context == null)
                return null;

            return context.transform;
        }
    }
}
