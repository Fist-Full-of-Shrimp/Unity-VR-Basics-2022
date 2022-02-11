using UnityEngine;
using System;

namespace Unity.XR.Oculus
{
    public class InputFocus
    {
        /// <summary>
        /// Occurs when Input Focus is acquired. The application is the foreground application and receives input.
        /// </summary>
        public static event Action InputFocusAcquired;

        /// <summary>
        /// Occurs when Input Focus is lost. The application is in the background (but possibly still visible), while the Universal Menu is up.
        /// </summary>
        public static event Action InputFocusLost;

        private static bool hadInputFocus = false;

        internal static bool hasInputFocus
        {
            get
            {
                return NativeMethods.GetHasInputFocus();
            }
        }
        
        internal static void Update()
        {
            bool appHasInputFocus = hasInputFocus;
            if (!appHasInputFocus && hadInputFocus)
            {
                if (InputFocusLost != null)
                    InputFocusLost();
            }
        
            if (appHasInputFocus && !hadInputFocus)
            {
                if (InputFocusAcquired != null)
                    InputFocusAcquired();
            }
        
            hadInputFocus = appHasInputFocus;
        }
    }
}