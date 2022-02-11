using System;
using UnityEngine;

namespace Unity.XR.Oculus
{
    public static partial class Utils
    {
        /// <summary>
        /// Set the degree of foveation. Only supported on mobile. See [Oculus Documention](https://developer.oculus.com/documentation/quest/latest/concepts/mobile-ffr/).
        /// </summary>
        /// <param name="level">
        ///  level can be 0, 1, 2, 3, or 4:
        /// 
        /// * 0 disables multi-resolution
        /// * 1 low FFR setting
        /// * 2 medium FFR setting
        /// * 3 high FFR setting
        /// * 4 high top FFR setting
        /// </param>
        public static void SetFoveationLevel(int level)
        {
            if (!NativeMethods.GetTiledMultiResSupported())
            {
                Debug.LogWarning("Can't set foveation level on current platform");
                return;
            }

            NativeMethods.SetTiledMultiResLevel(level);
        }

        /// <summary>
        /// Enable or disable dynamic FFR. Only supported on mobile. See [Oculus Documention](https://developer.oculus.com/documentation/quest/latest/concepts/mobile-ffr/).
        /// </summary>
        /// <param name="enable">
        /// Set to true to enable dynamic FFR or false to disable it.
        /// </param>
        public static bool EnableDynamicFFR(bool enable)
        {
            if (!NativeMethods.GetTiledMultiResSupported())
            {
                Debug.LogWarning("Can't enable dynamic FFR on current platform");
                return false;
            }

            NativeMethods.SetTiledMultiResDynamic(enable);
            return true;
        }

        /// <summary>
        /// Returns the degree of foveation. Only supported on mobile. See [Oculus Documentation](https://developer.oculus.com/documentation/quest/latest/concepts/mobile-ffr/).
        /// </summary>
        /// <returns>
        /// * -1 error retrieving foveation level
        /// * 0 disables multi-resolution
        /// * 1 low FFR setting
        /// * 2 medium FFR setting
        /// * 3 high FFR setting
        /// * 4 high top FFR setting
        /// </returns>
        public static int GetFoveationLevel()
        {
            if (!NativeMethods.GetTiledMultiResSupported())
            {
                Debug.LogWarning("Can't get foveation level on current platform");
                return -1;
            }

            return NativeMethods.GetTiledMultiResLevel();
        }
    }
}
