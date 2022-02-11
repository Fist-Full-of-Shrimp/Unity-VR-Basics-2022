using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using Unity.XR.Oculus;

namespace Unity.XR.Oculus.Editor
{
    [CustomEditor(typeof(OculusSettings))]
    public class OculusSettingsEditor : UnityEditor.Editor
    {
        private const string kSharedDepthBuffer = "SharedDepthBuffer";
        private const string kDashSupport = "DashSupport";
        private const string kStereoRenderingModeDesktop = "m_StereoRenderingModeDesktop";
        private const string kStereoRenderingModeAndroid = "m_StereoRenderingModeAndroid";
        private const string kLowOverheadMode = "LowOverheadMode";
        private const string kOptimizeBufferDiscards = "OptimizeBufferDiscards";
        private const string kPhaseSync = "PhaseSync";
        private const string kSubsampledLayout = "SubsampledLayout";
        private const string kTargetQuest = "TargetQuest";
        private const string kTargetQuest2 = "TargetQuest2";
        private const string kSystemSplashScreen = "SystemSplashScreen";

        static GUIContent s_SharedDepthBufferLabel = EditorGUIUtility.TrTextContent("Shared Depth Buffer");
        static GUIContent s_DashSupportLabel = EditorGUIUtility.TrTextContent("Dash Support");
        static GUIContent s_StereoRenderingModeLabel = EditorGUIUtility.TrTextContent("Stereo Rendering Mode");
        static GUIContent s_LowOverheadModeLabel = EditorGUIUtility.TrTextContent("Low Overhead Mode (GLES)");
        static GUIContent s_OptimizeBufferDiscardsLabel = EditorGUIUtility.TrTextContent("Optimize Buffer Discards (Vulkan)");
        static GUIContent s_PhaseSyncLabel = EditorGUIUtility.TrTextContent("Phase Sync");
        static GUIContent s_SubsampledLayoutLabel = EditorGUIUtility.TrTextContent("Subsampled Layout (Vulkan/Quest 2)");
        static GUIContent s_TargetDevicesLabel = EditorGUIUtility.TrTextContent("Target Devices");
        static GUIContent s_TargetQuestLabel = EditorGUIUtility.TrTextContent("Quest");
        static GUIContent s_TargetQuest2Label = EditorGUIUtility.TrTextContent("Quest 2");
        static GUIContent s_SystemSplashScreen = EditorGUIUtility.TrTextContent("System Splash Screen");

        private SerializedProperty m_SharedDepthBuffer;
        private SerializedProperty m_DashSupport;
        private SerializedProperty m_StereoRenderingModeDesktop;
        private SerializedProperty m_StereoRenderingModeAndroid;
        private SerializedProperty m_LowOverheadMode;
        private SerializedProperty m_OptimizeBufferDiscards;
        private SerializedProperty m_PhaseSync;
        private SerializedProperty m_SubsampledLayout;
        private SerializedProperty m_TargetQuest;
        private SerializedProperty m_TargetQuest2;
        private SerializedProperty m_SystemSplashScreen;

        public override void OnInspectorGUI()
        {
            if (serializedObject == null || serializedObject.targetObject == null)
                return;

            if (m_SharedDepthBuffer == null) m_SharedDepthBuffer = serializedObject.FindProperty(kSharedDepthBuffer);
            if (m_DashSupport == null) m_DashSupport = serializedObject.FindProperty(kDashSupport);
            if (m_StereoRenderingModeDesktop == null) m_StereoRenderingModeDesktop = serializedObject.FindProperty(kStereoRenderingModeDesktop);
            if (m_StereoRenderingModeAndroid == null) m_StereoRenderingModeAndroid = serializedObject.FindProperty(kStereoRenderingModeAndroid);
            if (m_LowOverheadMode == null) m_LowOverheadMode = serializedObject.FindProperty(kLowOverheadMode);
            if (m_OptimizeBufferDiscards == null) m_OptimizeBufferDiscards = serializedObject.FindProperty(kOptimizeBufferDiscards);
            if (m_PhaseSync == null) m_PhaseSync = serializedObject.FindProperty(kPhaseSync);
            if (m_SubsampledLayout == null) m_SubsampledLayout = serializedObject.FindProperty(kSubsampledLayout);
            if (m_TargetQuest == null) m_TargetQuest = serializedObject.FindProperty(kTargetQuest);
            if (m_TargetQuest2 == null) m_TargetQuest2 = serializedObject.FindProperty(kTargetQuest2);
            if (m_SystemSplashScreen == null) m_SystemSplashScreen = serializedObject.FindProperty(kSystemSplashScreen);

            serializedObject.Update();

            EditorGUIUtility.labelWidth = 220.0f;

            BuildTargetGroup selectedBuildTargetGroup = EditorGUILayout.BeginBuildTargetSelectionGrouping();
            EditorGUILayout.Space();

            EditorGUILayout.BeginVertical(GUILayout.ExpandWidth(true));
            if (EditorApplication.isPlayingOrWillChangePlaymode)
            {
                EditorGUILayout.HelpBox("Oculus settings cannnot be changed when the editor is in play mode.", MessageType.Info);
                EditorGUILayout.Space();
            }
            EditorGUI.BeginDisabledGroup(EditorApplication.isPlayingOrWillChangePlaymode);
            if (selectedBuildTargetGroup == BuildTargetGroup.Standalone)
            {
                EditorGUILayout.PropertyField(m_StereoRenderingModeDesktop, s_StereoRenderingModeLabel);
                EditorGUILayout.PropertyField(m_SharedDepthBuffer, s_SharedDepthBufferLabel);
                EditorGUILayout.PropertyField(m_DashSupport, s_DashSupportLabel);
            }
            else if(selectedBuildTargetGroup == BuildTargetGroup.Android)
            {
                EditorGUILayout.PropertyField(m_StereoRenderingModeAndroid, s_StereoRenderingModeLabel);
                EditorGUILayout.PropertyField(m_LowOverheadMode, s_LowOverheadModeLabel);
                EditorGUILayout.PropertyField(m_OptimizeBufferDiscards, s_OptimizeBufferDiscardsLabel);
                EditorGUILayout.PropertyField(m_PhaseSync, s_PhaseSyncLabel);
#if UNITY_2020_1_OR_NEWER
                EditorGUILayout.PropertyField(m_SubsampledLayout, s_SubsampledLayoutLabel);
#endif

                EditorGUILayout.Space();

                GUILayout.Label(s_TargetDevicesLabel, EditorStyles.boldLabel);

                EditorGUILayout.PropertyField(m_TargetQuest, s_TargetQuestLabel);
                EditorGUILayout.PropertyField(m_TargetQuest2, s_TargetQuest2Label);

                EditorGUILayout.Space();

                EditorGUILayout.PropertyField(m_SystemSplashScreen, s_SystemSplashScreen);
            }
            EditorGUI.EndDisabledGroup();
            EditorGUILayout.EndVertical();
            EditorGUILayout.EndBuildTargetSelectionGrouping();

            serializedObject.ApplyModifiedProperties();

            EditorGUIUtility.labelWidth = 0.0f;
        }
    }
}
