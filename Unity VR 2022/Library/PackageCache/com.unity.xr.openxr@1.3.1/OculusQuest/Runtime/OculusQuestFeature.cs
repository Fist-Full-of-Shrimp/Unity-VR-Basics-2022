using System.Collections.Generic;
using UnityEditor;

#if UNITY_EDITOR
using UnityEditor.XR.OpenXR.Features;
using UnityEngine.XR.OpenXR.Features.Interactions;
#endif

namespace UnityEngine.XR.OpenXR.Features.OculusQuestSupport
{
    /// <summary>
    /// Enables the Oculus mobile OpenXR Loader for Android, and modifies the AndroidManifest to be compatible with Quest.
    /// </summary>
#if UNITY_EDITOR
    [OpenXRFeature(UiName = "Oculus Quest Support",
        Desc="Necessary to deploy an Oculus Quest compatible app.",
        Company = "Unity",
        DocumentationLink = "https://developer.oculus.com/downloads/package/oculus-openxr-mobile-sdk/",
        OpenxrExtensionStrings = "XR_OCULUS_android_initialize_loader",
        Version = "1.0.0",
        BuildTargetGroups = new []{BuildTargetGroup.Android},
        CustomRuntimeLoaderBuildTargets = new []{BuildTarget.Android},
        FeatureId = featureId
    )]
#endif
    public class OculusQuestFeature : OpenXRFeature
    {
        /// <summary>
        /// The feature id string. This is used to give the feature a well known id for reference.
        /// </summary>
        public const string featureId = "com.unity.openxr.feature.oculusquest";

#if UNITY_EDITOR
        protected override void GetValidationChecks(List<ValidationRule> rules, BuildTargetGroup targetGroup)
        {
            rules.Add(new ValidationRule(this)
            {
                message = "Only the Oculus Touch Interaction Profile is supported right now.",
                checkPredicate = () =>
                {
                    var settings = OpenXRSettings.GetSettingsForBuildTargetGroup(targetGroup);
                    if (null == settings)
                        return false;

                    bool touchFeatureEnabled = false;
                    bool otherInteractionFeatureEnabled = false;
                    foreach (var feature in settings.GetFeatures<OpenXRInteractionFeature>())
                    {
                        if (feature.enabled)
                        {
                            if (feature is OculusTouchControllerProfile)
                                touchFeatureEnabled = true;
                            else
                                otherInteractionFeatureEnabled = true;
                        }
                    }
                    return touchFeatureEnabled && !otherInteractionFeatureEnabled;
                },
                fixIt = () =>
                {
                    var settings = OpenXRSettings.GetSettingsForBuildTargetGroup(targetGroup);
                    if (null == settings)
                        return;

                    foreach (var feature in settings.GetFeatures<OpenXRInteractionFeature>())
                    {
                        feature.enabled = (feature is OculusTouchControllerProfile);
                    }
                },
                error = true,
            });
        }
#endif
    }
}
