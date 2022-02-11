using System.Linq;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEditor.XR.Management;
using UnityEngine.XR.Management;

namespace UnityEditor.XR.OpenXR
{
    [InitializeOnLoad]
    internal class BuildHelperUtils : IPreprocessBuildWithReport
    {
        public static bool HasLoader(BuildTargetGroup targetGroup, System.Type loader)
        {
            var settings = XRGeneralSettingsPerBuildTarget.XRGeneralSettingsForBuildTarget(targetGroup);

            if (settings)
            {
#pragma warning disable CS0618
                return settings.Manager.loaders.Any(loader.IsInstanceOfType);
#pragma warning restore CS0618
            }

            return false;
        }

        public int callbackOrder => -100;

        public void OnPreprocessBuild(BuildReport report)
        {
            MakeSureXRGeneralSettingsExists(report.summary.platformGroup);
        }

        public static XRGeneralSettings MakeSureXRGeneralSettingsExists(BuildTargetGroup targetGroup)
        {
            // If we don't have XRGeneralSettings in EditorBuildSettings, check if we have one in the project and set it.
            var settings = XRGeneralSettingsPerBuildTarget.XRGeneralSettingsForBuildTarget(targetGroup);
            if (!settings)
            {
                string searchText = "t:XRGeneralSettings";
                string[] assets = AssetDatabase.FindAssets(searchText);
                if (assets.Length > 0)
                {
                    string path = AssetDatabase.GUIDToAssetPath(assets[0]);
                    var allSettings = AssetDatabase.LoadAssetAtPath(path, typeof(XRGeneralSettingsPerBuildTarget)) as XRGeneralSettingsPerBuildTarget;
                    EditorBuildSettings.AddConfigObject(XRGeneralSettings.k_SettingsKey, allSettings, true);
                }
            }

            return settings;
        }

        static BuildHelperUtils()
        {
            EditorApplication.playModeStateChanged += (state) =>
            {
                if (state == PlayModeStateChange.ExitingEditMode)
                    MakeSureXRGeneralSettingsExists(BuildTargetGroup.Standalone);
            };
        }
    }
}
