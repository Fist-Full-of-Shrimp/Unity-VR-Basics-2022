#if UNITY_EDITOR
using UnityEditor;
using UnityEditor.XR.Management;
#endif

namespace UnityEngine.XR.OpenXR
{
    // These platforms don't support IXRLoaderPreInit
#if UNITY_EDITOR
    [XRSupportedBuildTarget(BuildTargetGroup.WSA)]
#endif
    /// <summary>
    /// Loader for managing OpenXR devices that don't support PreInit.
    /// </summary>
    public class OpenXRLoaderNoPreInit : OpenXRLoaderBase
    {
    }
}