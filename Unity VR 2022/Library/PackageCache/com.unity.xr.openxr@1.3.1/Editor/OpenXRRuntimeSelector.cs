using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using UnityEngine;
using Microsoft.Win32;

namespace UnityEditor.XR.OpenXR
{
    internal class OpenXRRuntimeSelector
    {
        class RuntimeDetector
        {
            const string k_RuntimeEnvKey = "XR_RUNTIME_JSON";
            public virtual string name { get; }
            public virtual string jsonPath { get; }
            public virtual string tooltip => jsonPath;

            public virtual bool detected => File.Exists(jsonPath);

            public virtual void PrepareRuntime()
            {

            }

            public virtual void Activate()
            {
                if (detected)
                {
                    Environment.SetEnvironmentVariable(k_RuntimeEnvKey, jsonPath);
                }
            }

            public virtual void Deactivate()
            {
                Environment.SetEnvironmentVariable(k_RuntimeEnvKey, "");
            }
        };

        class SystemDefault : RuntimeDetector
        {
            public override string name
            {
                get
                {
                    string ret = "System Default";
                    if (string.IsNullOrEmpty(tooltip))
                    {
                        ret += " (None Set)";
                    }
                    return ret;
                }
            }

            public override string jsonPath => "";

            public override string tooltip => (string) Registry.GetValue(@"HKEY_LOCAL_MACHINE\SOFTWARE\Khronos\OpenXR\1", "ActiveRuntime", "");

            public override bool detected => true;
        }

        class OtherRuntime : RuntimeDetector
        {
            private string runtimeJsonPath = "";

            public override string name => "Other";

            public override string jsonPath => runtimeJsonPath;

            public override void PrepareRuntime()
            {
                var selectedJson = EditorUtility.OpenFilePanel("Select OpenXR Runtime json", "", "json");
                if (!string.IsNullOrEmpty(selectedJson))
                {
                    runtimeJsonPath = selectedJson;
                    base.PrepareRuntime();
                }
            }

            public override bool detected => true;
        }

        class OculusDetector : RuntimeDetector
        {
            private const string installLocKey = @"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Oculus";
            private const string installLocValue = "InstallLocation";
            private const string jsonName = @"Support\oculus-runtime\oculus_openxr_64.json";

            public override string name => "Oculus";

            public override string jsonPath
            {
                get
                {
                    var oculusPath = (string)Registry.GetValue(installLocKey, installLocValue, "");
                    if (string.IsNullOrEmpty(oculusPath)) return "";
                    return Path.Combine(oculusPath, jsonName);
                }
            }
        }

        class SteamVRDetector : RuntimeDetector
        {
            public override string name => "SteamVR";

            public override string jsonPath => @"C:\Program Files (x86)\Steam\steamapps\common\SteamVR\steamxr_win64.json";
        }

        class WindowsMRDetector : RuntimeDetector
        {
            public override string name => "Windows Mixed Reality";

            public override string jsonPath => @"C:\WINDOWS\system32\MixedRealityRuntime.json";
        }


        private static List<RuntimeDetector> runtimeDetectors = new List<RuntimeDetector>()
        {
            new SystemDefault(), // SystemDefault must always be the first item in the list.
            new WindowsMRDetector(),
            new SteamVRDetector(),
            new OculusDetector(),
            new OtherRuntime(),
        };

        static class Content
        {
            public static readonly GUIContent k_ActiveRuntimeLabel = new GUIContent("Play Mode OpenXR Runtime", "Changing this value will only affect this instance of the editor.");
        }

        static int selectedRuntimeIndex = -1;

        const string k_SelectedRuntimeEnvKey = "XR_SELECTED_RUNTIME_JSON";

        static int GetActiveRuntimeIndex(List<RuntimeDetector> runtimes)
        {
            string envValue = Environment.GetEnvironmentVariable(k_SelectedRuntimeEnvKey);
            if (string.IsNullOrEmpty(envValue))
                return 0;

            var runtime = runtimes.Where(r => String.Compare(r.jsonPath, envValue, StringComparison.InvariantCulture) == 0);
            if (!runtime.Any())
                return 0;

            return runtimes.IndexOf(runtime.First());
        }


        public static void DrawSelector()
        {
            EditorGUIUtility.labelWidth = 200;
            GUILayout.BeginHorizontal();
            var runtimes = runtimeDetectors.Where(runtime => runtime.detected).ToList();
            if (selectedRuntimeIndex < 0)
                selectedRuntimeIndex = GetActiveRuntimeIndex(runtimes);
            int index = EditorGUILayout.Popup(Content.k_ActiveRuntimeLabel, selectedRuntimeIndex, runtimes.Select(s => new GUIContent(s.name, s.tooltip)).ToArray());
            if (selectedRuntimeIndex != index)
            {
                selectedRuntimeIndex = index;
                runtimes[selectedRuntimeIndex].PrepareRuntime();
                Environment.SetEnvironmentVariable(k_SelectedRuntimeEnvKey, runtimes[selectedRuntimeIndex].jsonPath);
            }
            GUILayout.EndHorizontal();
            EditorGUIUtility.labelWidth = 0;
        }

        static OpenXRRuntimeSelector()
        {
            EditorApplication.playModeStateChanged += (state) =>
            {
                var runtimes = runtimeDetectors.Where(runtime => runtime.detected).ToList();
                int runtimeIndex = GetActiveRuntimeIndex(runtimes);
                switch (state)
                {
                    case PlayModeStateChange.ExitingEditMode:
                        if (runtimeIndex >= 0)
                        {
                            runtimes[runtimeIndex].Activate();
                        }
                        break;

                    case PlayModeStateChange.EnteredEditMode:
                        if (runtimeIndex >= 0)
                        {
                            runtimes[runtimeIndex].Deactivate();
                        }
                        break;
                }
            };
        }
    }
}
