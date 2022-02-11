#if UNITY_EDITOR
using UnityEditor;
using UnityEngine;

namespace Unity.XR.CoreUtils.GUI
{
    public static class ScreenGUIUtils
    {
        /// <summary>
        /// Gets the width of the screen, in points (pixels at 100% DPI)
        /// </summary>
        public static float PointWidth => Screen.width / EditorGUIUtility.pixelsPerPoint;

        /// <summary>
        /// Gets the height of the screen, in points (pixels at 100% DPI)
        /// </summary>
        public static float PointHeight => Screen.height / EditorGUIUtility.pixelsPerPoint;
    }
}
#endif
