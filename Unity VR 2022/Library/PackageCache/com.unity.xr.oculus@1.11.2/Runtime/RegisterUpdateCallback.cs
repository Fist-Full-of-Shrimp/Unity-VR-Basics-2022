#if UNITY_STANDALONE_WIN && !UNITY_EDITOR
#define OCULUSPLUGIN_WINDOWS_PLATFORM_ONLY
#endif

using UnityEngine;

namespace Unity.XR.Oculus
{
    internal static class RegisterUpdateCallback
    {
        internal static void Initialize()
        {
            Application.onBeforeRender += Update;
        }

        internal static void Deinitialize()
        {
            Application.onBeforeRender -= Update;
        }
        
        private static void Update()
        {
            //Detect if input focus lost or acquired.
            InputFocus.Update();

#if OCULUSPLUGIN_WINDOWS_PLATFORM_ONLY
            //Detect if App is closed from Oculus dash menu and close Windows based App as well.
            if (NativeMethods.GetAppShouldQuit())
            {
                Application.Quit();
            }
#endif
        }
    }
}