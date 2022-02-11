#ifndef OPENXR_REFLECTION_H_
#define OPENXR_REFLECTION_H_ 1

/*
** Copyright (c) 2017-2021, The Khronos Group Inc.
**
** SPDX-License-Identifier: Apache-2.0 OR MIT
*/

/*
** This header is generated from the Khronos OpenXR XML API Registry.
**
*/

// #include "openxr.h"

/*
This file contains expansion macros (X Macros) for OpenXR enumerations and structures.
Example of how to use expansion macros to make an enum-to-string function:

#define XR_ENUM_CASE_STR(name, val) case name: return #name;
#define XR_ENUM_STR(enumType)                         \
    constexpr const char* XrEnumStr(enumType e) {     \
        switch (e) {                                  \
            XR_LIST_ENUM_##enumType(XR_ENUM_CASE_STR) \
            default: return "Unknown";                \
        }                                             \
    }                                                 \

XR_ENUM_STR(XrResult);
*/

#define XR_LIST_HANDLES(_) \
    _(XrInstance) \
    _(XrSession) \
    _(XrSpace) \
    _(XrAction) \
    _(XrSwapchain) \
    _(XrActionSet) \
    _(XrDebugUtilsMessengerEXT) \
    _(XrSpatialAnchorMSFT) \
    _(XrHandTrackerEXT) \
    _(XrSceneObserverMSFT) \
    _(XrSceneMSFT) \


#define XR_LIST_ENUM_XrResult(_) \
    _(XR_SUCCESS, 0) \
    _(XR_TIMEOUT_EXPIRED, 1) \
    _(XR_SESSION_LOSS_PENDING, 3) \
    _(XR_EVENT_UNAVAILABLE, 4) \
    _(XR_SPACE_BOUNDS_UNAVAILABLE, 7) \
    _(XR_SESSION_NOT_FOCUSED, 8) \
    _(XR_FRAME_DISCARDED, 9) \
    _(XR_ERROR_VALIDATION_FAILURE, -1) \
    _(XR_ERROR_RUNTIME_FAILURE, -2) \
    _(XR_ERROR_OUT_OF_MEMORY, -3) \
    _(XR_ERROR_API_VERSION_UNSUPPORTED, -4) \
    _(XR_ERROR_INITIALIZATION_FAILED, -6) \
    _(XR_ERROR_FUNCTION_UNSUPPORTED, -7) \
    _(XR_ERROR_FEATURE_UNSUPPORTED, -8) \
    _(XR_ERROR_EXTENSION_NOT_PRESENT, -9) \
    _(XR_ERROR_LIMIT_REACHED, -10) \
    _(XR_ERROR_SIZE_INSUFFICIENT, -11) \
    _(XR_ERROR_HANDLE_INVALID, -12) \
    _(XR_ERROR_INSTANCE_LOST, -13) \
    _(XR_ERROR_SESSION_RUNNING, -14) \
    _(XR_ERROR_SESSION_NOT_RUNNING, -16) \
    _(XR_ERROR_SESSION_LOST, -17) \
    _(XR_ERROR_SYSTEM_INVALID, -18) \
    _(XR_ERROR_PATH_INVALID, -19) \
    _(XR_ERROR_PATH_COUNT_EXCEEDED, -20) \
    _(XR_ERROR_PATH_FORMAT_INVALID, -21) \
    _(XR_ERROR_PATH_UNSUPPORTED, -22) \
    _(XR_ERROR_LAYER_INVALID, -23) \
    _(XR_ERROR_LAYER_LIMIT_EXCEEDED, -24) \
    _(XR_ERROR_SWAPCHAIN_RECT_INVALID, -25) \
    _(XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED, -26) \
    _(XR_ERROR_ACTION_TYPE_MISMATCH, -27) \
    _(XR_ERROR_SESSION_NOT_READY, -28) \
    _(XR_ERROR_SESSION_NOT_STOPPING, -29) \
    _(XR_ERROR_TIME_INVALID, -30) \
    _(XR_ERROR_REFERENCE_SPACE_UNSUPPORTED, -31) \
    _(XR_ERROR_FILE_ACCESS_ERROR, -32) \
    _(XR_ERROR_FILE_CONTENTS_INVALID, -33) \
    _(XR_ERROR_FORM_FACTOR_UNSUPPORTED, -34) \
    _(XR_ERROR_FORM_FACTOR_UNAVAILABLE, -35) \
    _(XR_ERROR_API_LAYER_NOT_PRESENT, -36) \
    _(XR_ERROR_CALL_ORDER_INVALID, -37) \
    _(XR_ERROR_GRAPHICS_DEVICE_INVALID, -38) \
    _(XR_ERROR_POSE_INVALID, -39) \
    _(XR_ERROR_INDEX_OUT_OF_RANGE, -40) \
    _(XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED, -41) \
    _(XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED, -42) \
    _(XR_ERROR_NAME_DUPLICATED, -44) \
    _(XR_ERROR_NAME_INVALID, -45) \
    _(XR_ERROR_ACTIONSET_NOT_ATTACHED, -46) \
    _(XR_ERROR_ACTIONSETS_ALREADY_ATTACHED, -47) \
    _(XR_ERROR_LOCALIZED_NAME_DUPLICATED, -48) \
    _(XR_ERROR_LOCALIZED_NAME_INVALID, -49) \
    _(XR_ERROR_GRAPHICS_REQUIREMENTS_CALL_MISSING, -50) \
    _(XR_ERROR_RUNTIME_UNAVAILABLE, -51) \
    _(XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR, -1000003000) \
    _(XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR, -1000003001) \
    _(XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT, -1000039001) \
    _(XR_ERROR_SECONDARY_VIEW_CONFIGURATION_TYPE_NOT_ENABLED_MSFT, -1000053000) \
    _(XR_ERROR_CONTROLLER_MODEL_KEY_INVALID_MSFT, -1000055000) \
    _(XR_ERROR_REPROJECTION_MODE_UNSUPPORTED_MSFT, -1000066000) \
    _(XR_ERROR_COMPUTE_NEW_SCENE_NOT_COMPLETED_MSFT, -1000097000) \
    _(XR_ERROR_SCENE_COMPONENT_ID_INVALID_MSFT, -1000097001) \
    _(XR_ERROR_SCENE_COMPONENT_TYPE_MISMATCH_MSFT, -1000097002) \
    _(XR_ERROR_SCENE_MESH_BUFFER_ID_INVALID_MSFT, -1000097003) \
    _(XR_ERROR_SCENE_COMPUTE_FEATURE_INCOMPATIBLE_MSFT, -1000097004) \
    _(XR_ERROR_SCENE_COMPUTE_CONSISTENCY_MISMATCH_MSFT, -1000097005) \
    _(XR_ERROR_DISPLAY_REFRESH_RATE_UNSUPPORTED_FB, -1000101000) \
    _(XR_ERROR_COLOR_SPACE_UNSUPPORTED_FB, -1000108000) \
    _(XR_RESULT_MAX_ENUM, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrStructureType(_) \
    _(XR_TYPE_UNKNOWN, 0) \
    _(XR_TYPE_API_LAYER_PROPERTIES, 1) \
    _(XR_TYPE_EXTENSION_PROPERTIES, 2) \
    _(XR_TYPE_INSTANCE_CREATE_INFO, 3) \
    _(XR_TYPE_SYSTEM_GET_INFO, 4) \
    _(XR_TYPE_SYSTEM_PROPERTIES, 5) \
    _(XR_TYPE_VIEW_LOCATE_INFO, 6) \
    _(XR_TYPE_VIEW, 7) \
    _(XR_TYPE_SESSION_CREATE_INFO, 8) \
    _(XR_TYPE_SWAPCHAIN_CREATE_INFO, 9) \
    _(XR_TYPE_SESSION_BEGIN_INFO, 10) \
    _(XR_TYPE_VIEW_STATE, 11) \
    _(XR_TYPE_FRAME_END_INFO, 12) \
    _(XR_TYPE_HAPTIC_VIBRATION, 13) \
    _(XR_TYPE_EVENT_DATA_BUFFER, 16) \
    _(XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING, 17) \
    _(XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED, 18) \
    _(XR_TYPE_ACTION_STATE_BOOLEAN, 23) \
    _(XR_TYPE_ACTION_STATE_FLOAT, 24) \
    _(XR_TYPE_ACTION_STATE_VECTOR2F, 25) \
    _(XR_TYPE_ACTION_STATE_POSE, 27) \
    _(XR_TYPE_ACTION_SET_CREATE_INFO, 28) \
    _(XR_TYPE_ACTION_CREATE_INFO, 29) \
    _(XR_TYPE_INSTANCE_PROPERTIES, 32) \
    _(XR_TYPE_FRAME_WAIT_INFO, 33) \
    _(XR_TYPE_COMPOSITION_LAYER_PROJECTION, 35) \
    _(XR_TYPE_COMPOSITION_LAYER_QUAD, 36) \
    _(XR_TYPE_REFERENCE_SPACE_CREATE_INFO, 37) \
    _(XR_TYPE_ACTION_SPACE_CREATE_INFO, 38) \
    _(XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING, 40) \
    _(XR_TYPE_VIEW_CONFIGURATION_VIEW, 41) \
    _(XR_TYPE_SPACE_LOCATION, 42) \
    _(XR_TYPE_SPACE_VELOCITY, 43) \
    _(XR_TYPE_FRAME_STATE, 44) \
    _(XR_TYPE_VIEW_CONFIGURATION_PROPERTIES, 45) \
    _(XR_TYPE_FRAME_BEGIN_INFO, 46) \
    _(XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW, 48) \
    _(XR_TYPE_EVENT_DATA_EVENTS_LOST, 49) \
    _(XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING, 51) \
    _(XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED, 52) \
    _(XR_TYPE_INTERACTION_PROFILE_STATE, 53) \
    _(XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO, 55) \
    _(XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO, 56) \
    _(XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO, 57) \
    _(XR_TYPE_ACTION_STATE_GET_INFO, 58) \
    _(XR_TYPE_HAPTIC_ACTION_INFO, 59) \
    _(XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO, 60) \
    _(XR_TYPE_ACTIONS_SYNC_INFO, 61) \
    _(XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO, 62) \
    _(XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO, 63) \
    _(XR_TYPE_COMPOSITION_LAYER_CUBE_KHR, 1000006000) \
    _(XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR, 1000008000) \
    _(XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR, 1000010000) \
    _(XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR, 1000014000) \
    _(XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT, 1000015000) \
    _(XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR, 1000017000) \
    _(XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR, 1000018000) \
    _(XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT, 1000019000) \
    _(XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT, 1000019001) \
    _(XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT, 1000019002) \
    _(XR_TYPE_DEBUG_UTILS_LABEL_EXT, 1000019003) \
    _(XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR, 1000023000) \
    _(XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR, 1000023001) \
    _(XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR, 1000023002) \
    _(XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR, 1000023003) \
    _(XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR, 1000023004) \
    _(XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR, 1000023005) \
    _(XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR, 1000024001) \
    _(XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR, 1000024002) \
    _(XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR, 1000024003) \
    _(XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR, 1000025000) \
    _(XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR, 1000025001) \
    _(XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR, 1000025002) \
    _(XR_TYPE_GRAPHICS_BINDING_D3D11_KHR, 1000027000) \
    _(XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR, 1000027001) \
    _(XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR, 1000027002) \
    _(XR_TYPE_GRAPHICS_BINDING_D3D12_KHR, 1000028000) \
    _(XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR, 1000028001) \
    _(XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR, 1000028002) \
    _(XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT, 1000030000) \
    _(XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT, 1000030001) \
    _(XR_TYPE_VISIBILITY_MASK_KHR, 1000031000) \
    _(XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR, 1000031001) \
    _(XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX, 1000033000) \
    _(XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX, 1000033003) \
    _(XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR, 1000034000) \
    _(XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT, 1000039000) \
    _(XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT, 1000039001) \
    _(XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT, 1000046000) \
    _(XR_TYPE_GRAPHICS_BINDING_EGL_MNDX, 1000048004) \
    _(XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT, 1000049000) \
    _(XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT, 1000051000) \
    _(XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT, 1000051001) \
    _(XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT, 1000051002) \
    _(XR_TYPE_HAND_JOINT_LOCATIONS_EXT, 1000051003) \
    _(XR_TYPE_HAND_JOINT_VELOCITIES_EXT, 1000051004) \
    _(XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT, 1000052000) \
    _(XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT, 1000052001) \
    _(XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT, 1000052002) \
    _(XR_TYPE_HAND_MESH_MSFT, 1000052003) \
    _(XR_TYPE_HAND_POSE_TYPE_INFO_MSFT, 1000052004) \
    _(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT, 1000053000) \
    _(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT, 1000053001) \
    _(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT, 1000053002) \
    _(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT, 1000053003) \
    _(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT, 1000053004) \
    _(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT, 1000053005) \
    _(XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT, 1000055000) \
    _(XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT, 1000055001) \
    _(XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT, 1000055002) \
    _(XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT, 1000055003) \
    _(XR_TYPE_CONTROLLER_MODEL_STATE_MSFT, 1000055004) \
    _(XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC, 1000059000) \
    _(XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT, 1000063000) \
    _(XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT, 1000066000) \
    _(XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT, 1000066001) \
    _(XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB, 1000070000) \
    _(XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE, 1000079000) \
    _(XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT, 1000080000) \
    _(XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR, 1000089000) \
    _(XR_TYPE_VULKAN_INSTANCE_CREATE_INFO_KHR, 1000090000) \
    _(XR_TYPE_VULKAN_DEVICE_CREATE_INFO_KHR, 1000090001) \
    _(XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR, 1000090003) \
    _(XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR, 1000091000) \
    _(XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT, 1000097000) \
    _(XR_TYPE_SCENE_CREATE_INFO_MSFT, 1000097001) \
    _(XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT, 1000097002) \
    _(XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT, 1000097003) \
    _(XR_TYPE_SCENE_COMPONENTS_MSFT, 1000097004) \
    _(XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT, 1000097005) \
    _(XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT, 1000097006) \
    _(XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT, 1000097007) \
    _(XR_TYPE_SCENE_OBJECTS_MSFT, 1000097008) \
    _(XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT, 1000097009) \
    _(XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT, 1000097010) \
    _(XR_TYPE_SCENE_PLANES_MSFT, 1000097011) \
    _(XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT, 1000097012) \
    _(XR_TYPE_SCENE_MESHES_MSFT, 1000097013) \
    _(XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT, 1000097014) \
    _(XR_TYPE_SCENE_MESH_BUFFERS_MSFT, 1000097015) \
    _(XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT, 1000097016) \
    _(XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT, 1000097017) \
    _(XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT, 1000097018) \
    _(XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT, 1000098000) \
    _(XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT, 1000098001) \
    _(XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB, 1000101000) \
    _(XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB, 1000108000) \
    _(XR_TYPE_BINDING_MODIFICATIONS_KHR, 1000120000) \
    _(XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO, 1000121000) \
    _(XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO, 1000121001) \
    _(XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO, 1000121002) \
    _(XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO, 1000122000) \
    _(XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB, 1000161000) \
    _(XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB, 1000162000) \
    _(XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB, 1000163000) \
    _(XR_STRUCTURE_TYPE_MAX_ENUM, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrFormFactor(_) \
    _(XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY, 1) \
    _(XR_FORM_FACTOR_HANDHELD_DISPLAY, 2) \
    _(XR_FORM_FACTOR_MAX_ENUM, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrViewConfigurationType(_) \
    _(XR_VIEW_CONFIGURATION_TYPE_PRIMARY_MONO, 1) \
    _(XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO, 2) \
    _(XR_VIEW_CONFIGURATION_TYPE_PRIMARY_QUAD_VARJO, 1000037000) \
    _(XR_VIEW_CONFIGURATION_TYPE_SECONDARY_MONO_FIRST_PERSON_OBSERVER_MSFT, 1000054000) \
    _(XR_VIEW_CONFIGURATION_TYPE_MAX_ENUM, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrEnvironmentBlendMode(_) \
    _(XR_ENVIRONMENT_BLEND_MODE_OPAQUE, 1) \
    _(XR_ENVIRONMENT_BLEND_MODE_ADDITIVE, 2) \
    _(XR_ENVIRONMENT_BLEND_MODE_ALPHA_BLEND, 3) \
    _(XR_ENVIRONMENT_BLEND_MODE_MAX_ENUM, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrReferenceSpaceType(_) \
    _(XR_REFERENCE_SPACE_TYPE_VIEW, 1) \
    _(XR_REFERENCE_SPACE_TYPE_LOCAL, 2) \
    _(XR_REFERENCE_SPACE_TYPE_STAGE, 3) \
    _(XR_REFERENCE_SPACE_TYPE_UNBOUNDED_MSFT, 1000038000) \
    _(XR_REFERENCE_SPACE_TYPE_COMBINED_EYE_VARJO, 1000121000) \
    _(XR_REFERENCE_SPACE_TYPE_MAX_ENUM, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrActionType(_) \
    _(XR_ACTION_TYPE_BOOLEAN_INPUT, 1) \
    _(XR_ACTION_TYPE_FLOAT_INPUT, 2) \
    _(XR_ACTION_TYPE_VECTOR2F_INPUT, 3) \
    _(XR_ACTION_TYPE_POSE_INPUT, 4) \
    _(XR_ACTION_TYPE_VIBRATION_OUTPUT, 100) \
    _(XR_ACTION_TYPE_MAX_ENUM, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrEyeVisibility(_) \
    _(XR_EYE_VISIBILITY_BOTH, 0) \
    _(XR_EYE_VISIBILITY_LEFT, 1) \
    _(XR_EYE_VISIBILITY_RIGHT, 2) \
    _(XR_EYE_VISIBILITY_MAX_ENUM, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrSessionState(_) \
    _(XR_SESSION_STATE_UNKNOWN, 0) \
    _(XR_SESSION_STATE_IDLE, 1) \
    _(XR_SESSION_STATE_READY, 2) \
    _(XR_SESSION_STATE_SYNCHRONIZED, 3) \
    _(XR_SESSION_STATE_VISIBLE, 4) \
    _(XR_SESSION_STATE_FOCUSED, 5) \
    _(XR_SESSION_STATE_STOPPING, 6) \
    _(XR_SESSION_STATE_LOSS_PENDING, 7) \
    _(XR_SESSION_STATE_EXITING, 8) \
    _(XR_SESSION_STATE_MAX_ENUM, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrObjectType(_) \
    _(XR_OBJECT_TYPE_UNKNOWN, 0) \
    _(XR_OBJECT_TYPE_INSTANCE, 1) \
    _(XR_OBJECT_TYPE_SESSION, 2) \
    _(XR_OBJECT_TYPE_SWAPCHAIN, 3) \
    _(XR_OBJECT_TYPE_SPACE, 4) \
    _(XR_OBJECT_TYPE_ACTION_SET, 5) \
    _(XR_OBJECT_TYPE_ACTION, 6) \
    _(XR_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT, 1000019000) \
    _(XR_OBJECT_TYPE_SPATIAL_ANCHOR_MSFT, 1000039000) \
    _(XR_OBJECT_TYPE_HAND_TRACKER_EXT, 1000051000) \
    _(XR_OBJECT_TYPE_SCENE_OBSERVER_MSFT, 1000097000) \
    _(XR_OBJECT_TYPE_SCENE_MSFT, 1000097001) \
    _(XR_OBJECT_TYPE_MAX_ENUM, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrAndroidThreadTypeKHR(_) \
    _(XR_ANDROID_THREAD_TYPE_APPLICATION_MAIN_KHR, 1) \
    _(XR_ANDROID_THREAD_TYPE_APPLICATION_WORKER_KHR, 2) \
    _(XR_ANDROID_THREAD_TYPE_RENDERER_MAIN_KHR, 3) \
    _(XR_ANDROID_THREAD_TYPE_RENDERER_WORKER_KHR, 4) \
    _(XR_ANDROID_THREAD_TYPE_MAX_ENUM_KHR, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrVisibilityMaskTypeKHR(_) \
    _(XR_VISIBILITY_MASK_TYPE_HIDDEN_TRIANGLE_MESH_KHR, 1) \
    _(XR_VISIBILITY_MASK_TYPE_VISIBLE_TRIANGLE_MESH_KHR, 2) \
    _(XR_VISIBILITY_MASK_TYPE_LINE_LOOP_KHR, 3) \
    _(XR_VISIBILITY_MASK_TYPE_MAX_ENUM_KHR, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrPerfSettingsDomainEXT(_) \
    _(XR_PERF_SETTINGS_DOMAIN_CPU_EXT, 1) \
    _(XR_PERF_SETTINGS_DOMAIN_GPU_EXT, 2) \
    _(XR_PERF_SETTINGS_DOMAIN_MAX_ENUM_EXT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrPerfSettingsSubDomainEXT(_) \
    _(XR_PERF_SETTINGS_SUB_DOMAIN_COMPOSITING_EXT, 1) \
    _(XR_PERF_SETTINGS_SUB_DOMAIN_RENDERING_EXT, 2) \
    _(XR_PERF_SETTINGS_SUB_DOMAIN_THERMAL_EXT, 3) \
    _(XR_PERF_SETTINGS_SUB_DOMAIN_MAX_ENUM_EXT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrPerfSettingsLevelEXT(_) \
    _(XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT, 0) \
    _(XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT, 25) \
    _(XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT, 50) \
    _(XR_PERF_SETTINGS_LEVEL_BOOST_EXT, 75) \
    _(XR_PERF_SETTINGS_LEVEL_MAX_ENUM_EXT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrPerfSettingsNotificationLevelEXT(_) \
    _(XR_PERF_SETTINGS_NOTIF_LEVEL_NORMAL_EXT, 0) \
    _(XR_PERF_SETTINGS_NOTIF_LEVEL_WARNING_EXT, 25) \
    _(XR_PERF_SETTINGS_NOTIF_LEVEL_IMPAIRED_EXT, 75) \
    _(XR_PERF_SETTINGS_NOTIFICATION_LEVEL_MAX_ENUM_EXT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrSpatialGraphNodeTypeMSFT(_) \
    _(XR_SPATIAL_GRAPH_NODE_TYPE_STATIC_MSFT, 1) \
    _(XR_SPATIAL_GRAPH_NODE_TYPE_DYNAMIC_MSFT, 2) \
    _(XR_SPATIAL_GRAPH_NODE_TYPE_MAX_ENUM_MSFT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrHandEXT(_) \
    _(XR_HAND_LEFT_EXT, 1) \
    _(XR_HAND_RIGHT_EXT, 2) \
    _(XR_HAND_MAX_ENUM_EXT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrHandJointEXT(_) \
    _(XR_HAND_JOINT_PALM_EXT, 0) \
    _(XR_HAND_JOINT_WRIST_EXT, 1) \
    _(XR_HAND_JOINT_THUMB_METACARPAL_EXT, 2) \
    _(XR_HAND_JOINT_THUMB_PROXIMAL_EXT, 3) \
    _(XR_HAND_JOINT_THUMB_DISTAL_EXT, 4) \
    _(XR_HAND_JOINT_THUMB_TIP_EXT, 5) \
    _(XR_HAND_JOINT_INDEX_METACARPAL_EXT, 6) \
    _(XR_HAND_JOINT_INDEX_PROXIMAL_EXT, 7) \
    _(XR_HAND_JOINT_INDEX_INTERMEDIATE_EXT, 8) \
    _(XR_HAND_JOINT_INDEX_DISTAL_EXT, 9) \
    _(XR_HAND_JOINT_INDEX_TIP_EXT, 10) \
    _(XR_HAND_JOINT_MIDDLE_METACARPAL_EXT, 11) \
    _(XR_HAND_JOINT_MIDDLE_PROXIMAL_EXT, 12) \
    _(XR_HAND_JOINT_MIDDLE_INTERMEDIATE_EXT, 13) \
    _(XR_HAND_JOINT_MIDDLE_DISTAL_EXT, 14) \
    _(XR_HAND_JOINT_MIDDLE_TIP_EXT, 15) \
    _(XR_HAND_JOINT_RING_METACARPAL_EXT, 16) \
    _(XR_HAND_JOINT_RING_PROXIMAL_EXT, 17) \
    _(XR_HAND_JOINT_RING_INTERMEDIATE_EXT, 18) \
    _(XR_HAND_JOINT_RING_DISTAL_EXT, 19) \
    _(XR_HAND_JOINT_RING_TIP_EXT, 20) \
    _(XR_HAND_JOINT_LITTLE_METACARPAL_EXT, 21) \
    _(XR_HAND_JOINT_LITTLE_PROXIMAL_EXT, 22) \
    _(XR_HAND_JOINT_LITTLE_INTERMEDIATE_EXT, 23) \
    _(XR_HAND_JOINT_LITTLE_DISTAL_EXT, 24) \
    _(XR_HAND_JOINT_LITTLE_TIP_EXT, 25) \
    _(XR_HAND_JOINT_MAX_ENUM_EXT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrHandJointSetEXT(_) \
    _(XR_HAND_JOINT_SET_DEFAULT_EXT, 0) \
    _(XR_HAND_JOINT_SET_MAX_ENUM_EXT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrHandPoseTypeMSFT(_) \
    _(XR_HAND_POSE_TYPE_TRACKED_MSFT, 0) \
    _(XR_HAND_POSE_TYPE_REFERENCE_OPEN_PALM_MSFT, 1) \
    _(XR_HAND_POSE_TYPE_MAX_ENUM_MSFT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrReprojectionModeMSFT(_) \
    _(XR_REPROJECTION_MODE_DEPTH_MSFT, 1) \
    _(XR_REPROJECTION_MODE_PLANAR_FROM_DEPTH_MSFT, 2) \
    _(XR_REPROJECTION_MODE_PLANAR_MANUAL_MSFT, 3) \
    _(XR_REPROJECTION_MODE_ORIENTATION_ONLY_MSFT, 4) \
    _(XR_REPROJECTION_MODE_MAX_ENUM_MSFT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrHandJointsMotionRangeEXT(_) \
    _(XR_HAND_JOINTS_MOTION_RANGE_UNOBSTRUCTED_EXT, 1) \
    _(XR_HAND_JOINTS_MOTION_RANGE_CONFORMING_TO_CONTROLLER_EXT, 2) \
    _(XR_HAND_JOINTS_MOTION_RANGE_MAX_ENUM_EXT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrSceneComputeFeatureMSFT(_) \
    _(XR_SCENE_COMPUTE_FEATURE_PLANE_MSFT, 1) \
    _(XR_SCENE_COMPUTE_FEATURE_PLANE_MESH_MSFT, 2) \
    _(XR_SCENE_COMPUTE_FEATURE_VISUAL_MESH_MSFT, 3) \
    _(XR_SCENE_COMPUTE_FEATURE_COLLIDER_MESH_MSFT, 4) \
    _(XR_SCENE_COMPUTE_FEATURE_SERIALIZE_SCENE_MSFT, 1000098000) \
    _(XR_SCENE_COMPUTE_FEATURE_MAX_ENUM_MSFT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrSceneComputeConsistencyMSFT(_) \
    _(XR_SCENE_COMPUTE_CONSISTENCY_SNAPSHOT_COMPLETE_MSFT, 1) \
    _(XR_SCENE_COMPUTE_CONSISTENCY_SNAPSHOT_INCOMPLETE_FAST_MSFT, 2) \
    _(XR_SCENE_COMPUTE_CONSISTENCY_OCCLUSION_OPTIMIZED_MSFT, 3) \
    _(XR_SCENE_COMPUTE_CONSISTENCY_MAX_ENUM_MSFT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrMeshComputeLodMSFT(_) \
    _(XR_MESH_COMPUTE_LOD_COARSE_MSFT, 1) \
    _(XR_MESH_COMPUTE_LOD_MEDIUM_MSFT, 2) \
    _(XR_MESH_COMPUTE_LOD_FINE_MSFT, 3) \
    _(XR_MESH_COMPUTE_LOD_UNLIMITED_MSFT, 4) \
    _(XR_MESH_COMPUTE_LOD_MAX_ENUM_MSFT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrSceneComponentTypeMSFT(_) \
    _(XR_SCENE_COMPONENT_TYPE_INVALID_MSFT, -1) \
    _(XR_SCENE_COMPONENT_TYPE_OBJECT_MSFT, 1) \
    _(XR_SCENE_COMPONENT_TYPE_PLANE_MSFT, 2) \
    _(XR_SCENE_COMPONENT_TYPE_VISUAL_MESH_MSFT, 3) \
    _(XR_SCENE_COMPONENT_TYPE_COLLIDER_MESH_MSFT, 4) \
    _(XR_SCENE_COMPONENT_TYPE_SERIALIZED_SCENE_FRAGMENT_MSFT, 1000098000) \
    _(XR_SCENE_COMPONENT_TYPE_MAX_ENUM_MSFT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrSceneObjectTypeMSFT(_) \
    _(XR_SCENE_OBJECT_TYPE_UNCATEGORIZED_MSFT, -1) \
    _(XR_SCENE_OBJECT_TYPE_BACKGROUND_MSFT, 1) \
    _(XR_SCENE_OBJECT_TYPE_WALL_MSFT, 2) \
    _(XR_SCENE_OBJECT_TYPE_FLOOR_MSFT, 3) \
    _(XR_SCENE_OBJECT_TYPE_CEILING_MSFT, 4) \
    _(XR_SCENE_OBJECT_TYPE_PLATFORM_MSFT, 5) \
    _(XR_SCENE_OBJECT_TYPE_INFERRED_MSFT, 6) \
    _(XR_SCENE_OBJECT_TYPE_MAX_ENUM_MSFT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrScenePlaneAlignmentTypeMSFT(_) \
    _(XR_SCENE_PLANE_ALIGNMENT_TYPE_NON_ORTHOGONAL_MSFT, 0) \
    _(XR_SCENE_PLANE_ALIGNMENT_TYPE_HORIZONTAL_MSFT, 1) \
    _(XR_SCENE_PLANE_ALIGNMENT_TYPE_VERTICAL_MSFT, 2) \
    _(XR_SCENE_PLANE_ALIGNMENT_TYPE_MAX_ENUM_MSFT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrSceneComputeStateMSFT(_) \
    _(XR_SCENE_COMPUTE_STATE_NONE_MSFT, 0) \
    _(XR_SCENE_COMPUTE_STATE_UPDATING_MSFT, 1) \
    _(XR_SCENE_COMPUTE_STATE_COMPLETED_MSFT, 2) \
    _(XR_SCENE_COMPUTE_STATE_COMPLETED_WITH_ERROR_MSFT, 3) \
    _(XR_SCENE_COMPUTE_STATE_MAX_ENUM_MSFT, 0x7FFFFFFF)

#define XR_LIST_ENUM_XrColorSpaceFB(_) \
    _(XR_COLOR_SPACE_UNMANAGED_FB, 0) \
    _(XR_COLOR_SPACE_REC2020_FB, 1) \
    _(XR_COLOR_SPACE_REC709_FB, 2) \
    _(XR_COLOR_SPACE_RIFT_CV1_FB, 3) \
    _(XR_COLOR_SPACE_RIFT_S_FB, 4) \
    _(XR_COLOR_SPACE_QUEST_FB, 5) \
    _(XR_COLOR_SPACE_P3_FB, 6) \
    _(XR_COLOR_SPACE_ADOBE_RGB_FB, 7) \
    _(XR_COLOR_SPACE_MAX_ENUM_FB, 0x7FFFFFFF)



#define XR_LIST_ENUM_TYPES_CORE(_) \
    _(XrResult) \
    _(XrStructureType) \
    _(XrFormFactor) \
    _(XrViewConfigurationType) \
    _(XrEnvironmentBlendMode) \
    _(XrReferenceSpaceType) \
    _(XrActionType) \
    _(XrEyeVisibility) \
    _(XrSessionState) \
    _(XrObjectType) \
    _(XrVisibilityMaskTypeKHR) \
    _(XrPerfSettingsDomainEXT) \
    _(XrPerfSettingsSubDomainEXT) \
    _(XrPerfSettingsLevelEXT) \
    _(XrPerfSettingsNotificationLevelEXT) \
    _(XrSpatialGraphNodeTypeMSFT) \
    _(XrHandEXT) \
    _(XrHandJointEXT) \
    _(XrHandJointSetEXT) \
    _(XrHandPoseTypeMSFT) \
    _(XrReprojectionModeMSFT) \
    _(XrHandJointsMotionRangeEXT) \
    _(XrSceneComputeFeatureMSFT) \
    _(XrSceneComputeConsistencyMSFT) \
    _(XrMeshComputeLodMSFT) \
    _(XrSceneComponentTypeMSFT) \
    _(XrSceneObjectTypeMSFT) \
    _(XrScenePlaneAlignmentTypeMSFT) \
    _(XrSceneComputeStateMSFT) \
    _(XrColorSpaceFB) \




#if defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_ENUM_TYPES_XR_USE_PLATFORM_ANDROID(_) \
    _(XrAndroidThreadTypeKHR) \


#else
#define XR_LIST_ENUM_TYPES_XR_USE_PLATFORM_ANDROID(_)
#endif

#define XR_LIST_ENUM_TYPES(_) \
    XR_LIST_ENUM_TYPES_CORE(_) \
    XR_LIST_ENUM_TYPES_XR_USE_PLATFORM_ANDROID(_) \


#define XR_LIST_BITS_XrInstanceCreateFlags(_)

#define XR_LIST_BITS_XrSessionCreateFlags(_)

#define XR_LIST_BITS_XrSpaceVelocityFlags(_) \
    _(XR_SPACE_VELOCITY_LINEAR_VALID_BIT, 0x00000001) \
    _(XR_SPACE_VELOCITY_ANGULAR_VALID_BIT, 0x00000002) \

#define XR_LIST_BITS_XrSpaceLocationFlags(_) \
    _(XR_SPACE_LOCATION_ORIENTATION_VALID_BIT, 0x00000001) \
    _(XR_SPACE_LOCATION_POSITION_VALID_BIT, 0x00000002) \
    _(XR_SPACE_LOCATION_ORIENTATION_TRACKED_BIT, 0x00000004) \
    _(XR_SPACE_LOCATION_POSITION_TRACKED_BIT, 0x00000008) \

#define XR_LIST_BITS_XrSwapchainCreateFlags(_) \
    _(XR_SWAPCHAIN_CREATE_PROTECTED_CONTENT_BIT, 0x00000001) \
    _(XR_SWAPCHAIN_CREATE_STATIC_IMAGE_BIT, 0x00000002) \

#define XR_LIST_BITS_XrSwapchainUsageFlags(_) \
    _(XR_SWAPCHAIN_USAGE_COLOR_ATTACHMENT_BIT, 0x00000001) \
    _(XR_SWAPCHAIN_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, 0x00000002) \
    _(XR_SWAPCHAIN_USAGE_UNORDERED_ACCESS_BIT, 0x00000004) \
    _(XR_SWAPCHAIN_USAGE_TRANSFER_SRC_BIT, 0x00000008) \
    _(XR_SWAPCHAIN_USAGE_TRANSFER_DST_BIT, 0x00000010) \
    _(XR_SWAPCHAIN_USAGE_SAMPLED_BIT, 0x00000020) \
    _(XR_SWAPCHAIN_USAGE_MUTABLE_FORMAT_BIT, 0x00000040) \
    _(XR_SWAPCHAIN_USAGE_INPUT_ATTACHMENT_BIT_MND, 0x00000080) \

#define XR_LIST_BITS_XrCompositionLayerFlags(_) \
    _(XR_COMPOSITION_LAYER_CORRECT_CHROMATIC_ABERRATION_BIT, 0x00000001) \
    _(XR_COMPOSITION_LAYER_BLEND_TEXTURE_SOURCE_ALPHA_BIT, 0x00000002) \
    _(XR_COMPOSITION_LAYER_UNPREMULTIPLIED_ALPHA_BIT, 0x00000004) \

#define XR_LIST_BITS_XrViewStateFlags(_) \
    _(XR_VIEW_STATE_ORIENTATION_VALID_BIT, 0x00000001) \
    _(XR_VIEW_STATE_POSITION_VALID_BIT, 0x00000002) \
    _(XR_VIEW_STATE_ORIENTATION_TRACKED_BIT, 0x00000004) \
    _(XR_VIEW_STATE_POSITION_TRACKED_BIT, 0x00000008) \

#define XR_LIST_BITS_XrInputSourceLocalizedNameFlags(_) \
    _(XR_INPUT_SOURCE_LOCALIZED_NAME_USER_PATH_BIT, 0x00000001) \
    _(XR_INPUT_SOURCE_LOCALIZED_NAME_INTERACTION_PROFILE_BIT, 0x00000002) \
    _(XR_INPUT_SOURCE_LOCALIZED_NAME_COMPONENT_BIT, 0x00000004) \

#define XR_LIST_BITS_XrVulkanInstanceCreateFlagsKHR(_)

#define XR_LIST_BITS_XrVulkanDeviceCreateFlagsKHR(_)

#define XR_LIST_BITS_XrDebugUtilsMessageSeverityFlagsEXT(_) \
    _(XR_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT, 0x00000001) \
    _(XR_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT, 0x00000010) \
    _(XR_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT, 0x00000100) \
    _(XR_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT, 0x00001000) \

#define XR_LIST_BITS_XrDebugUtilsMessageTypeFlagsEXT(_) \
    _(XR_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT, 0x00000001) \
    _(XR_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT, 0x00000002) \
    _(XR_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT, 0x00000004) \
    _(XR_DEBUG_UTILS_MESSAGE_TYPE_CONFORMANCE_BIT_EXT, 0x00000008) \

#define XR_LIST_BITS_XrOverlaySessionCreateFlagsEXTX(_)

#define XR_LIST_BITS_XrOverlayMainSessionFlagsEXTX(_) \
    _(XR_OVERLAY_MAIN_SESSION_ENABLED_COMPOSITION_LAYER_INFO_DEPTH_BIT_EXTX, 0x00000001) \

#define XR_LIST_BITS_XrAndroidSurfaceSwapchainFlagsFB(_) \
    _(XR_ANDROID_SURFACE_SWAPCHAIN_SYNCHRONOUS_BIT_FB, 0x00000001) \
    _(XR_ANDROID_SURFACE_SWAPCHAIN_USE_TIMESTAMPS_BIT_FB, 0x00000002) \

#define XR_LIST_STRUCT_XrApiLayerProperties(_) \
    _(type) \
    _(next) \
    _(layerName) \
    _(specVersion) \
    _(layerVersion) \
    _(description) \

#define XR_LIST_STRUCT_XrExtensionProperties(_) \
    _(type) \
    _(next) \
    _(extensionName) \
    _(extensionVersion) \

#define XR_LIST_STRUCT_XrApplicationInfo(_) \
    _(applicationName) \
    _(applicationVersion) \
    _(engineName) \
    _(engineVersion) \
    _(apiVersion) \

#define XR_LIST_STRUCT_XrInstanceCreateInfo(_) \
    _(type) \
    _(next) \
    _(createFlags) \
    _(applicationInfo) \
    _(enabledApiLayerCount) \
    _(enabledExtensionCount) \

#define XR_LIST_STRUCT_XrInstanceProperties(_) \
    _(type) \
    _(next) \
    _(runtimeVersion) \
    _(runtimeName) \

#define XR_LIST_STRUCT_XrSystemGetInfo(_) \
    _(type) \
    _(next) \
    _(formFactor) \

#define XR_LIST_STRUCT_XrSystemGraphicsProperties(_) \
    _(maxSwapchainImageHeight) \
    _(maxSwapchainImageWidth) \
    _(maxLayerCount) \

#define XR_LIST_STRUCT_XrSystemTrackingProperties(_) \
    _(orientationTracking) \
    _(positionTracking) \

#define XR_LIST_STRUCT_XrSystemProperties(_) \
    _(type) \
    _(next) \
    _(systemId) \
    _(vendorId) \
    _(systemName) \
    _(graphicsProperties) \
    _(trackingProperties) \

#define XR_LIST_STRUCT_XrSessionCreateInfo(_) \
    _(type) \
    _(next) \
    _(createFlags) \
    _(systemId) \

#define XR_LIST_STRUCT_XrVector3f(_) \
    _(x) \
    _(y) \
    _(z) \

#define XR_LIST_STRUCT_XrSpaceVelocity(_) \
    _(type) \
    _(next) \
    _(velocityFlags) \
    _(linearVelocity) \
    _(angularVelocity) \

#define XR_LIST_STRUCT_XrQuaternionf(_) \
    _(x) \
    _(y) \
    _(z) \
    _(w) \

#define XR_LIST_STRUCT_XrPosef(_) \
    _(orientation) \
    _(position) \

#define XR_LIST_STRUCT_XrReferenceSpaceCreateInfo(_) \
    _(type) \
    _(next) \
    _(referenceSpaceType) \
    _(poseInReferenceSpace) \

#define XR_LIST_STRUCT_XrExtent2Df(_) \
    _(width) \
    _(height) \

#define XR_LIST_STRUCT_XrActionSpaceCreateInfo(_) \
    _(type) \
    _(next) \
    _(action) \
    _(subactionPath) \
    _(poseInActionSpace) \

#define XR_LIST_STRUCT_XrSpaceLocation(_) \
    _(type) \
    _(next) \
    _(locationFlags) \
    _(pose) \

#define XR_LIST_STRUCT_XrViewConfigurationProperties(_) \
    _(type) \
    _(next) \
    _(viewConfigurationType) \
    _(fovMutable) \

#define XR_LIST_STRUCT_XrViewConfigurationView(_) \
    _(type) \
    _(next) \
    _(recommendedImageRectWidth) \
    _(maxImageRectWidth) \
    _(recommendedImageRectHeight) \
    _(maxImageRectHeight) \
    _(recommendedSwapchainSampleCount) \
    _(maxSwapchainSampleCount) \

#define XR_LIST_STRUCT_XrSwapchainCreateInfo(_) \
    _(type) \
    _(next) \
    _(createFlags) \
    _(usageFlags) \
    _(format) \
    _(sampleCount) \
    _(width) \
    _(height) \
    _(faceCount) \
    _(arraySize) \
    _(mipCount) \

#define XR_LIST_STRUCT_XrSwapchainImageBaseHeader(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrSwapchainImageAcquireInfo(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrSwapchainImageWaitInfo(_) \
    _(type) \
    _(next) \
    _(timeout) \

#define XR_LIST_STRUCT_XrSwapchainImageReleaseInfo(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrSessionBeginInfo(_) \
    _(type) \
    _(next) \
    _(primaryViewConfigurationType) \

#define XR_LIST_STRUCT_XrFrameWaitInfo(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrFrameState(_) \
    _(type) \
    _(next) \
    _(predictedDisplayTime) \
    _(predictedDisplayPeriod) \
    _(shouldRender) \

#define XR_LIST_STRUCT_XrFrameBeginInfo(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrCompositionLayerBaseHeader(_) \
    _(type) \
    _(next) \
    _(layerFlags) \
    _(space) \

#define XR_LIST_STRUCT_XrFrameEndInfo(_) \
    _(type) \
    _(next) \
    _(displayTime) \
    _(environmentBlendMode) \
    _(layerCount) \

#define XR_LIST_STRUCT_XrViewLocateInfo(_) \
    _(type) \
    _(next) \
    _(viewConfigurationType) \
    _(displayTime) \
    _(space) \

#define XR_LIST_STRUCT_XrViewState(_) \
    _(type) \
    _(next) \
    _(viewStateFlags) \

#define XR_LIST_STRUCT_XrFovf(_) \
    _(angleLeft) \
    _(angleRight) \
    _(angleUp) \
    _(angleDown) \

#define XR_LIST_STRUCT_XrView(_) \
    _(type) \
    _(next) \
    _(pose) \
    _(fov) \

#define XR_LIST_STRUCT_XrActionSetCreateInfo(_) \
    _(type) \
    _(next) \
    _(actionSetName) \
    _(localizedActionSetName) \
    _(priority) \

#define XR_LIST_STRUCT_XrActionCreateInfo(_) \
    _(type) \
    _(next) \
    _(actionName) \
    _(actionType) \
    _(countSubactionPaths) \
    _(localizedActionName) \

#define XR_LIST_STRUCT_XrActionSuggestedBinding(_) \
    _(action) \
    _(binding) \

#define XR_LIST_STRUCT_XrInteractionProfileSuggestedBinding(_) \
    _(type) \
    _(next) \
    _(interactionProfile) \
    _(countSuggestedBindings) \

#define XR_LIST_STRUCT_XrSessionActionSetsAttachInfo(_) \
    _(type) \
    _(next) \
    _(countActionSets) \

#define XR_LIST_STRUCT_XrInteractionProfileState(_) \
    _(type) \
    _(next) \
    _(interactionProfile) \

#define XR_LIST_STRUCT_XrActionStateGetInfo(_) \
    _(type) \
    _(next) \
    _(action) \
    _(subactionPath) \

#define XR_LIST_STRUCT_XrActionStateBoolean(_) \
    _(type) \
    _(next) \
    _(currentState) \
    _(changedSinceLastSync) \
    _(lastChangeTime) \
    _(isActive) \

#define XR_LIST_STRUCT_XrActionStateFloat(_) \
    _(type) \
    _(next) \
    _(currentState) \
    _(changedSinceLastSync) \
    _(lastChangeTime) \
    _(isActive) \

#define XR_LIST_STRUCT_XrVector2f(_) \
    _(x) \
    _(y) \

#define XR_LIST_STRUCT_XrActionStateVector2f(_) \
    _(type) \
    _(next) \
    _(currentState) \
    _(changedSinceLastSync) \
    _(lastChangeTime) \
    _(isActive) \

#define XR_LIST_STRUCT_XrActionStatePose(_) \
    _(type) \
    _(next) \
    _(isActive) \

#define XR_LIST_STRUCT_XrActiveActionSet(_) \
    _(actionSet) \
    _(subactionPath) \

#define XR_LIST_STRUCT_XrActionsSyncInfo(_) \
    _(type) \
    _(next) \
    _(countActiveActionSets) \

#define XR_LIST_STRUCT_XrBoundSourcesForActionEnumerateInfo(_) \
    _(type) \
    _(next) \
    _(action) \

#define XR_LIST_STRUCT_XrInputSourceLocalizedNameGetInfo(_) \
    _(type) \
    _(next) \
    _(sourcePath) \
    _(whichComponents) \

#define XR_LIST_STRUCT_XrHapticActionInfo(_) \
    _(type) \
    _(next) \
    _(action) \
    _(subactionPath) \

#define XR_LIST_STRUCT_XrHapticBaseHeader(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrOffset2Di(_) \
    _(x) \
    _(y) \

#define XR_LIST_STRUCT_XrExtent2Di(_) \
    _(width) \
    _(height) \

#define XR_LIST_STRUCT_XrRect2Di(_) \
    _(offset) \
    _(extent) \

#define XR_LIST_STRUCT_XrSwapchainSubImage(_) \
    _(swapchain) \
    _(imageRect) \
    _(imageArrayIndex) \

#define XR_LIST_STRUCT_XrCompositionLayerProjectionView(_) \
    _(type) \
    _(next) \
    _(pose) \
    _(fov) \
    _(subImage) \

#define XR_LIST_STRUCT_XrCompositionLayerProjection(_) \
    _(type) \
    _(next) \
    _(layerFlags) \
    _(space) \
    _(viewCount) \

#define XR_LIST_STRUCT_XrCompositionLayerQuad(_) \
    _(type) \
    _(next) \
    _(layerFlags) \
    _(space) \
    _(eyeVisibility) \
    _(subImage) \
    _(pose) \
    _(size) \

#define XR_LIST_STRUCT_XrEventDataBaseHeader(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrEventDataEventsLost(_) \
    _(type) \
    _(next) \
    _(lostEventCount) \

#define XR_LIST_STRUCT_XrEventDataInstanceLossPending(_) \
    _(type) \
    _(next) \
    _(lossTime) \

#define XR_LIST_STRUCT_XrEventDataSessionStateChanged(_) \
    _(type) \
    _(next) \
    _(session) \
    _(state) \
    _(time) \

#define XR_LIST_STRUCT_XrEventDataReferenceSpaceChangePending(_) \
    _(type) \
    _(next) \
    _(session) \
    _(referenceSpaceType) \
    _(changeTime) \
    _(poseValid) \
    _(poseInPreviousSpace) \

#define XR_LIST_STRUCT_XrEventDataInteractionProfileChanged(_) \
    _(type) \
    _(next) \
    _(session) \

#define XR_LIST_STRUCT_XrHapticVibration(_) \
    _(type) \
    _(next) \
    _(duration) \
    _(frequency) \
    _(amplitude) \

#define XR_LIST_STRUCT_XrOffset2Df(_) \
    _(x) \
    _(y) \

#define XR_LIST_STRUCT_XrRect2Df(_) \
    _(offset) \
    _(extent) \

#define XR_LIST_STRUCT_XrVector4f(_) \
    _(x) \
    _(y) \
    _(z) \
    _(w) \

#define XR_LIST_STRUCT_XrColor4f(_) \
    _(r) \
    _(g) \
    _(b) \
    _(a) \

#define XR_LIST_STRUCT_XrCompositionLayerCubeKHR(_) \
    _(type) \
    _(next) \
    _(layerFlags) \
    _(space) \
    _(eyeVisibility) \
    _(swapchain) \
    _(imageArrayIndex) \
    _(orientation) \

#define XR_LIST_STRUCT_XrInstanceCreateInfoAndroidKHR(_) \
    _(type) \
    _(next) \
    _(applicationVM) \
    _(applicationActivity) \

#define XR_LIST_STRUCT_XrCompositionLayerDepthInfoKHR(_) \
    _(type) \
    _(next) \
    _(subImage) \
    _(minDepth) \
    _(maxDepth) \
    _(nearZ) \
    _(farZ) \

#define XR_LIST_STRUCT_XrVulkanSwapchainFormatListCreateInfoKHR(_) \
    _(type) \
    _(next) \
    _(viewFormatCount) \

#define XR_LIST_STRUCT_XrCompositionLayerCylinderKHR(_) \
    _(type) \
    _(next) \
    _(layerFlags) \
    _(space) \
    _(eyeVisibility) \
    _(subImage) \
    _(pose) \
    _(radius) \
    _(centralAngle) \
    _(aspectRatio) \

#define XR_LIST_STRUCT_XrCompositionLayerEquirectKHR(_) \
    _(type) \
    _(next) \
    _(layerFlags) \
    _(space) \
    _(eyeVisibility) \
    _(subImage) \
    _(pose) \
    _(radius) \
    _(scale) \
    _(bias) \

#define XR_LIST_STRUCT_XrGraphicsBindingOpenGLWin32KHR(_) \
    _(type) \
    _(next) \
    _(hDC) \
    _(hGLRC) \

#define XR_LIST_STRUCT_XrGraphicsBindingOpenGLXlibKHR(_) \
    _(type) \
    _(next) \
    _(xDisplay) \
    _(visualid) \
    _(glxFBConfig) \
    _(glxDrawable) \
    _(glxContext) \

#define XR_LIST_STRUCT_XrGraphicsBindingOpenGLXcbKHR(_) \
    _(type) \
    _(next) \
    _(connection) \
    _(screenNumber) \
    _(fbconfigid) \
    _(visualid) \
    _(glxDrawable) \
    _(glxContext) \

#define XR_LIST_STRUCT_XrGraphicsBindingOpenGLWaylandKHR(_) \
    _(type) \
    _(next) \
    _(display) \

#define XR_LIST_STRUCT_XrSwapchainImageOpenGLKHR(_) \
    _(type) \
    _(next) \
    _(image) \

#define XR_LIST_STRUCT_XrGraphicsRequirementsOpenGLKHR(_) \
    _(type) \
    _(next) \
    _(minApiVersionSupported) \
    _(maxApiVersionSupported) \

#define XR_LIST_STRUCT_XrGraphicsBindingOpenGLESAndroidKHR(_) \
    _(type) \
    _(next) \
    _(display) \
    _(config) \
    _(context) \

#define XR_LIST_STRUCT_XrSwapchainImageOpenGLESKHR(_) \
    _(type) \
    _(next) \
    _(image) \

#define XR_LIST_STRUCT_XrGraphicsRequirementsOpenGLESKHR(_) \
    _(type) \
    _(next) \
    _(minApiVersionSupported) \
    _(maxApiVersionSupported) \

#define XR_LIST_STRUCT_XrGraphicsBindingVulkanKHR(_) \
    _(type) \
    _(next) \
    _(instance) \
    _(physicalDevice) \
    _(device) \
    _(queueFamilyIndex) \
    _(queueIndex) \

#define XR_LIST_STRUCT_XrSwapchainImageVulkanKHR(_) \
    _(type) \
    _(next) \
    _(image) \

#define XR_LIST_STRUCT_XrGraphicsRequirementsVulkanKHR(_) \
    _(type) \
    _(next) \
    _(minApiVersionSupported) \
    _(maxApiVersionSupported) \

#define XR_LIST_STRUCT_XrGraphicsBindingD3D11KHR(_) \
    _(type) \
    _(next) \
    _(device) \

#define XR_LIST_STRUCT_XrSwapchainImageD3D11KHR(_) \
    _(type) \
    _(next) \
    _(texture) \

#define XR_LIST_STRUCT_XrGraphicsRequirementsD3D11KHR(_) \
    _(type) \
    _(next) \
    _(adapterLuid) \
    _(minFeatureLevel) \

#define XR_LIST_STRUCT_XrGraphicsBindingD3D12KHR(_) \
    _(type) \
    _(next) \
    _(device) \
    _(queue) \

#define XR_LIST_STRUCT_XrSwapchainImageD3D12KHR(_) \
    _(type) \
    _(next) \
    _(texture) \

#define XR_LIST_STRUCT_XrGraphicsRequirementsD3D12KHR(_) \
    _(type) \
    _(next) \
    _(adapterLuid) \
    _(minFeatureLevel) \

#define XR_LIST_STRUCT_XrVisibilityMaskKHR(_) \
    _(type) \
    _(next) \
    _(vertexCapacityInput) \
    _(vertexCountOutput) \
    _(indexCapacityInput) \
    _(indexCountOutput) \

#define XR_LIST_STRUCT_XrEventDataVisibilityMaskChangedKHR(_) \
    _(type) \
    _(next) \
    _(session) \
    _(viewConfigurationType) \
    _(viewIndex) \

#define XR_LIST_STRUCT_XrCompositionLayerColorScaleBiasKHR(_) \
    _(type) \
    _(next) \
    _(colorScale) \
    _(colorBias) \

#define XR_LIST_STRUCT_XrLoaderInitInfoBaseHeaderKHR(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrLoaderInitInfoAndroidKHR(_) \
    _(type) \
    _(next) \
    _(applicationVM) \
    _(applicationContext) \

#define XR_LIST_STRUCT_XrVulkanInstanceCreateInfoKHR(_) \
    _(type) \
    _(next) \
    _(systemId) \
    _(createFlags) \
    _(pfnGetInstanceProcAddr) \
    _(vulkanCreateInfo) \
    _(vulkanAllocator) \

#define XR_LIST_STRUCT_XrVulkanDeviceCreateInfoKHR(_) \
    _(type) \
    _(next) \
    _(systemId) \
    _(createFlags) \
    _(pfnGetInstanceProcAddr) \
    _(vulkanPhysicalDevice) \
    _(vulkanCreateInfo) \
    _(vulkanAllocator) \

#define XR_LIST_STRUCT_XrVulkanGraphicsDeviceGetInfoKHR(_) \
    _(type) \
    _(next) \
    _(systemId) \
    _(vulkanInstance) \

#define XR_LIST_STRUCT_XrCompositionLayerEquirect2KHR(_) \
    _(type) \
    _(next) \
    _(layerFlags) \
    _(space) \
    _(eyeVisibility) \
    _(subImage) \
    _(pose) \
    _(radius) \
    _(centralHorizontalAngle) \
    _(upperVerticalAngle) \
    _(lowerVerticalAngle) \

#define XR_LIST_STRUCT_XrBindingModificationBaseHeaderKHR(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrBindingModificationsKHR(_) \
    _(type) \
    _(next) \
    _(bindingModificationCount) \

#define XR_LIST_STRUCT_XrEventDataPerfSettingsEXT(_) \
    _(type) \
    _(next) \
    _(domain) \
    _(subDomain) \
    _(fromLevel) \
    _(toLevel) \

#define XR_LIST_STRUCT_XrDebugUtilsObjectNameInfoEXT(_) \
    _(type) \
    _(next) \
    _(objectType) \
    _(objectHandle) \
    _(objectName) \

#define XR_LIST_STRUCT_XrDebugUtilsLabelEXT(_) \
    _(type) \
    _(next) \
    _(labelName) \

#define XR_LIST_STRUCT_XrDebugUtilsMessengerCallbackDataEXT(_) \
    _(type) \
    _(next) \
    _(messageId) \
    _(functionName) \
    _(message) \
    _(objectCount) \
    _(sessionLabelCount) \

#define XR_LIST_STRUCT_XrSystemEyeGazeInteractionPropertiesEXT(_) \
    _(type) \
    _(next) \
    _(supportsEyeGazeInteraction) \

#define XR_LIST_STRUCT_XrEyeGazeSampleTimeEXT(_) \
    _(type) \
    _(next) \
    _(time) \

#define XR_LIST_STRUCT_XrSessionCreateInfoOverlayEXTX(_) \
    _(type) \
    _(next) \
    _(createFlags) \
    _(sessionLayersPlacement) \

#define XR_LIST_STRUCT_XrEventDataMainSessionVisibilityChangedEXTX(_) \
    _(type) \
    _(next) \
    _(visible) \
    _(flags) \

#define XR_LIST_STRUCT_XrSpatialAnchorCreateInfoMSFT(_) \
    _(type) \
    _(next) \
    _(space) \
    _(pose) \
    _(time) \

#define XR_LIST_STRUCT_XrSpatialAnchorSpaceCreateInfoMSFT(_) \
    _(type) \
    _(next) \
    _(anchor) \
    _(poseInAnchorSpace) \

#define XR_LIST_STRUCT_XrViewConfigurationDepthRangeEXT(_) \
    _(type) \
    _(next) \
    _(recommendedNearZ) \
    _(minNearZ) \
    _(recommendedFarZ) \
    _(maxFarZ) \

#define XR_LIST_STRUCT_XrGraphicsBindingEGLMNDX(_) \
    _(type) \
    _(next) \
    _(getProcAddress) \
    _(display) \
    _(config) \
    _(context) \

#define XR_LIST_STRUCT_XrSystemHandTrackingPropertiesEXT(_) \
    _(type) \
    _(next) \
    _(supportsHandTracking) \

#define XR_LIST_STRUCT_XrHandTrackerCreateInfoEXT(_) \
    _(type) \
    _(next) \
    _(hand) \
    _(handJointSet) \

#define XR_LIST_STRUCT_XrHandJointsLocateInfoEXT(_) \
    _(type) \
    _(next) \
    _(baseSpace) \
    _(time) \

#define XR_LIST_STRUCT_XrHandJointLocationEXT(_) \
    _(locationFlags) \
    _(pose) \
    _(radius) \

#define XR_LIST_STRUCT_XrHandJointVelocityEXT(_) \
    _(velocityFlags) \
    _(linearVelocity) \
    _(angularVelocity) \

#define XR_LIST_STRUCT_XrHandJointLocationsEXT(_) \
    _(type) \
    _(next) \
    _(isActive) \
    _(jointCount) \

#define XR_LIST_STRUCT_XrHandJointVelocitiesEXT(_) \
    _(type) \
    _(next) \
    _(jointCount) \

#define XR_LIST_STRUCT_XrSystemHandTrackingMeshPropertiesMSFT(_) \
    _(type) \
    _(next) \
    _(supportsHandTrackingMesh) \
    _(maxHandMeshIndexCount) \
    _(maxHandMeshVertexCount) \

#define XR_LIST_STRUCT_XrHandMeshSpaceCreateInfoMSFT(_) \
    _(type) \
    _(next) \
    _(handPoseType) \
    _(poseInHandMeshSpace) \

#define XR_LIST_STRUCT_XrHandMeshUpdateInfoMSFT(_) \
    _(type) \
    _(next) \
    _(time) \
    _(handPoseType) \

#define XR_LIST_STRUCT_XrHandMeshIndexBufferMSFT(_) \
    _(indexBufferKey) \
    _(indexCapacityInput) \
    _(indexCountOutput) \

#define XR_LIST_STRUCT_XrHandMeshVertexMSFT(_) \
    _(position) \
    _(normal) \

#define XR_LIST_STRUCT_XrHandMeshVertexBufferMSFT(_) \
    _(vertexUpdateTime) \
    _(vertexCapacityInput) \
    _(vertexCountOutput) \

#define XR_LIST_STRUCT_XrHandMeshMSFT(_) \
    _(type) \
    _(next) \
    _(isActive) \
    _(indexBufferChanged) \
    _(vertexBufferChanged) \
    _(indexBuffer) \
    _(vertexBuffer) \

#define XR_LIST_STRUCT_XrHandPoseTypeInfoMSFT(_) \
    _(type) \
    _(next) \
    _(handPoseType) \

#define XR_LIST_STRUCT_XrSecondaryViewConfigurationSessionBeginInfoMSFT(_) \
    _(type) \
    _(next) \
    _(viewConfigurationCount) \

#define XR_LIST_STRUCT_XrSecondaryViewConfigurationStateMSFT(_) \
    _(type) \
    _(next) \
    _(viewConfigurationType) \
    _(active) \

#define XR_LIST_STRUCT_XrSecondaryViewConfigurationFrameStateMSFT(_) \
    _(type) \
    _(next) \
    _(viewConfigurationCount) \

#define XR_LIST_STRUCT_XrSecondaryViewConfigurationLayerInfoMSFT(_) \
    _(type) \
    _(next) \
    _(viewConfigurationType) \
    _(environmentBlendMode) \
    _(layerCount) \

#define XR_LIST_STRUCT_XrSecondaryViewConfigurationFrameEndInfoMSFT(_) \
    _(type) \
    _(next) \
    _(viewConfigurationCount) \

#define XR_LIST_STRUCT_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT(_) \
    _(type) \
    _(next) \
    _(viewConfigurationType) \

#define XR_LIST_STRUCT_XrControllerModelKeyStateMSFT(_) \
    _(type) \
    _(next) \
    _(modelKey) \

#define XR_LIST_STRUCT_XrControllerModelNodePropertiesMSFT(_) \
    _(type) \
    _(next) \
    _(parentNodeName) \
    _(nodeName) \

#define XR_LIST_STRUCT_XrControllerModelPropertiesMSFT(_) \
    _(type) \
    _(next) \
    _(nodeCapacityInput) \
    _(nodeCountOutput) \

#define XR_LIST_STRUCT_XrControllerModelNodeStateMSFT(_) \
    _(type) \
    _(next) \
    _(nodePose) \

#define XR_LIST_STRUCT_XrControllerModelStateMSFT(_) \
    _(type) \
    _(next) \
    _(nodeCapacityInput) \
    _(nodeCountOutput) \

#define XR_LIST_STRUCT_XrViewConfigurationViewFovEPIC(_) \
    _(type) \
    _(next) \
    _(recommendedFov) \
    _(maxMutableFov) \

#define XR_LIST_STRUCT_XrHolographicWindowAttachmentMSFT(_) \
    _(type) \
    _(next) \
    _(holographicSpace) \
    _(coreWindow) \

#define XR_LIST_STRUCT_XrCompositionLayerReprojectionInfoMSFT(_) \
    _(type) \
    _(next) \
    _(reprojectionMode) \

#define XR_LIST_STRUCT_XrCompositionLayerReprojectionPlaneOverrideMSFT(_) \
    _(type) \
    _(next) \
    _(position) \
    _(normal) \
    _(velocity) \

#define XR_LIST_STRUCT_XrAndroidSurfaceSwapchainCreateInfoFB(_) \
    _(type) \
    _(next) \
    _(createFlags) \

#define XR_LIST_STRUCT_XrSwapchainStateBaseHeaderFB(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrHandJointsMotionRangeInfoEXT(_) \
    _(type) \
    _(next) \
    _(handJointsMotionRange) \

#define XR_LIST_STRUCT_XrUuidMSFT(_) \
    _(bytes) \

#define XR_LIST_STRUCT_XrSceneObserverCreateInfoMSFT(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrSceneCreateInfoMSFT(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrSceneSphereBoundMSFT(_) \
    _(center) \
    _(radius) \

#define XR_LIST_STRUCT_XrSceneOrientedBoxBoundMSFT(_) \
    _(pose) \
    _(extents) \

#define XR_LIST_STRUCT_XrSceneFrustumBoundMSFT(_) \
    _(pose) \
    _(fov) \
    _(farDistance) \

#define XR_LIST_STRUCT_XrSceneBoundsMSFT(_) \
    _(space) \
    _(time) \
    _(sphereCount) \
    _(boxCount) \
    _(frustumCount) \

#define XR_LIST_STRUCT_XrNewSceneComputeInfoMSFT(_) \
    _(type) \
    _(next) \
    _(requestedFeatureCount) \
    _(consistency) \
    _(bounds) \

#define XR_LIST_STRUCT_XrVisualMeshComputeLodInfoMSFT(_) \
    _(type) \
    _(next) \
    _(lod) \

#define XR_LIST_STRUCT_XrSceneComponentMSFT(_) \
    _(componentType) \
    _(id) \
    _(parentId) \
    _(updateTime) \

#define XR_LIST_STRUCT_XrSceneComponentsMSFT(_) \
    _(type) \
    _(next) \
    _(componentCapacityInput) \
    _(componentCountOutput) \

#define XR_LIST_STRUCT_XrSceneComponentsGetInfoMSFT(_) \
    _(type) \
    _(next) \
    _(componentType) \

#define XR_LIST_STRUCT_XrSceneComponentLocationMSFT(_) \
    _(flags) \
    _(pose) \

#define XR_LIST_STRUCT_XrSceneComponentLocationsMSFT(_) \
    _(type) \
    _(next) \
    _(locationCount) \

#define XR_LIST_STRUCT_XrSceneComponentsLocateInfoMSFT(_) \
    _(type) \
    _(next) \
    _(baseSpace) \
    _(time) \
    _(componentIdCount) \

#define XR_LIST_STRUCT_XrSceneObjectMSFT(_) \
    _(objectType) \

#define XR_LIST_STRUCT_XrSceneObjectsMSFT(_) \
    _(type) \
    _(next) \
    _(sceneObjectCount) \

#define XR_LIST_STRUCT_XrSceneComponentParentFilterInfoMSFT(_) \
    _(type) \
    _(next) \
    _(parentId) \

#define XR_LIST_STRUCT_XrSceneObjectTypesFilterInfoMSFT(_) \
    _(type) \
    _(next) \
    _(objectTypeCount) \

#define XR_LIST_STRUCT_XrScenePlaneMSFT(_) \
    _(alignment) \
    _(size) \
    _(meshBufferId) \
    _(supportsIndicesUint16) \

#define XR_LIST_STRUCT_XrScenePlanesMSFT(_) \
    _(type) \
    _(next) \
    _(scenePlaneCount) \

#define XR_LIST_STRUCT_XrScenePlaneAlignmentFilterInfoMSFT(_) \
    _(type) \
    _(next) \
    _(alignmentCount) \

#define XR_LIST_STRUCT_XrSceneMeshMSFT(_) \
    _(meshBufferId) \
    _(supportsIndicesUint16) \

#define XR_LIST_STRUCT_XrSceneMeshesMSFT(_) \
    _(type) \
    _(next) \
    _(sceneMeshCount) \

#define XR_LIST_STRUCT_XrSceneMeshBuffersGetInfoMSFT(_) \
    _(type) \
    _(next) \
    _(meshBufferId) \

#define XR_LIST_STRUCT_XrSceneMeshBuffersMSFT(_) \
    _(type) \
    _(next) \

#define XR_LIST_STRUCT_XrSceneMeshVertexBufferMSFT(_) \
    _(type) \
    _(next) \
    _(vertexCapacityInput) \
    _(vertexCountOutput) \

#define XR_LIST_STRUCT_XrSceneMeshIndicesUint32MSFT(_) \
    _(type) \
    _(next) \
    _(indexCapacityInput) \
    _(indexCountOutput) \

#define XR_LIST_STRUCT_XrSceneMeshIndicesUint16MSFT(_) \
    _(type) \
    _(next) \
    _(indexCapacityInput) \
    _(indexCountOutput) \

#define XR_LIST_STRUCT_XrSerializedSceneFragmentDataGetInfoMSFT(_) \
    _(type) \
    _(next) \
    _(sceneFragmentId) \

#define XR_LIST_STRUCT_XrDeserializeSceneFragmentMSFT(_) \
    _(bufferSize) \

#define XR_LIST_STRUCT_XrSceneDeserializeInfoMSFT(_) \
    _(type) \
    _(next) \
    _(fragmentCount) \

#define XR_LIST_STRUCT_XrEventDataDisplayRefreshRateChangedFB(_) \
    _(type) \
    _(next) \
    _(fromDisplayRefreshRate) \
    _(toDisplayRefreshRate) \

#define XR_LIST_STRUCT_XrSystemColorSpacePropertiesFB(_) \
    _(type) \
    _(next) \
    _(colorSpace) \

#define XR_LIST_STRUCT_XrViewLocateFoveatedRenderingVARJO(_) \
    _(type) \
    _(next) \
    _(foveatedRenderingActive) \

#define XR_LIST_STRUCT_XrFoveatedViewConfigurationViewVARJO(_) \
    _(type) \
    _(next) \
    _(foveatedRenderingActive) \

#define XR_LIST_STRUCT_XrSystemFoveatedRenderingPropertiesVARJO(_) \
    _(type) \
    _(next) \
    _(supportsFoveatedRendering) \

#define XR_LIST_STRUCT_XrCompositionLayerDepthTestVARJO(_) \
    _(type) \
    _(next) \
    _(depthTestRangeNearZ) \
    _(depthTestRangeFarZ) \

#define XR_LIST_STRUCT_XrSwapchainStateAndroidSurfaceDimensionsFB(_) \
    _(type) \
    _(next) \
    _(width) \
    _(height) \

#define XR_LIST_STRUCT_XrSwapchainStateSamplerOpenGLESFB(_) \
    _(type) \
    _(next) \
    _(minFilter) \
    _(magFilter) \
    _(wrapModeS) \
    _(wrapModeT) \
    _(swizzleRed) \
    _(swizzleGreen) \
    _(swizzleBlue) \
    _(swizzleAlpha) \
    _(maxAnisotropy) \
    _(borderColor) \

#define XR_LIST_STRUCT_XrSwapchainStateSamplerVulkanFB(_) \
    _(type) \
    _(next) \
    _(minFilter) \
    _(magFilter) \
    _(mipmapMode) \
    _(wrapModeS) \
    _(wrapModeT) \
    _(swizzleRed) \
    _(swizzleGreen) \
    _(swizzleBlue) \
    _(swizzleAlpha) \
    _(maxAnisotropy) \
    _(borderColor) \

#define XR_LIST_STRUCT_ARRAYS_XrApiLayerProperties(_) \

#define XR_LIST_STRUCT_ARRAYS_XrExtensionProperties(_) \

#define XR_LIST_STRUCT_ARRAYS_XrApplicationInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrInstanceCreateInfo(_) \
    _(enabledApiLayerNames, enabledApiLayerCount) \
    _(enabledExtensionNames, enabledExtensionCount) \

#define XR_LIST_STRUCT_ARRAYS_XrInstanceProperties(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSystemGetInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSystemGraphicsProperties(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSystemTrackingProperties(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSystemProperties(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSessionCreateInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrVector3f(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSpaceVelocity(_) \

#define XR_LIST_STRUCT_ARRAYS_XrQuaternionf(_) \

#define XR_LIST_STRUCT_ARRAYS_XrPosef(_) \

#define XR_LIST_STRUCT_ARRAYS_XrReferenceSpaceCreateInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrExtent2Df(_) \

#define XR_LIST_STRUCT_ARRAYS_XrActionSpaceCreateInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSpaceLocation(_) \

#define XR_LIST_STRUCT_ARRAYS_XrViewConfigurationProperties(_) \

#define XR_LIST_STRUCT_ARRAYS_XrViewConfigurationView(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainCreateInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainImageBaseHeader(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainImageAcquireInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainImageWaitInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainImageReleaseInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSessionBeginInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrFrameWaitInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrFrameState(_) \

#define XR_LIST_STRUCT_ARRAYS_XrFrameBeginInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerBaseHeader(_) \

#define XR_LIST_STRUCT_ARRAYS_XrFrameEndInfo(_) \
    _(layers, layerCount) \

#define XR_LIST_STRUCT_ARRAYS_XrViewLocateInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrViewState(_) \

#define XR_LIST_STRUCT_ARRAYS_XrFovf(_) \

#define XR_LIST_STRUCT_ARRAYS_XrView(_) \

#define XR_LIST_STRUCT_ARRAYS_XrActionSetCreateInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrActionCreateInfo(_) \
    _(subactionPaths, countSubactionPaths) \

#define XR_LIST_STRUCT_ARRAYS_XrActionSuggestedBinding(_) \

#define XR_LIST_STRUCT_ARRAYS_XrInteractionProfileSuggestedBinding(_) \
    _(suggestedBindings, countSuggestedBindings) \

#define XR_LIST_STRUCT_ARRAYS_XrSessionActionSetsAttachInfo(_) \
    _(actionSets, countActionSets) \

#define XR_LIST_STRUCT_ARRAYS_XrInteractionProfileState(_) \

#define XR_LIST_STRUCT_ARRAYS_XrActionStateGetInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrActionStateBoolean(_) \

#define XR_LIST_STRUCT_ARRAYS_XrActionStateFloat(_) \

#define XR_LIST_STRUCT_ARRAYS_XrVector2f(_) \

#define XR_LIST_STRUCT_ARRAYS_XrActionStateVector2f(_) \

#define XR_LIST_STRUCT_ARRAYS_XrActionStatePose(_) \

#define XR_LIST_STRUCT_ARRAYS_XrActiveActionSet(_) \

#define XR_LIST_STRUCT_ARRAYS_XrActionsSyncInfo(_) \
    _(activeActionSets, countActiveActionSets) \

#define XR_LIST_STRUCT_ARRAYS_XrBoundSourcesForActionEnumerateInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrInputSourceLocalizedNameGetInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHapticActionInfo(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHapticBaseHeader(_) \

#define XR_LIST_STRUCT_ARRAYS_XrOffset2Di(_) \

#define XR_LIST_STRUCT_ARRAYS_XrExtent2Di(_) \

#define XR_LIST_STRUCT_ARRAYS_XrRect2Di(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainSubImage(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerProjectionView(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerProjection(_) \
    _(views, viewCount) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerQuad(_) \

#define XR_LIST_STRUCT_ARRAYS_XrEventDataBaseHeader(_) \

#define XR_LIST_STRUCT_ARRAYS_XrEventDataEventsLost(_) \

#define XR_LIST_STRUCT_ARRAYS_XrEventDataInstanceLossPending(_) \

#define XR_LIST_STRUCT_ARRAYS_XrEventDataSessionStateChanged(_) \

#define XR_LIST_STRUCT_ARRAYS_XrEventDataReferenceSpaceChangePending(_) \

#define XR_LIST_STRUCT_ARRAYS_XrEventDataInteractionProfileChanged(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHapticVibration(_) \

#define XR_LIST_STRUCT_ARRAYS_XrOffset2Df(_) \

#define XR_LIST_STRUCT_ARRAYS_XrRect2Df(_) \

#define XR_LIST_STRUCT_ARRAYS_XrVector4f(_) \

#define XR_LIST_STRUCT_ARRAYS_XrColor4f(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerCubeKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrInstanceCreateInfoAndroidKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerDepthInfoKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrVulkanSwapchainFormatListCreateInfoKHR(_) \
    _(viewFormats, viewFormatCount) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerCylinderKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerEquirectKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsBindingOpenGLWin32KHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsBindingOpenGLXlibKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsBindingOpenGLXcbKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsBindingOpenGLWaylandKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainImageOpenGLKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsRequirementsOpenGLKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsBindingOpenGLESAndroidKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainImageOpenGLESKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsRequirementsOpenGLESKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsBindingVulkanKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainImageVulkanKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsRequirementsVulkanKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsBindingD3D11KHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainImageD3D11KHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsRequirementsD3D11KHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsBindingD3D12KHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainImageD3D12KHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsRequirementsD3D12KHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrVisibilityMaskKHR(_) \
    _(vertices, vertexCapacityInput) \
    _(indices, indexCapacityInput) \

#define XR_LIST_STRUCT_ARRAYS_XrEventDataVisibilityMaskChangedKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerColorScaleBiasKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrLoaderInitInfoBaseHeaderKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrLoaderInitInfoAndroidKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrVulkanInstanceCreateInfoKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrVulkanDeviceCreateInfoKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrVulkanGraphicsDeviceGetInfoKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerEquirect2KHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrBindingModificationBaseHeaderKHR(_) \

#define XR_LIST_STRUCT_ARRAYS_XrBindingModificationsKHR(_) \
    _(bindingModifications, bindingModificationCount) \

#define XR_LIST_STRUCT_ARRAYS_XrEventDataPerfSettingsEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrDebugUtilsObjectNameInfoEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrDebugUtilsLabelEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrDebugUtilsMessengerCallbackDataEXT(_) \
    _(objects, objectCount) \
    _(sessionLabels, sessionLabelCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSystemEyeGazeInteractionPropertiesEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrEyeGazeSampleTimeEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSessionCreateInfoOverlayEXTX(_) \

#define XR_LIST_STRUCT_ARRAYS_XrEventDataMainSessionVisibilityChangedEXTX(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSpatialAnchorCreateInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSpatialAnchorSpaceCreateInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrViewConfigurationDepthRangeEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrGraphicsBindingEGLMNDX(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSystemHandTrackingPropertiesEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandTrackerCreateInfoEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandJointsLocateInfoEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandJointLocationEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandJointVelocityEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandJointLocationsEXT(_) \
    _(jointLocations, jointCount) \

#define XR_LIST_STRUCT_ARRAYS_XrHandJointVelocitiesEXT(_) \
    _(jointVelocities, jointCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSystemHandTrackingMeshPropertiesMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandMeshSpaceCreateInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandMeshUpdateInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandMeshIndexBufferMSFT(_) \
    _(indices, indexCapacityInput) \

#define XR_LIST_STRUCT_ARRAYS_XrHandMeshVertexMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandMeshVertexBufferMSFT(_) \
    _(vertices, vertexCapacityInput) \

#define XR_LIST_STRUCT_ARRAYS_XrHandMeshMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandPoseTypeInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSecondaryViewConfigurationSessionBeginInfoMSFT(_) \
    _(enabledViewConfigurationTypes, viewConfigurationCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSecondaryViewConfigurationStateMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSecondaryViewConfigurationFrameStateMSFT(_) \
    _(viewConfigurationStates, viewConfigurationCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSecondaryViewConfigurationLayerInfoMSFT(_) \
    _(layers, layerCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSecondaryViewConfigurationFrameEndInfoMSFT(_) \
    _(viewConfigurationLayersInfo, viewConfigurationCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSecondaryViewConfigurationSwapchainCreateInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrControllerModelKeyStateMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrControllerModelNodePropertiesMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrControllerModelPropertiesMSFT(_) \
    _(nodeProperties, nodeCapacityInput) \

#define XR_LIST_STRUCT_ARRAYS_XrControllerModelNodeStateMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrControllerModelStateMSFT(_) \
    _(nodeStates, nodeCapacityInput) \

#define XR_LIST_STRUCT_ARRAYS_XrViewConfigurationViewFovEPIC(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHolographicWindowAttachmentMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerReprojectionInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerReprojectionPlaneOverrideMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrAndroidSurfaceSwapchainCreateInfoFB(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainStateBaseHeaderFB(_) \

#define XR_LIST_STRUCT_ARRAYS_XrHandJointsMotionRangeInfoEXT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrUuidMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneObserverCreateInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneCreateInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneSphereBoundMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneOrientedBoxBoundMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneFrustumBoundMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneBoundsMSFT(_) \
    _(spheres, sphereCount) \
    _(boxes, boxCount) \
    _(frustums, frustumCount) \

#define XR_LIST_STRUCT_ARRAYS_XrNewSceneComputeInfoMSFT(_) \
    _(requestedFeatures, requestedFeatureCount) \

#define XR_LIST_STRUCT_ARRAYS_XrVisualMeshComputeLodInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneComponentMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneComponentsMSFT(_) \
    _(components, componentCapacityInput) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneComponentsGetInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneComponentLocationMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneComponentLocationsMSFT(_) \
    _(locations, locationCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneComponentsLocateInfoMSFT(_) \
    _(componentIds, componentIdCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneObjectMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneObjectsMSFT(_) \
    _(sceneObjects, sceneObjectCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneComponentParentFilterInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneObjectTypesFilterInfoMSFT(_) \
    _(objectTypes, objectTypeCount) \

#define XR_LIST_STRUCT_ARRAYS_XrScenePlaneMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrScenePlanesMSFT(_) \
    _(scenePlanes, scenePlaneCount) \

#define XR_LIST_STRUCT_ARRAYS_XrScenePlaneAlignmentFilterInfoMSFT(_) \
    _(alignments, alignmentCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneMeshMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneMeshesMSFT(_) \
    _(sceneMeshes, sceneMeshCount) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneMeshBuffersGetInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneMeshBuffersMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneMeshVertexBufferMSFT(_) \
    _(vertices, vertexCapacityInput) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneMeshIndicesUint32MSFT(_) \
    _(indices, indexCapacityInput) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneMeshIndicesUint16MSFT(_) \
    _(indices, indexCapacityInput) \

#define XR_LIST_STRUCT_ARRAYS_XrSerializedSceneFragmentDataGetInfoMSFT(_) \

#define XR_LIST_STRUCT_ARRAYS_XrDeserializeSceneFragmentMSFT(_) \
    _(buffer, bufferSize) \

#define XR_LIST_STRUCT_ARRAYS_XrSceneDeserializeInfoMSFT(_) \
    _(fragments, fragmentCount) \

#define XR_LIST_STRUCT_ARRAYS_XrEventDataDisplayRefreshRateChangedFB(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSystemColorSpacePropertiesFB(_) \

#define XR_LIST_STRUCT_ARRAYS_XrViewLocateFoveatedRenderingVARJO(_) \

#define XR_LIST_STRUCT_ARRAYS_XrFoveatedViewConfigurationViewVARJO(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSystemFoveatedRenderingPropertiesVARJO(_) \

#define XR_LIST_STRUCT_ARRAYS_XrCompositionLayerDepthTestVARJO(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainStateAndroidSurfaceDimensionsFB(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainStateSamplerOpenGLESFB(_) \

#define XR_LIST_STRUCT_ARRAYS_XrSwapchainStateSamplerVulkanFB(_) \



#define XR_LIST_STRUCTURE_TYPES_CORE(_) \
    _(XrApiLayerProperties, XR_TYPE_API_LAYER_PROPERTIES) \
    _(XrExtensionProperties, XR_TYPE_EXTENSION_PROPERTIES) \
    _(XrInstanceCreateInfo, XR_TYPE_INSTANCE_CREATE_INFO) \
    _(XrInstanceProperties, XR_TYPE_INSTANCE_PROPERTIES) \
    _(XrSystemGetInfo, XR_TYPE_SYSTEM_GET_INFO) \
    _(XrSystemProperties, XR_TYPE_SYSTEM_PROPERTIES) \
    _(XrSessionCreateInfo, XR_TYPE_SESSION_CREATE_INFO) \
    _(XrSpaceVelocity, XR_TYPE_SPACE_VELOCITY) \
    _(XrReferenceSpaceCreateInfo, XR_TYPE_REFERENCE_SPACE_CREATE_INFO) \
    _(XrActionSpaceCreateInfo, XR_TYPE_ACTION_SPACE_CREATE_INFO) \
    _(XrSpaceLocation, XR_TYPE_SPACE_LOCATION) \
    _(XrViewConfigurationProperties, XR_TYPE_VIEW_CONFIGURATION_PROPERTIES) \
    _(XrViewConfigurationView, XR_TYPE_VIEW_CONFIGURATION_VIEW) \
    _(XrSwapchainCreateInfo, XR_TYPE_SWAPCHAIN_CREATE_INFO) \
    _(XrSwapchainImageAcquireInfo, XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO) \
    _(XrSwapchainImageWaitInfo, XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO) \
    _(XrSwapchainImageReleaseInfo, XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO) \
    _(XrSessionBeginInfo, XR_TYPE_SESSION_BEGIN_INFO) \
    _(XrFrameWaitInfo, XR_TYPE_FRAME_WAIT_INFO) \
    _(XrFrameState, XR_TYPE_FRAME_STATE) \
    _(XrFrameBeginInfo, XR_TYPE_FRAME_BEGIN_INFO) \
    _(XrFrameEndInfo, XR_TYPE_FRAME_END_INFO) \
    _(XrViewLocateInfo, XR_TYPE_VIEW_LOCATE_INFO) \
    _(XrViewState, XR_TYPE_VIEW_STATE) \
    _(XrView, XR_TYPE_VIEW) \
    _(XrActionSetCreateInfo, XR_TYPE_ACTION_SET_CREATE_INFO) \
    _(XrActionCreateInfo, XR_TYPE_ACTION_CREATE_INFO) \
    _(XrInteractionProfileSuggestedBinding, XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING) \
    _(XrSessionActionSetsAttachInfo, XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO) \
    _(XrInteractionProfileState, XR_TYPE_INTERACTION_PROFILE_STATE) \
    _(XrActionStateGetInfo, XR_TYPE_ACTION_STATE_GET_INFO) \
    _(XrActionStateBoolean, XR_TYPE_ACTION_STATE_BOOLEAN) \
    _(XrActionStateFloat, XR_TYPE_ACTION_STATE_FLOAT) \
    _(XrActionStateVector2f, XR_TYPE_ACTION_STATE_VECTOR2F) \
    _(XrActionStatePose, XR_TYPE_ACTION_STATE_POSE) \
    _(XrActionsSyncInfo, XR_TYPE_ACTIONS_SYNC_INFO) \
    _(XrBoundSourcesForActionEnumerateInfo, XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO) \
    _(XrInputSourceLocalizedNameGetInfo, XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO) \
    _(XrHapticActionInfo, XR_TYPE_HAPTIC_ACTION_INFO) \
    _(XrCompositionLayerProjectionView, XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW) \
    _(XrCompositionLayerProjection, XR_TYPE_COMPOSITION_LAYER_PROJECTION) \
    _(XrCompositionLayerQuad, XR_TYPE_COMPOSITION_LAYER_QUAD) \
    _(XrEventDataEventsLost, XR_TYPE_EVENT_DATA_EVENTS_LOST) \
    _(XrEventDataInstanceLossPending, XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING) \
    _(XrEventDataSessionStateChanged, XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED) \
    _(XrEventDataReferenceSpaceChangePending, XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING) \
    _(XrEventDataInteractionProfileChanged, XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED) \
    _(XrHapticVibration, XR_TYPE_HAPTIC_VIBRATION) \
    _(XrCompositionLayerCubeKHR, XR_TYPE_COMPOSITION_LAYER_CUBE_KHR) \
    _(XrCompositionLayerDepthInfoKHR, XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR) \
    _(XrCompositionLayerCylinderKHR, XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR) \
    _(XrCompositionLayerEquirectKHR, XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR) \
    _(XrVisibilityMaskKHR, XR_TYPE_VISIBILITY_MASK_KHR) \
    _(XrEventDataVisibilityMaskChangedKHR, XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR) \
    _(XrCompositionLayerColorScaleBiasKHR, XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR) \
    _(XrCompositionLayerEquirect2KHR, XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR) \
    _(XrBindingModificationsKHR, XR_TYPE_BINDING_MODIFICATIONS_KHR) \
    _(XrEventDataPerfSettingsEXT, XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT) \
    _(XrDebugUtilsObjectNameInfoEXT, XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT) \
    _(XrDebugUtilsLabelEXT, XR_TYPE_DEBUG_UTILS_LABEL_EXT) \
    _(XrDebugUtilsMessengerCallbackDataEXT, XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT) \
    _(XrSystemEyeGazeInteractionPropertiesEXT, XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT) \
    _(XrEyeGazeSampleTimeEXT, XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT) \
    _(XrSessionCreateInfoOverlayEXTX, XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX) \
    _(XrEventDataMainSessionVisibilityChangedEXTX, XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX) \
    _(XrSpatialAnchorCreateInfoMSFT, XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT) \
    _(XrSpatialAnchorSpaceCreateInfoMSFT, XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT) \
    _(XrViewConfigurationDepthRangeEXT, XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT) \
    _(XrSystemHandTrackingPropertiesEXT, XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT) \
    _(XrHandTrackerCreateInfoEXT, XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT) \
    _(XrHandJointsLocateInfoEXT, XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT) \
    _(XrHandJointLocationsEXT, XR_TYPE_HAND_JOINT_LOCATIONS_EXT) \
    _(XrHandJointVelocitiesEXT, XR_TYPE_HAND_JOINT_VELOCITIES_EXT) \
    _(XrSystemHandTrackingMeshPropertiesMSFT, XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT) \
    _(XrHandMeshSpaceCreateInfoMSFT, XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT) \
    _(XrHandMeshUpdateInfoMSFT, XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT) \
    _(XrHandMeshMSFT, XR_TYPE_HAND_MESH_MSFT) \
    _(XrHandPoseTypeInfoMSFT, XR_TYPE_HAND_POSE_TYPE_INFO_MSFT) \
    _(XrSecondaryViewConfigurationSessionBeginInfoMSFT, XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT) \
    _(XrSecondaryViewConfigurationStateMSFT, XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT) \
    _(XrSecondaryViewConfigurationFrameStateMSFT, XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT) \
    _(XrSecondaryViewConfigurationLayerInfoMSFT, XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT) \
    _(XrSecondaryViewConfigurationFrameEndInfoMSFT, XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT) \
    _(XrSecondaryViewConfigurationSwapchainCreateInfoMSFT, XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT) \
    _(XrControllerModelKeyStateMSFT, XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT) \
    _(XrControllerModelNodePropertiesMSFT, XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT) \
    _(XrControllerModelPropertiesMSFT, XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT) \
    _(XrControllerModelNodeStateMSFT, XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT) \
    _(XrControllerModelStateMSFT, XR_TYPE_CONTROLLER_MODEL_STATE_MSFT) \
    _(XrViewConfigurationViewFovEPIC, XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC) \
    _(XrCompositionLayerReprojectionInfoMSFT, XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT) \
    _(XrCompositionLayerReprojectionPlaneOverrideMSFT, XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT) \
    _(XrHandJointsMotionRangeInfoEXT, XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT) \
    _(XrSceneObserverCreateInfoMSFT, XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT) \
    _(XrSceneCreateInfoMSFT, XR_TYPE_SCENE_CREATE_INFO_MSFT) \
    _(XrNewSceneComputeInfoMSFT, XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT) \
    _(XrVisualMeshComputeLodInfoMSFT, XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT) \
    _(XrSceneComponentsMSFT, XR_TYPE_SCENE_COMPONENTS_MSFT) \
    _(XrSceneComponentsGetInfoMSFT, XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT) \
    _(XrSceneComponentLocationsMSFT, XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT) \
    _(XrSceneComponentsLocateInfoMSFT, XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT) \
    _(XrSceneObjectsMSFT, XR_TYPE_SCENE_OBJECTS_MSFT) \
    _(XrSceneComponentParentFilterInfoMSFT, XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT) \
    _(XrSceneObjectTypesFilterInfoMSFT, XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT) \
    _(XrScenePlanesMSFT, XR_TYPE_SCENE_PLANES_MSFT) \
    _(XrScenePlaneAlignmentFilterInfoMSFT, XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT) \
    _(XrSceneMeshesMSFT, XR_TYPE_SCENE_MESHES_MSFT) \
    _(XrSceneMeshBuffersGetInfoMSFT, XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT) \
    _(XrSceneMeshBuffersMSFT, XR_TYPE_SCENE_MESH_BUFFERS_MSFT) \
    _(XrSceneMeshVertexBufferMSFT, XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT) \
    _(XrSceneMeshIndicesUint32MSFT, XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT) \
    _(XrSceneMeshIndicesUint16MSFT, XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT) \
    _(XrSerializedSceneFragmentDataGetInfoMSFT, XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT) \
    _(XrSceneDeserializeInfoMSFT, XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT) \
    _(XrEventDataDisplayRefreshRateChangedFB, XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB) \
    _(XrSystemColorSpacePropertiesFB, XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB) \
    _(XrViewLocateFoveatedRenderingVARJO, XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO) \
    _(XrFoveatedViewConfigurationViewVARJO, XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO) \
    _(XrSystemFoveatedRenderingPropertiesVARJO, XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO) \
    _(XrCompositionLayerDepthTestVARJO, XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO) \




#if defined(XR_USE_GRAPHICS_API_D3D11)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_D3D11(_) \
    _(XrGraphicsBindingD3D11KHR, XR_TYPE_GRAPHICS_BINDING_D3D11_KHR) \
    _(XrSwapchainImageD3D11KHR, XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR) \
    _(XrGraphicsRequirementsD3D11KHR, XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_D3D11(_)
#endif

#if defined(XR_USE_GRAPHICS_API_D3D12)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_D3D12(_) \
    _(XrGraphicsBindingD3D12KHR, XR_TYPE_GRAPHICS_BINDING_D3D12_KHR) \
    _(XrSwapchainImageD3D12KHR, XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR) \
    _(XrGraphicsRequirementsD3D12KHR, XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_D3D12(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL(_) \
    _(XrSwapchainImageOpenGLKHR, XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR) \
    _(XrGraphicsRequirementsOpenGLKHR, XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WAYLAND)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \
    _(XrGraphicsBindingOpenGLWaylandKHR, XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \
    _(XrGraphicsBindingOpenGLWin32KHR, XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XCB)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \
    _(XrGraphicsBindingOpenGLXcbKHR, XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XLIB)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \
    _(XrGraphicsBindingOpenGLXlibKHR, XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    _(XrSwapchainImageOpenGLESKHR, XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR) \
    _(XrGraphicsRequirementsOpenGLESKHR, XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR) \
    _(XrSwapchainStateSamplerOpenGLESFB, XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_ES(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES) && defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \
    _(XrGraphicsBindingOpenGLESAndroidKHR, XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_GRAPHICS_API_VULKAN)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_VULKAN(_) \
    _(XrVulkanSwapchainFormatListCreateInfoKHR, XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR) \
    _(XrGraphicsBindingVulkanKHR, XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR) \
    _(XrSwapchainImageVulkanKHR, XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR) \
    _(XrGraphicsRequirementsVulkanKHR, XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR) \
    _(XrVulkanInstanceCreateInfoKHR, XR_TYPE_VULKAN_INSTANCE_CREATE_INFO_KHR) \
    _(XrVulkanDeviceCreateInfoKHR, XR_TYPE_VULKAN_DEVICE_CREATE_INFO_KHR) \
    _(XrVulkanGraphicsDeviceGetInfoKHR, XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR) \
    _(XrSwapchainStateSamplerVulkanFB, XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_VULKAN(_)
#endif

#if defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_PLATFORM_ANDROID(_) \
    _(XrInstanceCreateInfoAndroidKHR, XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR) \
    _(XrLoaderInitInfoAndroidKHR, XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR) \
    _(XrAndroidSurfaceSwapchainCreateInfoFB, XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB) \
    _(XrSwapchainStateAndroidSurfaceDimensionsFB, XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_PLATFORM_EGL)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_PLATFORM_EGL(_) \
    _(XrGraphicsBindingEGLMNDX, XR_TYPE_GRAPHICS_BINDING_EGL_MNDX) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_PLATFORM_EGL(_)
#endif

#if defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_STRUCTURE_TYPES_XR_USE_PLATFORM_WIN32(_) \
    _(XrHolographicWindowAttachmentMSFT, XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT) \


#else
#define XR_LIST_STRUCTURE_TYPES_XR_USE_PLATFORM_WIN32(_)
#endif

#define XR_LIST_STRUCTURE_TYPES(_) \
    XR_LIST_STRUCTURE_TYPES_CORE(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_D3D11(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_D3D12(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_GRAPHICS_API_VULKAN(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_PLATFORM_EGL(_) \
    XR_LIST_STRUCTURE_TYPES_XR_USE_PLATFORM_WIN32(_) \




#define XR_LIST_BASE_STRUCTS(_) \
    _(XrCompositionLayerBaseHeader) \
    _(XrHapticBaseHeader) \
    _(XrSwapchainImageBaseHeader) \
    _(XrSwapchainStateBaseHeaderFB) \
    _(XrLoaderInitInfoBaseHeaderKHR) \
    _(XrEventDataBaseHeader) \


#define XR_LIST_BASE_STRUCT_TYPES_CORE_XrCompositionLayerBaseHeader(_) \
    _(XrCompositionLayerProjection, XR_TYPE_COMPOSITION_LAYER_PROJECTION) \
    _(XrCompositionLayerQuad, XR_TYPE_COMPOSITION_LAYER_QUAD) \
    _(XrCompositionLayerCubeKHR, XR_TYPE_COMPOSITION_LAYER_CUBE_KHR) \
    _(XrCompositionLayerCylinderKHR, XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR) \
    _(XrCompositionLayerEquirectKHR, XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR) \
    _(XrCompositionLayerEquirect2KHR, XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR) \


#if defined(XR_USE_GRAPHICS_API_D3D11)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_D3D11(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_D3D11(_)
#endif

#if defined(XR_USE_GRAPHICS_API_D3D12)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_D3D12(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_D3D12(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WAYLAND)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XCB)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XLIB)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES) && defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_GRAPHICS_API_VULKAN)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_)
#endif

#if defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_PLATFORM_ANDROID(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_PLATFORM_EGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_PLATFORM_EGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_PLATFORM_EGL(_)
#endif

#if defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_PLATFORM_WIN32(_)
#endif



#define XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader(_) \
    XR_LIST_BASE_STRUCT_TYPES_CORE_XrCompositionLayerBaseHeader(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_D3D11(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_D3D12(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_PLATFORM_EGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrCompositionLayerBaseHeader_XR_USE_PLATFORM_WIN32(_) \


#define XR_LIST_BASE_STRUCT_TYPES_CORE_XrHapticBaseHeader(_) \
    _(XrHapticVibration, XR_TYPE_HAPTIC_VIBRATION) \


#if defined(XR_USE_GRAPHICS_API_D3D11)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_D3D11(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_D3D11(_)
#endif

#if defined(XR_USE_GRAPHICS_API_D3D12)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_D3D12(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_D3D12(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WAYLAND)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XCB)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XLIB)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES) && defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_GRAPHICS_API_VULKAN)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_)
#endif

#if defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_PLATFORM_ANDROID(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_PLATFORM_EGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_PLATFORM_EGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_PLATFORM_EGL(_)
#endif

#if defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_PLATFORM_WIN32(_)
#endif



#define XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader(_) \
    XR_LIST_BASE_STRUCT_TYPES_CORE_XrHapticBaseHeader(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_D3D11(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_D3D12(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_PLATFORM_EGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrHapticBaseHeader_XR_USE_PLATFORM_WIN32(_) \


#define XR_LIST_BASE_STRUCT_TYPES_CORE_XrSwapchainImageBaseHeader(_) \


#if defined(XR_USE_GRAPHICS_API_D3D11)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_D3D11(_) \
    _(XrSwapchainImageD3D11KHR, XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_D3D11(_)
#endif

#if defined(XR_USE_GRAPHICS_API_D3D12)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_D3D12(_) \
    _(XrSwapchainImageD3D12KHR, XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_D3D12(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_) \
    _(XrSwapchainImageOpenGLKHR, XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WAYLAND)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XCB)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XLIB)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    _(XrSwapchainImageOpenGLESKHR, XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES) && defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_GRAPHICS_API_VULKAN)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_) \
    _(XrSwapchainImageVulkanKHR, XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_)
#endif

#if defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_PLATFORM_ANDROID(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_PLATFORM_EGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_PLATFORM_EGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_PLATFORM_EGL(_)
#endif

#if defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_PLATFORM_WIN32(_)
#endif



#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader(_) \
    XR_LIST_BASE_STRUCT_TYPES_CORE_XrSwapchainImageBaseHeader(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_D3D11(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_D3D12(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_PLATFORM_EGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainImageBaseHeader_XR_USE_PLATFORM_WIN32(_) \


#define XR_LIST_BASE_STRUCT_TYPES_CORE_XrSwapchainStateBaseHeaderFB(_) \


#if defined(XR_USE_GRAPHICS_API_D3D11)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_D3D11(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_D3D11(_)
#endif

#if defined(XR_USE_GRAPHICS_API_D3D12)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_D3D12(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_D3D12(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WAYLAND)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XCB)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XLIB)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    _(XrSwapchainStateSamplerOpenGLESFB, XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_ES(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES) && defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_GRAPHICS_API_VULKAN)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_VULKAN(_) \
    _(XrSwapchainStateSamplerVulkanFB, XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_VULKAN(_)
#endif

#if defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_PLATFORM_ANDROID(_) \
    _(XrSwapchainStateAndroidSurfaceDimensionsFB, XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_PLATFORM_EGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_PLATFORM_EGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_PLATFORM_EGL(_)
#endif

#if defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_PLATFORM_WIN32(_)
#endif



#define XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB(_) \
    XR_LIST_BASE_STRUCT_TYPES_CORE_XrSwapchainStateBaseHeaderFB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_D3D11(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_D3D12(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_GRAPHICS_API_VULKAN(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_PLATFORM_EGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrSwapchainStateBaseHeaderFB_XR_USE_PLATFORM_WIN32(_) \


#define XR_LIST_BASE_STRUCT_TYPES_CORE_XrLoaderInitInfoBaseHeaderKHR(_) \


#if defined(XR_USE_GRAPHICS_API_D3D11)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_D3D11(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_D3D11(_)
#endif

#if defined(XR_USE_GRAPHICS_API_D3D12)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_D3D12(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_D3D12(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WAYLAND)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XCB)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XLIB)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_ES(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_ES(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES) && defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_GRAPHICS_API_VULKAN)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_VULKAN(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_VULKAN(_)
#endif

#if defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_PLATFORM_ANDROID(_) \
    _(XrLoaderInitInfoAndroidKHR, XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_PLATFORM_EGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_PLATFORM_EGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_PLATFORM_EGL(_)
#endif

#if defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_PLATFORM_WIN32(_)
#endif



#define XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR(_) \
    XR_LIST_BASE_STRUCT_TYPES_CORE_XrLoaderInitInfoBaseHeaderKHR(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_D3D11(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_D3D12(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_GRAPHICS_API_VULKAN(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_PLATFORM_EGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrLoaderInitInfoBaseHeaderKHR_XR_USE_PLATFORM_WIN32(_) \


#define XR_LIST_BASE_STRUCT_TYPES_CORE_XrEventDataBaseHeader(_) \
    _(XrEventDataEventsLost, XR_TYPE_EVENT_DATA_EVENTS_LOST) \
    _(XrEventDataInstanceLossPending, XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING) \
    _(XrEventDataSessionStateChanged, XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED) \
    _(XrEventDataReferenceSpaceChangePending, XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING) \
    _(XrEventDataInteractionProfileChanged, XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED) \
    _(XrEventDataVisibilityMaskChangedKHR, XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR) \
    _(XrEventDataPerfSettingsEXT, XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT) \
    _(XrEventDataMainSessionVisibilityChangedEXTX, XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX) \
    _(XrEventDataDisplayRefreshRateChangedFB, XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB) \


#if defined(XR_USE_GRAPHICS_API_D3D11)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_D3D11(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_D3D11(_)
#endif

#if defined(XR_USE_GRAPHICS_API_D3D12)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_D3D12(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_D3D12(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WAYLAND)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XCB)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL) && defined(XR_USE_PLATFORM_XLIB)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES) && defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_GRAPHICS_API_VULKAN)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_)
#endif

#if defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_PLATFORM_ANDROID(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_PLATFORM_EGL)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_PLATFORM_EGL(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_PLATFORM_EGL(_)
#endif

#if defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_PLATFORM_WIN32(_) \


#else
#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_PLATFORM_WIN32(_)
#endif



#define XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader(_) \
    XR_LIST_BASE_STRUCT_TYPES_CORE_XrEventDataBaseHeader(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_D3D11(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_D3D12(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WAYLAND(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_WIN32(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XCB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_XR_USE_PLATFORM_XLIB(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_OPENGL_ES_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_GRAPHICS_API_VULKAN(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_PLATFORM_EGL(_) \
    XR_LIST_BASE_STRUCT_TYPES_XrEventDataBaseHeader_XR_USE_PLATFORM_WIN32(_) \






#define XR_LIST_BASIC_STRUCTS(_) \
    _(XrApplicationInfo) \
    _(XrSystemGraphicsProperties) \
    _(XrSystemTrackingProperties) \
    _(XrVector3f) \
    _(XrQuaternionf) \
    _(XrPosef) \
    _(XrExtent2Df) \
    _(XrFovf) \
    _(XrActionSuggestedBinding) \
    _(XrVector2f) \
    _(XrActiveActionSet) \
    _(XrOffset2Di) \
    _(XrExtent2Di) \
    _(XrRect2Di) \
    _(XrSwapchainSubImage) \
    _(XrOffset2Df) \
    _(XrRect2Df) \
    _(XrVector4f) \
    _(XrColor4f) \
    _(XrBindingModificationBaseHeaderKHR) \
    _(XrHandJointLocationEXT) \
    _(XrHandJointVelocityEXT) \
    _(XrHandMeshIndexBufferMSFT) \
    _(XrHandMeshVertexMSFT) \
    _(XrHandMeshVertexBufferMSFT) \
    _(XrUuidMSFT) \
    _(XrSceneSphereBoundMSFT) \
    _(XrSceneOrientedBoxBoundMSFT) \
    _(XrSceneFrustumBoundMSFT) \
    _(XrSceneBoundsMSFT) \
    _(XrSceneComponentMSFT) \
    _(XrSceneComponentLocationMSFT) \
    _(XrSceneObjectMSFT) \
    _(XrScenePlaneMSFT) \
    _(XrSceneMeshMSFT) \
    _(XrDeserializeSceneFragmentMSFT) \


#define XR_LIST_EXTENSIONS(_) \
    _(XR_KHR_android_thread_settings, 4) \
    _(XR_KHR_android_surface_swapchain, 5) \
    _(XR_KHR_composition_layer_cube, 7) \
    _(XR_KHR_android_create_instance, 9) \
    _(XR_KHR_composition_layer_depth, 11) \
    _(XR_KHR_vulkan_swapchain_format_list, 15) \
    _(XR_EXT_performance_settings, 16) \
    _(XR_EXT_thermal_query, 17) \
    _(XR_KHR_composition_layer_cylinder, 18) \
    _(XR_KHR_composition_layer_equirect, 19) \
    _(XR_EXT_debug_utils, 20) \
    _(XR_KHR_opengl_enable, 24) \
    _(XR_KHR_opengl_es_enable, 25) \
    _(XR_KHR_vulkan_enable, 26) \
    _(XR_KHR_D3D11_enable, 28) \
    _(XR_KHR_D3D12_enable, 29) \
    _(XR_EXT_eye_gaze_interaction, 31) \
    _(XR_KHR_visibility_mask, 32) \
    _(XR_EXTX_overlay, 34) \
    _(XR_KHR_composition_layer_color_scale_bias, 35) \
    _(XR_KHR_win32_convert_performance_counter_time, 36) \
    _(XR_KHR_convert_timespec_time, 37) \
    _(XR_VARJO_quad_views, 38) \
    _(XR_MSFT_unbounded_reference_space, 39) \
    _(XR_MSFT_spatial_anchor, 40) \
    _(XR_MND_headless, 43) \
    _(XR_OCULUS_android_session_state_enable, 45) \
    _(XR_EXT_view_configuration_depth_range, 47) \
    _(XR_EXT_conformance_automation, 48) \
    _(XR_MNDX_egl_enable, 49) \
    _(XR_MSFT_spatial_graph_bridge, 50) \
    _(XR_MSFT_hand_interaction, 51) \
    _(XR_EXT_hand_tracking, 52) \
    _(XR_MSFT_hand_tracking_mesh, 53) \
    _(XR_MSFT_secondary_view_configuration, 54) \
    _(XR_MSFT_first_person_observer, 55) \
    _(XR_MSFT_controller_model, 56) \
    _(XR_MSFT_perception_anchor_interop, 57) \
    _(XR_EXT_win32_appcontainer_compatible, 58) \
    _(XR_EPIC_view_configuration_fov, 60) \
    _(XR_MSFT_holographic_window_attachment, 64) \
    _(XR_MSFT_composition_layer_reprojection, 67) \
    _(XR_HUAWEI_controller_interaction, 70) \
    _(XR_FB_android_surface_swapchain_create, 71) \
    _(XR_FB_swapchain_update_state, 72) \
    _(XR_VALVE_analog_threshold, 80) \
    _(XR_EXT_hand_joints_motion_range, 81) \
    _(XR_KHR_loader_init, 89) \
    _(XR_KHR_loader_init_android, 90) \
    _(XR_KHR_vulkan_enable2, 91) \
    _(XR_KHR_composition_layer_equirect2, 92) \
    _(XR_EXT_samsung_odyssey_controller, 95) \
    _(XR_EXT_hp_mixed_reality_controller, 96) \
    _(XR_MND_swapchain_usage_input_attachment_bit, 97) \
    _(XR_MSFT_scene_understanding, 98) \
    _(XR_MSFT_scene_understanding_serialization, 99) \
    _(XR_FB_display_refresh_rate, 102) \
    _(XR_HTC_vive_cosmos_controller_interaction, 103) \
    _(XR_FB_color_space, 109) \
    _(XR_KHR_binding_modification, 121) \
    _(XR_VARJO_foveated_rendering, 122) \
    _(XR_VARJO_composition_layer_depth_test, 123) \
    _(XR_VARJO_environment_depth_estimation, 124) \
    _(XR_OCULUS_audio_device_guid, 160) \
    _(XR_FB_swapchain_update_state_android_surface, 162) \
    _(XR_FB_swapchain_update_state_opengl_es, 163) \
    _(XR_FB_swapchain_update_state_vulkan, 164) \





#define XR_LIST_FUNCS_CORE(_) \
    _(xrEnumerateApiLayerProperties,     uint32_t propertyCapacityInput,     uint32_t* propertyCountOutput,     XrApiLayerProperties* properties) \
    _(xrEnumerateInstanceExtensionProperties,     const char* layerName,     uint32_t propertyCapacityInput,     uint32_t* propertyCountOutput,     XrExtensionProperties* properties) \
    _(xrCreateInstance,     const XrInstanceCreateInfo* createInfo,     XrInstance* instance) \
    _(xrDestroyInstance,     XrInstance instance) \
    _(xrGetInstanceProperties,     XrInstance instance,     XrInstanceProperties* instanceProperties) \
    _(xrPollEvent,     XrInstance instance,     XrEventDataBuffer* eventData) \
    _(xrResultToString,     XrInstance instance,     XrResult value,     char buffer[XR_MAX_RESULT_STRING_SIZE]) \
    _(xrStructureTypeToString,     XrInstance instance,     XrStructureType value,     char buffer[XR_MAX_STRUCTURE_NAME_SIZE]) \
    _(xrGetSystem,     XrInstance instance,     const XrSystemGetInfo* getInfo,     XrSystemId* systemId) \
    _(xrGetSystemProperties,     XrInstance instance,     XrSystemId systemId,     XrSystemProperties* properties) \
    _(xrEnumerateEnvironmentBlendModes,     XrInstance instance,     XrSystemId systemId,     XrViewConfigurationType viewConfigurationType,     uint32_t environmentBlendModeCapacityInput,     uint32_t* environmentBlendModeCountOutput,     XrEnvironmentBlendMode* environmentBlendModes) \
    _(xrCreateSession,     XrInstance instance,     const XrSessionCreateInfo* createInfo,     XrSession* session) \
    _(xrDestroySession,     XrSession session) \
    _(xrEnumerateReferenceSpaces,     XrSession session,     uint32_t spaceCapacityInput,     uint32_t* spaceCountOutput,     XrReferenceSpaceType* spaces) \
    _(xrCreateReferenceSpace,     XrSession session,     const XrReferenceSpaceCreateInfo* createInfo,     XrSpace* space) \
    _(xrGetReferenceSpaceBoundsRect,     XrSession session,     XrReferenceSpaceType referenceSpaceType,     XrExtent2Df* bounds) \
    _(xrCreateActionSpace,     XrSession session,     const XrActionSpaceCreateInfo* createInfo,     XrSpace* space) \
    _(xrLocateSpace,     XrSpace space,     XrSpace baseSpace,     XrTime time,     XrSpaceLocation* location) \
    _(xrDestroySpace,     XrSpace space) \
    _(xrEnumerateViewConfigurations,     XrInstance instance,     XrSystemId systemId,     uint32_t viewConfigurationTypeCapacityInput,     uint32_t* viewConfigurationTypeCountOutput,     XrViewConfigurationType* viewConfigurationTypes) \
    _(xrGetViewConfigurationProperties,     XrInstance instance,     XrSystemId systemId,     XrViewConfigurationType viewConfigurationType,     XrViewConfigurationProperties* configurationProperties) \
    _(xrEnumerateViewConfigurationViews,     XrInstance instance,     XrSystemId systemId,     XrViewConfigurationType viewConfigurationType,     uint32_t viewCapacityInput,     uint32_t* viewCountOutput,     XrViewConfigurationView* views) \
    _(xrEnumerateSwapchainFormats,     XrSession session,     uint32_t formatCapacityInput,     uint32_t* formatCountOutput,     int64_t* formats) \
    _(xrCreateSwapchain,     XrSession session,     const XrSwapchainCreateInfo* createInfo,     XrSwapchain* swapchain) \
    _(xrDestroySwapchain,     XrSwapchain swapchain) \
    _(xrEnumerateSwapchainImages,     XrSwapchain swapchain,     uint32_t imageCapacityInput,     uint32_t* imageCountOutput,     XrSwapchainImageBaseHeader* images) \
    _(xrAcquireSwapchainImage,     XrSwapchain swapchain,     const XrSwapchainImageAcquireInfo* acquireInfo,     uint32_t* index) \
    _(xrWaitSwapchainImage,     XrSwapchain swapchain,     const XrSwapchainImageWaitInfo* waitInfo) \
    _(xrReleaseSwapchainImage,     XrSwapchain swapchain,     const XrSwapchainImageReleaseInfo* releaseInfo) \
    _(xrBeginSession,     XrSession session,     const XrSessionBeginInfo* beginInfo) \
    _(xrEndSession,     XrSession session) \
    _(xrRequestExitSession,     XrSession session) \
    _(xrWaitFrame,     XrSession session,     const XrFrameWaitInfo* frameWaitInfo,     XrFrameState* frameState) \
    _(xrBeginFrame,     XrSession session,     const XrFrameBeginInfo* frameBeginInfo) \
    _(xrEndFrame,     XrSession session,     const XrFrameEndInfo* frameEndInfo) \
    _(xrLocateViews,     XrSession session,     const XrViewLocateInfo* viewLocateInfo,     XrViewState* viewState,     uint32_t viewCapacityInput,     uint32_t* viewCountOutput,     XrView* views) \
    _(xrStringToPath,     XrInstance instance,     const char* pathString,     XrPath* path) \
    _(xrPathToString,     XrInstance instance,     XrPath path,     uint32_t bufferCapacityInput,     uint32_t* bufferCountOutput,     char* buffer) \
    _(xrCreateActionSet,     XrInstance instance,     const XrActionSetCreateInfo* createInfo,     XrActionSet* actionSet) \
    _(xrDestroyActionSet,     XrActionSet actionSet) \
    _(xrCreateAction,     XrActionSet actionSet,     const XrActionCreateInfo* createInfo,     XrAction* action) \
    _(xrDestroyAction,     XrAction action) \
    _(xrSuggestInteractionProfileBindings,     XrInstance instance,     const XrInteractionProfileSuggestedBinding* suggestedBindings) \
    _(xrAttachSessionActionSets,     XrSession session,     const XrSessionActionSetsAttachInfo* attachInfo) \
    _(xrGetCurrentInteractionProfile,     XrSession session,     XrPath topLevelUserPath,     XrInteractionProfileState* interactionProfile) \
    _(xrGetActionStateBoolean,     XrSession session,     const XrActionStateGetInfo* getInfo,     XrActionStateBoolean* state) \
    _(xrGetActionStateFloat,     XrSession session,     const XrActionStateGetInfo* getInfo,     XrActionStateFloat* state) \
    _(xrGetActionStateVector2f,     XrSession session,     const XrActionStateGetInfo* getInfo,     XrActionStateVector2f* state) \
    _(xrGetActionStatePose,     XrSession session,     const XrActionStateGetInfo* getInfo,     XrActionStatePose* state) \
    _(xrSyncActions,     XrSession session,     const XrActionsSyncInfo* syncInfo) \
    _(xrEnumerateBoundSourcesForAction,     XrSession session,     const XrBoundSourcesForActionEnumerateInfo* enumerateInfo,     uint32_t sourceCapacityInput,     uint32_t* sourceCountOutput,     XrPath* sources) \
    _(xrGetInputSourceLocalizedName,     XrSession session,     const XrInputSourceLocalizedNameGetInfo* getInfo,     uint32_t bufferCapacityInput,     uint32_t* bufferCountOutput,     char* buffer) \
    _(xrApplyHapticFeedback,     XrSession session,     const XrHapticActionInfo* hapticActionInfo,     const XrHapticBaseHeader* hapticFeedback) \
    _(xrStopHapticFeedback,     XrSession session,     const XrHapticActionInfo* hapticActionInfo) \
    _(xrGetVisibilityMaskKHR,     XrSession session,     XrViewConfigurationType viewConfigurationType,     uint32_t viewIndex,     XrVisibilityMaskTypeKHR visibilityMaskType,     XrVisibilityMaskKHR* visibilityMask) \
    _(xrInitializeLoaderKHR,     const XrLoaderInitInfoBaseHeaderKHR* loaderInitInfo) \
    _(xrPerfSettingsSetPerformanceLevelEXT,     XrSession session,     XrPerfSettingsDomainEXT domain,     XrPerfSettingsLevelEXT level) \
    _(xrThermalGetTemperatureTrendEXT,     XrSession session,     XrPerfSettingsDomainEXT domain,     XrPerfSettingsNotificationLevelEXT* notificationLevel,     float* tempHeadroom,     float* tempSlope) \
    _(xrSetDebugUtilsObjectNameEXT,     XrInstance instance,     const XrDebugUtilsObjectNameInfoEXT* nameInfo) \
    _(xrCreateDebugUtilsMessengerEXT,     XrInstance instance,     const XrDebugUtilsMessengerCreateInfoEXT* createInfo,     XrDebugUtilsMessengerEXT* messenger) \
    _(xrDestroyDebugUtilsMessengerEXT,     XrDebugUtilsMessengerEXT messenger) \
    _(xrSubmitDebugUtilsMessageEXT,     XrInstance instance,     XrDebugUtilsMessageSeverityFlagsEXT messageSeverity,     XrDebugUtilsMessageTypeFlagsEXT messageTypes,     const XrDebugUtilsMessengerCallbackDataEXT* callbackData) \
    _(xrSessionBeginDebugUtilsLabelRegionEXT,     XrSession session,     const XrDebugUtilsLabelEXT* labelInfo) \
    _(xrSessionEndDebugUtilsLabelRegionEXT,     XrSession session) \
    _(xrSessionInsertDebugUtilsLabelEXT,     XrSession session,     const XrDebugUtilsLabelEXT* labelInfo) \
    _(xrCreateSpatialAnchorMSFT,     XrSession session,     const XrSpatialAnchorCreateInfoMSFT* createInfo,     XrSpatialAnchorMSFT* anchor) \
    _(xrCreateSpatialAnchorSpaceMSFT,     XrSession session,     const XrSpatialAnchorSpaceCreateInfoMSFT* createInfo,     XrSpace* space) \
    _(xrDestroySpatialAnchorMSFT,     XrSpatialAnchorMSFT anchor) \
    _(xrSetInputDeviceActiveEXT,     XrSession session,     XrPath interactionProfile,     XrPath topLevelPath,     XrBool32 isActive) \
    _(xrSetInputDeviceStateBoolEXT,     XrSession session,     XrPath topLevelPath,     XrPath inputSourcePath,     XrBool32 state) \
    _(xrSetInputDeviceStateFloatEXT,     XrSession session,     XrPath topLevelPath,     XrPath inputSourcePath,     float state) \
    _(xrSetInputDeviceStateVector2fEXT,     XrSession session,     XrPath topLevelPath,     XrPath inputSourcePath,     XrVector2f state) \
    _(xrSetInputDeviceLocationEXT,     XrSession session,     XrPath topLevelPath,     XrPath inputSourcePath,     XrSpace space,     XrPosef pose) \
    _(xrCreateSpatialGraphNodeSpaceMSFT,     XrSession session,     const XrSpatialGraphNodeSpaceCreateInfoMSFT* createInfo,     XrSpace* space) \
    _(xrCreateHandTrackerEXT,     XrSession session,     const XrHandTrackerCreateInfoEXT* createInfo,     XrHandTrackerEXT* handTracker) \
    _(xrDestroyHandTrackerEXT,     XrHandTrackerEXT handTracker) \
    _(xrLocateHandJointsEXT,     XrHandTrackerEXT handTracker,     const XrHandJointsLocateInfoEXT* locateInfo,     XrHandJointLocationsEXT* locations) \
    _(xrCreateHandMeshSpaceMSFT,     XrHandTrackerEXT handTracker,     const XrHandMeshSpaceCreateInfoMSFT* createInfo,     XrSpace* space) \
    _(xrUpdateHandMeshMSFT,     XrHandTrackerEXT handTracker,     const XrHandMeshUpdateInfoMSFT* updateInfo,     XrHandMeshMSFT* handMesh) \
    _(xrGetControllerModelKeyMSFT,     XrSession session,     XrPath topLevelUserPath,     XrControllerModelKeyStateMSFT* controllerModelKeyState) \
    _(xrGetControllerModelPropertiesMSFT,     XrSession session,     XrControllerModelKeyMSFT modelKey,     XrControllerModelPropertiesMSFT* properties) \
    _(xrGetControllerModelStateMSFT,     XrSession session,     XrControllerModelKeyMSFT modelKey,     XrControllerModelStateMSFT* state) \
    _(xrEnumerateReprojectionModesMSFT,     XrInstance instance,     XrSystemId systemId,     XrViewConfigurationType viewConfigurationType,     uint32_t modeCapacityInput,     uint32_t* modeCountOutput,     XrReprojectionModeMSFT* modes) \
    _(xrUpdateSwapchainFB,     XrSwapchain swapchain,     const XrSwapchainStateBaseHeaderFB* state) \
    _(xrGetSwapchainStateFB,     XrSwapchain swapchain,     XrSwapchainStateBaseHeaderFB* state) \
    _(xrEnumerateSceneComputeFeaturesMSFT,     XrInstance instance,     XrSystemId systemId,     uint32_t featureCapacityInput,     uint32_t* featureCountOutput,     XrSceneComputeFeatureMSFT* features) \
    _(xrCreateSceneObserverMSFT,     XrSession session,     const XrSceneObserverCreateInfoMSFT* createInfo,     XrSceneObserverMSFT* sceneObserver) \
    _(xrDestroySceneObserverMSFT,     XrSceneObserverMSFT sceneObserver) \
    _(xrCreateSceneMSFT,     XrSceneObserverMSFT sceneObserver,     const XrSceneCreateInfoMSFT* createInfo,     XrSceneMSFT* scene) \
    _(xrDestroySceneMSFT,     XrSceneMSFT scene) \
    _(xrComputeNewSceneMSFT,     XrSceneObserverMSFT sceneObserver,     const XrNewSceneComputeInfoMSFT* computeInfo) \
    _(xrGetSceneComputeStateMSFT,     XrSceneObserverMSFT sceneObserver,     XrSceneComputeStateMSFT* state) \
    _(xrGetSceneComponentsMSFT,     XrSceneMSFT scene,     const XrSceneComponentsGetInfoMSFT* getInfo,     XrSceneComponentsMSFT* components) \
    _(xrLocateSceneComponentsMSFT,     XrSceneMSFT scene,     const XrSceneComponentsLocateInfoMSFT* locateInfo,     XrSceneComponentLocationsMSFT* locations) \
    _(xrGetSceneMeshBuffersMSFT,     XrSceneMSFT scene,     const XrSceneMeshBuffersGetInfoMSFT* getInfo,     XrSceneMeshBuffersMSFT* buffers) \
    _(xrDeserializeSceneMSFT,     XrSceneObserverMSFT sceneObserver,     const XrSceneDeserializeInfoMSFT* deserializeInfo) \
    _(xrGetSerializedSceneFragmentDataMSFT,     XrSceneMSFT scene,     const XrSerializedSceneFragmentDataGetInfoMSFT* getInfo,     uint32_t countInput,     uint32_t* readOutput,     uint8_t* buffer) \
    _(xrEnumerateDisplayRefreshRatesFB,     XrSession session,     uint32_t displayRefreshRateCapacityInput,     uint32_t* displayRefreshRateCountOutput,     float* displayRefreshRates) \
    _(xrGetDisplayRefreshRateFB,     XrSession session,     float* displayRefreshRate) \
    _(xrRequestDisplayRefreshRateFB,     XrSession session,     float displayRefreshRate) \
    _(xrEnumerateColorSpacesFB,     XrSession session,     uint32_t colorSpaceCapacityInput,     uint32_t* colorSpaceCountOutput,     XrColorSpaceFB* colorSpaces) \
    _(xrSetColorSpaceFB,     XrSession session,     const XrColorSpaceFB colorspace) \
    _(xrSetEnvironmentDepthEstimationVARJO,     XrSession session,     XrBool32 enabled) \




#if defined(XR_USE_GRAPHICS_API_D3D11)
#define XR_LIST_FUNCS_XR_USE_GRAPHICS_API_D3D11(_) \
    _(xrGetD3D11GraphicsRequirementsKHR,     XrInstance instance,     XrSystemId systemId,     XrGraphicsRequirementsD3D11KHR* graphicsRequirements) \


#else
#define XR_LIST_FUNCS_XR_USE_GRAPHICS_API_D3D11(_)
#endif

#if defined(XR_USE_GRAPHICS_API_D3D12)
#define XR_LIST_FUNCS_XR_USE_GRAPHICS_API_D3D12(_) \
    _(xrGetD3D12GraphicsRequirementsKHR,     XrInstance instance,     XrSystemId systemId,     XrGraphicsRequirementsD3D12KHR* graphicsRequirements) \


#else
#define XR_LIST_FUNCS_XR_USE_GRAPHICS_API_D3D12(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL)
#define XR_LIST_FUNCS_XR_USE_GRAPHICS_API_OPENGL(_) \
    _(xrGetOpenGLGraphicsRequirementsKHR,     XrInstance instance,     XrSystemId systemId,     XrGraphicsRequirementsOpenGLKHR* graphicsRequirements) \


#else
#define XR_LIST_FUNCS_XR_USE_GRAPHICS_API_OPENGL(_)
#endif

#if defined(XR_USE_GRAPHICS_API_OPENGL_ES)
#define XR_LIST_FUNCS_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    _(xrGetOpenGLESGraphicsRequirementsKHR,     XrInstance instance,     XrSystemId systemId,     XrGraphicsRequirementsOpenGLESKHR* graphicsRequirements) \


#else
#define XR_LIST_FUNCS_XR_USE_GRAPHICS_API_OPENGL_ES(_)
#endif

#if defined(XR_USE_GRAPHICS_API_VULKAN)
#define XR_LIST_FUNCS_XR_USE_GRAPHICS_API_VULKAN(_) \
    _(xrGetVulkanInstanceExtensionsKHR,     XrInstance instance,     XrSystemId systemId,     uint32_t bufferCapacityInput,     uint32_t* bufferCountOutput,     char* buffer) \
    _(xrGetVulkanDeviceExtensionsKHR,     XrInstance instance,     XrSystemId systemId,     uint32_t bufferCapacityInput,     uint32_t* bufferCountOutput,     char* buffer) \
    _(xrGetVulkanGraphicsDeviceKHR,     XrInstance instance,     XrSystemId systemId,     VkInstance vkInstance,     VkPhysicalDevice* vkPhysicalDevice) \
    _(xrGetVulkanGraphicsRequirementsKHR,     XrInstance instance,     XrSystemId systemId,     XrGraphicsRequirementsVulkanKHR* graphicsRequirements) \
    _(xrCreateVulkanInstanceKHR,     XrInstance instance,     const XrVulkanInstanceCreateInfoKHR*createInfo,     VkInstance* vulkanInstance,     VkResult* vulkanResult) \
    _(xrCreateVulkanDeviceKHR,     XrInstance instance,     const XrVulkanDeviceCreateInfoKHR* createInfo,     VkDevice* vulkanDevice,     VkResult* vulkanResult) \
    _(xrGetVulkanGraphicsDevice2KHR,     XrInstance instance,     const XrVulkanGraphicsDeviceGetInfoKHR* getInfo,     VkPhysicalDevice* vulkanPhysicalDevice) \


#else
#define XR_LIST_FUNCS_XR_USE_GRAPHICS_API_VULKAN(_)
#endif

#if defined(XR_USE_PLATFORM_ANDROID)
#define XR_LIST_FUNCS_XR_USE_PLATFORM_ANDROID(_) \
    _(xrSetAndroidApplicationThreadKHR,     XrSession session,     XrAndroidThreadTypeKHR threadType,     uint32_t threadId) \
    _(xrCreateSwapchainAndroidSurfaceKHR,     XrSession session,     const XrSwapchainCreateInfo* info,     XrSwapchain* swapchain,     jobject* surface) \


#else
#define XR_LIST_FUNCS_XR_USE_PLATFORM_ANDROID(_)
#endif

#if defined(XR_USE_PLATFORM_WIN32)
#define XR_LIST_FUNCS_XR_USE_PLATFORM_WIN32(_) \
    _(xrConvertWin32PerformanceCounterToTimeKHR,     XrInstance instance,     const LARGE_INTEGER* performanceCounter,     XrTime* time) \
    _(xrConvertTimeToWin32PerformanceCounterKHR,     XrInstance instance,     XrTime time,     LARGE_INTEGER* performanceCounter) \
    _(xrCreateSpatialAnchorFromPerceptionAnchorMSFT,     XrSession session,     IUnknown* perceptionAnchor,     XrSpatialAnchorMSFT* anchor) \
    _(xrTryGetPerceptionAnchorFromSpatialAnchorMSFT,     XrSession session,     XrSpatialAnchorMSFT anchor,     IUnknown** perceptionAnchor) \
    _(xrGetAudioOutputDeviceGuidOculus,     XrInstance instance,     wchar_t buffer[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]) \
    _(xrGetAudioInputDeviceGuidOculus,     XrInstance instance,     wchar_t buffer[XR_MAX_AUDIO_DEVICE_STR_SIZE_OCULUS]) \


#else
#define XR_LIST_FUNCS_XR_USE_PLATFORM_WIN32(_)
#endif

#define XR_LIST_FUNCS(_) \
    XR_LIST_FUNCS_CORE(_) \
    XR_LIST_FUNCS_XR_USE_GRAPHICS_API_D3D11(_) \
    XR_LIST_FUNCS_XR_USE_GRAPHICS_API_D3D12(_) \
    XR_LIST_FUNCS_XR_USE_GRAPHICS_API_OPENGL(_) \
    XR_LIST_FUNCS_XR_USE_GRAPHICS_API_OPENGL_ES(_) \
    XR_LIST_FUNCS_XR_USE_GRAPHICS_API_VULKAN(_) \
    XR_LIST_FUNCS_XR_USE_PLATFORM_ANDROID(_) \
    XR_LIST_FUNCS_XR_USE_PLATFORM_WIN32(_) \


#define XR_LIST_FUNC_xrEnumerateApiLayerProperties(_) \
    _(propertyCapacityInput) \
    _(propertyCountOutput) \


#define XR_LIST_FUNC_xrEnumerateInstanceExtensionProperties(_) \
    _(layerName) \
    _(propertyCapacityInput) \
    _(propertyCountOutput) \


#define XR_LIST_FUNC_xrCreateInstance(_) \
    _(createInfo) \
    _(instance) \


#define XR_LIST_FUNC_xrDestroyInstance(_) \
    _(instance) \


#define XR_LIST_FUNC_xrGetInstanceProperties(_) \
    _(instance) \
    _(instanceProperties) \


#define XR_LIST_FUNC_xrPollEvent(_) \
    _(instance) \
    _(eventData) \


#define XR_LIST_FUNC_xrResultToString(_) \
    _(instance) \
    _(value) \
    _(buffer) \


#define XR_LIST_FUNC_xrStructureTypeToString(_) \
    _(instance) \
    _(value) \
    _(buffer) \


#define XR_LIST_FUNC_xrGetSystem(_) \
    _(instance) \
    _(getInfo) \
    _(systemId) \


#define XR_LIST_FUNC_xrGetSystemProperties(_) \
    _(instance) \
    _(systemId) \
    _(properties) \


#define XR_LIST_FUNC_xrEnumerateEnvironmentBlendModes(_) \
    _(instance) \
    _(systemId) \
    _(viewConfigurationType) \
    _(environmentBlendModeCapacityInput) \
    _(environmentBlendModeCountOutput) \


#define XR_LIST_FUNC_xrCreateSession(_) \
    _(instance) \
    _(createInfo) \
    _(session) \


#define XR_LIST_FUNC_xrDestroySession(_) \
    _(session) \


#define XR_LIST_FUNC_xrEnumerateReferenceSpaces(_) \
    _(session) \
    _(spaceCapacityInput) \
    _(spaceCountOutput) \


#define XR_LIST_FUNC_xrCreateReferenceSpace(_) \
    _(session) \
    _(createInfo) \
    _(space) \


#define XR_LIST_FUNC_xrGetReferenceSpaceBoundsRect(_) \
    _(session) \
    _(referenceSpaceType) \
    _(bounds) \


#define XR_LIST_FUNC_xrCreateActionSpace(_) \
    _(session) \
    _(createInfo) \
    _(space) \


#define XR_LIST_FUNC_xrLocateSpace(_) \
    _(space) \
    _(baseSpace) \
    _(time) \
    _(location) \


#define XR_LIST_FUNC_xrDestroySpace(_) \
    _(space) \


#define XR_LIST_FUNC_xrEnumerateViewConfigurations(_) \
    _(instance) \
    _(systemId) \
    _(viewConfigurationTypeCapacityInput) \
    _(viewConfigurationTypeCountOutput) \


#define XR_LIST_FUNC_xrGetViewConfigurationProperties(_) \
    _(instance) \
    _(systemId) \
    _(viewConfigurationType) \
    _(configurationProperties) \


#define XR_LIST_FUNC_xrEnumerateViewConfigurationViews(_) \
    _(instance) \
    _(systemId) \
    _(viewConfigurationType) \
    _(viewCapacityInput) \
    _(viewCountOutput) \


#define XR_LIST_FUNC_xrEnumerateSwapchainFormats(_) \
    _(session) \
    _(formatCapacityInput) \
    _(formatCountOutput) \


#define XR_LIST_FUNC_xrCreateSwapchain(_) \
    _(session) \
    _(createInfo) \
    _(swapchain) \


#define XR_LIST_FUNC_xrDestroySwapchain(_) \
    _(swapchain) \


#define XR_LIST_FUNC_xrEnumerateSwapchainImages(_) \
    _(swapchain) \
    _(imageCapacityInput) \
    _(imageCountOutput) \


#define XR_LIST_FUNC_xrAcquireSwapchainImage(_) \
    _(swapchain) \
    _(acquireInfo) \
    _(index) \


#define XR_LIST_FUNC_xrWaitSwapchainImage(_) \
    _(swapchain) \
    _(waitInfo) \


#define XR_LIST_FUNC_xrReleaseSwapchainImage(_) \
    _(swapchain) \
    _(releaseInfo) \


#define XR_LIST_FUNC_xrBeginSession(_) \
    _(session) \
    _(beginInfo) \


#define XR_LIST_FUNC_xrEndSession(_) \
    _(session) \


#define XR_LIST_FUNC_xrRequestExitSession(_) \
    _(session) \


#define XR_LIST_FUNC_xrWaitFrame(_) \
    _(session) \
    _(frameWaitInfo) \
    _(frameState) \


#define XR_LIST_FUNC_xrBeginFrame(_) \
    _(session) \
    _(frameBeginInfo) \


#define XR_LIST_FUNC_xrEndFrame(_) \
    _(session) \
    _(frameEndInfo) \


#define XR_LIST_FUNC_xrLocateViews(_) \
    _(session) \
    _(viewLocateInfo) \
    _(viewState) \
    _(viewCapacityInput) \
    _(viewCountOutput) \


#define XR_LIST_FUNC_xrStringToPath(_) \
    _(instance) \
    _(pathString) \
    _(path) \


#define XR_LIST_FUNC_xrPathToString(_) \
    _(instance) \
    _(path) \
    _(bufferCapacityInput) \
    _(bufferCountOutput) \
    _(buffer) \


#define XR_LIST_FUNC_xrCreateActionSet(_) \
    _(instance) \
    _(createInfo) \
    _(actionSet) \


#define XR_LIST_FUNC_xrDestroyActionSet(_) \
    _(actionSet) \


#define XR_LIST_FUNC_xrCreateAction(_) \
    _(actionSet) \
    _(createInfo) \
    _(action) \


#define XR_LIST_FUNC_xrDestroyAction(_) \
    _(action) \


#define XR_LIST_FUNC_xrSuggestInteractionProfileBindings(_) \
    _(instance) \
    _(suggestedBindings) \


#define XR_LIST_FUNC_xrAttachSessionActionSets(_) \
    _(session) \
    _(attachInfo) \


#define XR_LIST_FUNC_xrGetCurrentInteractionProfile(_) \
    _(session) \
    _(topLevelUserPath) \
    _(interactionProfile) \


#define XR_LIST_FUNC_xrGetActionStateBoolean(_) \
    _(session) \
    _(getInfo) \
    _(state) \


#define XR_LIST_FUNC_xrGetActionStateFloat(_) \
    _(session) \
    _(getInfo) \
    _(state) \


#define XR_LIST_FUNC_xrGetActionStateVector2f(_) \
    _(session) \
    _(getInfo) \
    _(state) \


#define XR_LIST_FUNC_xrGetActionStatePose(_) \
    _(session) \
    _(getInfo) \
    _(state) \


#define XR_LIST_FUNC_xrSyncActions(_) \
    _(session) \
    _(syncInfo) \


#define XR_LIST_FUNC_xrEnumerateBoundSourcesForAction(_) \
    _(session) \
    _(enumerateInfo) \
    _(sourceCapacityInput) \
    _(sourceCountOutput) \


#define XR_LIST_FUNC_xrGetInputSourceLocalizedName(_) \
    _(session) \
    _(getInfo) \
    _(bufferCapacityInput) \
    _(bufferCountOutput) \
    _(buffer) \


#define XR_LIST_FUNC_xrApplyHapticFeedback(_) \
    _(session) \
    _(hapticActionInfo) \
    _(hapticFeedback) \


#define XR_LIST_FUNC_xrStopHapticFeedback(_) \
    _(session) \
    _(hapticActionInfo) \


#define XR_LIST_FUNC_xrSetAndroidApplicationThreadKHR(_) \
    _(session) \
    _(threadType) \
    _(threadId) \


#define XR_LIST_FUNC_xrCreateSwapchainAndroidSurfaceKHR(_) \
    _(session) \
    _(info) \
    _(swapchain) \
    _(surface) \


#define XR_LIST_FUNC_xrGetOpenGLGraphicsRequirementsKHR(_) \
    _(instance) \
    _(systemId) \
    _(graphicsRequirements) \


#define XR_LIST_FUNC_xrGetOpenGLESGraphicsRequirementsKHR(_) \
    _(instance) \
    _(systemId) \
    _(graphicsRequirements) \


#define XR_LIST_FUNC_xrGetVulkanInstanceExtensionsKHR(_) \
    _(instance) \
    _(systemId) \
    _(bufferCapacityInput) \
    _(bufferCountOutput) \
    _(buffer) \


#define XR_LIST_FUNC_xrGetVulkanDeviceExtensionsKHR(_) \
    _(instance) \
    _(systemId) \
    _(bufferCapacityInput) \
    _(bufferCountOutput) \
    _(buffer) \


#define XR_LIST_FUNC_xrGetVulkanGraphicsDeviceKHR(_) \
    _(instance) \
    _(systemId) \
    _(vkInstance) \
    _(vkPhysicalDevice) \


#define XR_LIST_FUNC_xrGetVulkanGraphicsRequirementsKHR(_) \
    _(instance) \
    _(systemId) \
    _(graphicsRequirements) \


#define XR_LIST_FUNC_xrGetD3D11GraphicsRequirementsKHR(_) \
    _(instance) \
    _(systemId) \
    _(graphicsRequirements) \


#define XR_LIST_FUNC_xrGetD3D12GraphicsRequirementsKHR(_) \
    _(instance) \
    _(systemId) \
    _(graphicsRequirements) \


#define XR_LIST_FUNC_xrGetVisibilityMaskKHR(_) \
    _(session) \
    _(viewConfigurationType) \
    _(viewIndex) \
    _(visibilityMaskType) \
    _(visibilityMask) \


#define XR_LIST_FUNC_xrConvertWin32PerformanceCounterToTimeKHR(_) \
    _(instance) \
    _(performanceCounter) \
    _(time) \


#define XR_LIST_FUNC_xrConvertTimeToWin32PerformanceCounterKHR(_) \
    _(instance) \
    _(time) \
    _(performanceCounter) \


#define XR_LIST_FUNC_xrConvertTimespecTimeToTimeKHR(_) \
    _(instance) \
    _(timespecTime) \
    _(time) \


#define XR_LIST_FUNC_xrConvertTimeToTimespecTimeKHR(_) \
    _(instance) \
    _(time) \
    _(timespecTime) \


#define XR_LIST_FUNC_xrInitializeLoaderKHR(_) \
    _(loaderInitInfo) \


#define XR_LIST_FUNC_xrCreateVulkanInstanceKHR(_) \
    _(instance) \
    _(createInfo) \
    _(vulkanInstance) \
    _(vulkanResult) \


#define XR_LIST_FUNC_xrCreateVulkanDeviceKHR(_) \
    _(instance) \
    _(createInfo) \
    _(vulkanDevice) \
    _(vulkanResult) \


#define XR_LIST_FUNC_xrGetVulkanGraphicsDevice2KHR(_) \
    _(instance) \
    _(getInfo) \
    _(vulkanPhysicalDevice) \


#define XR_LIST_FUNC_xrPerfSettingsSetPerformanceLevelEXT(_) \
    _(session) \
    _(domain) \
    _(level) \


#define XR_LIST_FUNC_xrThermalGetTemperatureTrendEXT(_) \
    _(session) \
    _(domain) \
    _(notificationLevel) \
    _(tempHeadroom) \
    _(tempSlope) \


#define XR_LIST_FUNC_xrSetDebugUtilsObjectNameEXT(_) \
    _(instance) \
    _(nameInfo) \


#define XR_LIST_FUNC_xrCreateDebugUtilsMessengerEXT(_) \
    _(instance) \
    _(createInfo) \
    _(messenger) \


#define XR_LIST_FUNC_xrDestroyDebugUtilsMessengerEXT(_) \
    _(messenger) \


#define XR_LIST_FUNC_xrSubmitDebugUtilsMessageEXT(_) \
    _(instance) \
    _(messageSeverity) \
    _(messageTypes) \
    _(callbackData) \


#define XR_LIST_FUNC_xrSessionBeginDebugUtilsLabelRegionEXT(_) \
    _(session) \
    _(labelInfo) \


#define XR_LIST_FUNC_xrSessionEndDebugUtilsLabelRegionEXT(_) \
    _(session) \


#define XR_LIST_FUNC_xrSessionInsertDebugUtilsLabelEXT(_) \
    _(session) \
    _(labelInfo) \


#define XR_LIST_FUNC_xrCreateSpatialAnchorMSFT(_) \
    _(session) \
    _(createInfo) \
    _(anchor) \


#define XR_LIST_FUNC_xrCreateSpatialAnchorSpaceMSFT(_) \
    _(session) \
    _(createInfo) \
    _(space) \


#define XR_LIST_FUNC_xrDestroySpatialAnchorMSFT(_) \
    _(anchor) \


#define XR_LIST_FUNC_xrSetInputDeviceActiveEXT(_) \
    _(session) \
    _(interactionProfile) \
    _(topLevelPath) \
    _(isActive) \


#define XR_LIST_FUNC_xrSetInputDeviceStateBoolEXT(_) \
    _(session) \
    _(topLevelPath) \
    _(inputSourcePath) \
    _(state) \


#define XR_LIST_FUNC_xrSetInputDeviceStateFloatEXT(_) \
    _(session) \
    _(topLevelPath) \
    _(inputSourcePath) \
    _(state) \


#define XR_LIST_FUNC_xrSetInputDeviceStateVector2fEXT(_) \
    _(session) \
    _(topLevelPath) \
    _(inputSourcePath) \
    _(state) \


#define XR_LIST_FUNC_xrSetInputDeviceLocationEXT(_) \
    _(session) \
    _(topLevelPath) \
    _(inputSourcePath) \
    _(space) \
    _(pose) \


#define XR_LIST_FUNC_xrCreateSpatialGraphNodeSpaceMSFT(_) \
    _(session) \
    _(createInfo) \
    _(space) \


#define XR_LIST_FUNC_xrCreateHandTrackerEXT(_) \
    _(session) \
    _(createInfo) \
    _(handTracker) \


#define XR_LIST_FUNC_xrDestroyHandTrackerEXT(_) \
    _(handTracker) \


#define XR_LIST_FUNC_xrLocateHandJointsEXT(_) \
    _(handTracker) \
    _(locateInfo) \
    _(locations) \


#define XR_LIST_FUNC_xrCreateHandMeshSpaceMSFT(_) \
    _(handTracker) \
    _(createInfo) \
    _(space) \


#define XR_LIST_FUNC_xrUpdateHandMeshMSFT(_) \
    _(handTracker) \
    _(updateInfo) \
    _(handMesh) \


#define XR_LIST_FUNC_xrGetControllerModelKeyMSFT(_) \
    _(session) \
    _(topLevelUserPath) \
    _(controllerModelKeyState) \


#define XR_LIST_FUNC_xrGetControllerModelPropertiesMSFT(_) \
    _(session) \
    _(modelKey) \
    _(properties) \


#define XR_LIST_FUNC_xrGetControllerModelStateMSFT(_) \
    _(session) \
    _(modelKey) \
    _(state) \


#define XR_LIST_FUNC_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(_) \
    _(session) \
    _(perceptionAnchor) \
    _(anchor) \


#define XR_LIST_FUNC_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(_) \
    _(session) \
    _(anchor) \
    _(perceptionAnchor) \


#define XR_LIST_FUNC_xrEnumerateReprojectionModesMSFT(_) \
    _(instance) \
    _(systemId) \
    _(viewConfigurationType) \
    _(modeCapacityInput) \
    _(modeCountOutput) \


#define XR_LIST_FUNC_xrUpdateSwapchainFB(_) \
    _(swapchain) \
    _(state) \


#define XR_LIST_FUNC_xrGetSwapchainStateFB(_) \
    _(swapchain) \
    _(state) \


#define XR_LIST_FUNC_xrEnumerateSceneComputeFeaturesMSFT(_) \
    _(instance) \
    _(systemId) \
    _(featureCapacityInput) \
    _(featureCountOutput) \


#define XR_LIST_FUNC_xrCreateSceneObserverMSFT(_) \
    _(session) \
    _(createInfo) \
    _(sceneObserver) \


#define XR_LIST_FUNC_xrDestroySceneObserverMSFT(_) \
    _(sceneObserver) \


#define XR_LIST_FUNC_xrCreateSceneMSFT(_) \
    _(sceneObserver) \
    _(createInfo) \
    _(scene) \


#define XR_LIST_FUNC_xrDestroySceneMSFT(_) \
    _(scene) \


#define XR_LIST_FUNC_xrComputeNewSceneMSFT(_) \
    _(sceneObserver) \
    _(computeInfo) \


#define XR_LIST_FUNC_xrGetSceneComputeStateMSFT(_) \
    _(sceneObserver) \
    _(state) \


#define XR_LIST_FUNC_xrGetSceneComponentsMSFT(_) \
    _(scene) \
    _(getInfo) \
    _(components) \


#define XR_LIST_FUNC_xrLocateSceneComponentsMSFT(_) \
    _(scene) \
    _(locateInfo) \
    _(locations) \


#define XR_LIST_FUNC_xrGetSceneMeshBuffersMSFT(_) \
    _(scene) \
    _(getInfo) \
    _(buffers) \


#define XR_LIST_FUNC_xrDeserializeSceneMSFT(_) \
    _(sceneObserver) \
    _(deserializeInfo) \


#define XR_LIST_FUNC_xrGetSerializedSceneFragmentDataMSFT(_) \
    _(scene) \
    _(getInfo) \
    _(countInput) \
    _(readOutput) \


#define XR_LIST_FUNC_xrEnumerateDisplayRefreshRatesFB(_) \
    _(session) \
    _(displayRefreshRateCapacityInput) \
    _(displayRefreshRateCountOutput) \


#define XR_LIST_FUNC_xrGetDisplayRefreshRateFB(_) \
    _(session) \
    _(displayRefreshRate) \


#define XR_LIST_FUNC_xrRequestDisplayRefreshRateFB(_) \
    _(session) \
    _(displayRefreshRate) \


#define XR_LIST_FUNC_xrEnumerateColorSpacesFB(_) \
    _(session) \
    _(colorSpaceCapacityInput) \
    _(colorSpaceCountOutput) \


#define XR_LIST_FUNC_xrSetColorSpaceFB(_) \
    _(session) \
    _(colorspace) \


#define XR_LIST_FUNC_xrSetEnvironmentDepthEstimationVARJO(_) \
    _(session) \
    _(enabled) \


#define XR_LIST_FUNC_xrGetAudioOutputDeviceGuidOculus(_) \
    _(instance) \
    _(buffer) \


#define XR_LIST_FUNC_xrGetAudioInputDeviceGuidOculus(_) \
    _(instance) \
    _(buffer) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateApiLayerProperties(_) \
    _(properties, propertyCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateInstanceExtensionProperties(_) \
    _(properties, propertyCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrCreateInstance(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroyInstance(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetInstanceProperties(_) \


#define XR_LIST_FUNC_ARRAYS_xrPollEvent(_) \


#define XR_LIST_FUNC_ARRAYS_xrResultToString(_) \


#define XR_LIST_FUNC_ARRAYS_xrStructureTypeToString(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetSystem(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetSystemProperties(_) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateEnvironmentBlendModes(_) \
    _(environmentBlendModes, environmentBlendModeCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrCreateSession(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroySession(_) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateReferenceSpaces(_) \
    _(spaces, spaceCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrCreateReferenceSpace(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetReferenceSpaceBoundsRect(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateActionSpace(_) \


#define XR_LIST_FUNC_ARRAYS_xrLocateSpace(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroySpace(_) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateViewConfigurations(_) \
    _(viewConfigurationTypes, viewConfigurationTypeCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrGetViewConfigurationProperties(_) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateViewConfigurationViews(_) \
    _(views, viewCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateSwapchainFormats(_) \
    _(formats, formatCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrCreateSwapchain(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroySwapchain(_) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateSwapchainImages(_) \
    _(images, imageCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrAcquireSwapchainImage(_) \


#define XR_LIST_FUNC_ARRAYS_xrWaitSwapchainImage(_) \


#define XR_LIST_FUNC_ARRAYS_xrReleaseSwapchainImage(_) \


#define XR_LIST_FUNC_ARRAYS_xrBeginSession(_) \


#define XR_LIST_FUNC_ARRAYS_xrEndSession(_) \


#define XR_LIST_FUNC_ARRAYS_xrRequestExitSession(_) \


#define XR_LIST_FUNC_ARRAYS_xrWaitFrame(_) \


#define XR_LIST_FUNC_ARRAYS_xrBeginFrame(_) \


#define XR_LIST_FUNC_ARRAYS_xrEndFrame(_) \


#define XR_LIST_FUNC_ARRAYS_xrLocateViews(_) \
    _(views, viewCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrStringToPath(_) \


#define XR_LIST_FUNC_ARRAYS_xrPathToString(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateActionSet(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroyActionSet(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateAction(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroyAction(_) \


#define XR_LIST_FUNC_ARRAYS_xrSuggestInteractionProfileBindings(_) \


#define XR_LIST_FUNC_ARRAYS_xrAttachSessionActionSets(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetCurrentInteractionProfile(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetActionStateBoolean(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetActionStateFloat(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetActionStateVector2f(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetActionStatePose(_) \


#define XR_LIST_FUNC_ARRAYS_xrSyncActions(_) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateBoundSourcesForAction(_) \
    _(sources, sourceCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrGetInputSourceLocalizedName(_) \


#define XR_LIST_FUNC_ARRAYS_xrApplyHapticFeedback(_) \


#define XR_LIST_FUNC_ARRAYS_xrStopHapticFeedback(_) \


#define XR_LIST_FUNC_ARRAYS_xrSetAndroidApplicationThreadKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateSwapchainAndroidSurfaceKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetOpenGLGraphicsRequirementsKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetOpenGLESGraphicsRequirementsKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetVulkanInstanceExtensionsKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetVulkanDeviceExtensionsKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetVulkanGraphicsDeviceKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetVulkanGraphicsRequirementsKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetD3D11GraphicsRequirementsKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetD3D12GraphicsRequirementsKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetVisibilityMaskKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrConvertWin32PerformanceCounterToTimeKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrConvertTimeToWin32PerformanceCounterKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrConvertTimespecTimeToTimeKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrConvertTimeToTimespecTimeKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrInitializeLoaderKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateVulkanInstanceKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateVulkanDeviceKHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetVulkanGraphicsDevice2KHR(_) \


#define XR_LIST_FUNC_ARRAYS_xrPerfSettingsSetPerformanceLevelEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrThermalGetTemperatureTrendEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrSetDebugUtilsObjectNameEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateDebugUtilsMessengerEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroyDebugUtilsMessengerEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrSubmitDebugUtilsMessageEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrSessionBeginDebugUtilsLabelRegionEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrSessionEndDebugUtilsLabelRegionEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrSessionInsertDebugUtilsLabelEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateSpatialAnchorMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateSpatialAnchorSpaceMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroySpatialAnchorMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrSetInputDeviceActiveEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrSetInputDeviceStateBoolEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrSetInputDeviceStateFloatEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrSetInputDeviceStateVector2fEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrSetInputDeviceLocationEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateSpatialGraphNodeSpaceMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateHandTrackerEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroyHandTrackerEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrLocateHandJointsEXT(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateHandMeshSpaceMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrUpdateHandMeshMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetControllerModelKeyMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetControllerModelPropertiesMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetControllerModelStateMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateReprojectionModesMSFT(_) \
    _(modes, modeCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrUpdateSwapchainFB(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetSwapchainStateFB(_) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateSceneComputeFeaturesMSFT(_) \
    _(features, featureCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrCreateSceneObserverMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroySceneObserverMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrCreateSceneMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrDestroySceneMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrComputeNewSceneMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetSceneComputeStateMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetSceneComponentsMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrLocateSceneComponentsMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetSceneMeshBuffersMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrDeserializeSceneMSFT(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetSerializedSceneFragmentDataMSFT(_) \
    _(buffer, countInput) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateDisplayRefreshRatesFB(_) \
    _(displayRefreshRates, displayRefreshRateCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrGetDisplayRefreshRateFB(_) \


#define XR_LIST_FUNC_ARRAYS_xrRequestDisplayRefreshRateFB(_) \


#define XR_LIST_FUNC_ARRAYS_xrEnumerateColorSpacesFB(_) \
    _(colorSpaces, colorSpaceCapacityInput) \


#define XR_LIST_FUNC_ARRAYS_xrSetColorSpaceFB(_) \


#define XR_LIST_FUNC_ARRAYS_xrSetEnvironmentDepthEstimationVARJO(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetAudioOutputDeviceGuidOculus(_) \


#define XR_LIST_FUNC_ARRAYS_xrGetAudioInputDeviceGuidOculus(_) \


#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateApiLayerProperties(_) \
    _(propertyCapacityInput, propertyCountOutput, properties) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateInstanceExtensionProperties(_) \
    _(layerName, propertyCapacityInput, propertyCountOutput, properties) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateInstance(_) \
    _(createInfo, instance) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroyInstance(_) \
    _(instance) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetInstanceProperties(_) \
    _(instance, instanceProperties) \



#define XR_LIST_FUNC_PARAM_NAMES_xrPollEvent(_) \
    _(instance, eventData) \



#define XR_LIST_FUNC_PARAM_NAMES_xrResultToString(_) \
    _(instance, value, buffer) \



#define XR_LIST_FUNC_PARAM_NAMES_xrStructureTypeToString(_) \
    _(instance, value, buffer) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetSystem(_) \
    _(instance, getInfo, systemId) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetSystemProperties(_) \
    _(instance, systemId, properties) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateEnvironmentBlendModes(_) \
    _(instance, systemId, viewConfigurationType, environmentBlendModeCapacityInput, environmentBlendModeCountOutput, environmentBlendModes) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateSession(_) \
    _(instance, createInfo, session) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroySession(_) \
    _(session) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateReferenceSpaces(_) \
    _(session, spaceCapacityInput, spaceCountOutput, spaces) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateReferenceSpace(_) \
    _(session, createInfo, space) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetReferenceSpaceBoundsRect(_) \
    _(session, referenceSpaceType, bounds) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateActionSpace(_) \
    _(session, createInfo, space) \



#define XR_LIST_FUNC_PARAM_NAMES_xrLocateSpace(_) \
    _(space, baseSpace, time, location) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroySpace(_) \
    _(space) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateViewConfigurations(_) \
    _(instance, systemId, viewConfigurationTypeCapacityInput, viewConfigurationTypeCountOutput, viewConfigurationTypes) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetViewConfigurationProperties(_) \
    _(instance, systemId, viewConfigurationType, configurationProperties) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateViewConfigurationViews(_) \
    _(instance, systemId, viewConfigurationType, viewCapacityInput, viewCountOutput, views) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateSwapchainFormats(_) \
    _(session, formatCapacityInput, formatCountOutput, formats) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateSwapchain(_) \
    _(session, createInfo, swapchain) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroySwapchain(_) \
    _(swapchain) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateSwapchainImages(_) \
    _(swapchain, imageCapacityInput, imageCountOutput, images) \



#define XR_LIST_FUNC_PARAM_NAMES_xrAcquireSwapchainImage(_) \
    _(swapchain, acquireInfo, index) \



#define XR_LIST_FUNC_PARAM_NAMES_xrWaitSwapchainImage(_) \
    _(swapchain, waitInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrReleaseSwapchainImage(_) \
    _(swapchain, releaseInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrBeginSession(_) \
    _(session, beginInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEndSession(_) \
    _(session) \



#define XR_LIST_FUNC_PARAM_NAMES_xrRequestExitSession(_) \
    _(session) \



#define XR_LIST_FUNC_PARAM_NAMES_xrWaitFrame(_) \
    _(session, frameWaitInfo, frameState) \



#define XR_LIST_FUNC_PARAM_NAMES_xrBeginFrame(_) \
    _(session, frameBeginInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEndFrame(_) \
    _(session, frameEndInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrLocateViews(_) \
    _(session, viewLocateInfo, viewState, viewCapacityInput, viewCountOutput, views) \



#define XR_LIST_FUNC_PARAM_NAMES_xrStringToPath(_) \
    _(instance, pathString, path) \



#define XR_LIST_FUNC_PARAM_NAMES_xrPathToString(_) \
    _(instance, path, bufferCapacityInput, bufferCountOutput, buffer) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateActionSet(_) \
    _(instance, createInfo, actionSet) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroyActionSet(_) \
    _(actionSet) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateAction(_) \
    _(actionSet, createInfo, action) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroyAction(_) \
    _(action) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSuggestInteractionProfileBindings(_) \
    _(instance, suggestedBindings) \



#define XR_LIST_FUNC_PARAM_NAMES_xrAttachSessionActionSets(_) \
    _(session, attachInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetCurrentInteractionProfile(_) \
    _(session, topLevelUserPath, interactionProfile) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetActionStateBoolean(_) \
    _(session, getInfo, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetActionStateFloat(_) \
    _(session, getInfo, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetActionStateVector2f(_) \
    _(session, getInfo, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetActionStatePose(_) \
    _(session, getInfo, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSyncActions(_) \
    _(session, syncInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateBoundSourcesForAction(_) \
    _(session, enumerateInfo, sourceCapacityInput, sourceCountOutput, sources) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetInputSourceLocalizedName(_) \
    _(session, getInfo, bufferCapacityInput, bufferCountOutput, buffer) \



#define XR_LIST_FUNC_PARAM_NAMES_xrApplyHapticFeedback(_) \
    _(session, hapticActionInfo, hapticFeedback) \



#define XR_LIST_FUNC_PARAM_NAMES_xrStopHapticFeedback(_) \
    _(session, hapticActionInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSetAndroidApplicationThreadKHR(_) \
    _(session, threadType, threadId) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateSwapchainAndroidSurfaceKHR(_) \
    _(session, info, swapchain, surface) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetOpenGLGraphicsRequirementsKHR(_) \
    _(instance, systemId, graphicsRequirements) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetOpenGLESGraphicsRequirementsKHR(_) \
    _(instance, systemId, graphicsRequirements) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetVulkanInstanceExtensionsKHR(_) \
    _(instance, systemId, bufferCapacityInput, bufferCountOutput, buffer) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetVulkanDeviceExtensionsKHR(_) \
    _(instance, systemId, bufferCapacityInput, bufferCountOutput, buffer) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetVulkanGraphicsDeviceKHR(_) \
    _(instance, systemId, vkInstance, vkPhysicalDevice) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetVulkanGraphicsRequirementsKHR(_) \
    _(instance, systemId, graphicsRequirements) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetD3D11GraphicsRequirementsKHR(_) \
    _(instance, systemId, graphicsRequirements) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetD3D12GraphicsRequirementsKHR(_) \
    _(instance, systemId, graphicsRequirements) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetVisibilityMaskKHR(_) \
    _(session, viewConfigurationType, viewIndex, visibilityMaskType, visibilityMask) \



#define XR_LIST_FUNC_PARAM_NAMES_xrConvertWin32PerformanceCounterToTimeKHR(_) \
    _(instance, performanceCounter, time) \



#define XR_LIST_FUNC_PARAM_NAMES_xrConvertTimeToWin32PerformanceCounterKHR(_) \
    _(instance, time, performanceCounter) \



#define XR_LIST_FUNC_PARAM_NAMES_xrConvertTimespecTimeToTimeKHR(_) \
    _(instance, timespecTime, time) \



#define XR_LIST_FUNC_PARAM_NAMES_xrConvertTimeToTimespecTimeKHR(_) \
    _(instance, time, timespecTime) \



#define XR_LIST_FUNC_PARAM_NAMES_xrInitializeLoaderKHR(_) \
    _(loaderInitInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateVulkanInstanceKHR(_) \
    _(instance, createInfo, vulkanInstance, vulkanResult) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateVulkanDeviceKHR(_) \
    _(instance, createInfo, vulkanDevice, vulkanResult) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetVulkanGraphicsDevice2KHR(_) \
    _(instance, getInfo, vulkanPhysicalDevice) \



#define XR_LIST_FUNC_PARAM_NAMES_xrPerfSettingsSetPerformanceLevelEXT(_) \
    _(session, domain, level) \



#define XR_LIST_FUNC_PARAM_NAMES_xrThermalGetTemperatureTrendEXT(_) \
    _(session, domain, notificationLevel, tempHeadroom, tempSlope) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSetDebugUtilsObjectNameEXT(_) \
    _(instance, nameInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateDebugUtilsMessengerEXT(_) \
    _(instance, createInfo, messenger) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroyDebugUtilsMessengerEXT(_) \
    _(messenger) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSubmitDebugUtilsMessageEXT(_) \
    _(instance, messageSeverity, messageTypes, callbackData) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSessionBeginDebugUtilsLabelRegionEXT(_) \
    _(session, labelInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSessionEndDebugUtilsLabelRegionEXT(_) \
    _(session) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSessionInsertDebugUtilsLabelEXT(_) \
    _(session, labelInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateSpatialAnchorMSFT(_) \
    _(session, createInfo, anchor) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateSpatialAnchorSpaceMSFT(_) \
    _(session, createInfo, space) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroySpatialAnchorMSFT(_) \
    _(anchor) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSetInputDeviceActiveEXT(_) \
    _(session, interactionProfile, topLevelPath, isActive) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSetInputDeviceStateBoolEXT(_) \
    _(session, topLevelPath, inputSourcePath, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSetInputDeviceStateFloatEXT(_) \
    _(session, topLevelPath, inputSourcePath, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSetInputDeviceStateVector2fEXT(_) \
    _(session, topLevelPath, inputSourcePath, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSetInputDeviceLocationEXT(_) \
    _(session, topLevelPath, inputSourcePath, space, pose) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateSpatialGraphNodeSpaceMSFT(_) \
    _(session, createInfo, space) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateHandTrackerEXT(_) \
    _(session, createInfo, handTracker) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroyHandTrackerEXT(_) \
    _(handTracker) \



#define XR_LIST_FUNC_PARAM_NAMES_xrLocateHandJointsEXT(_) \
    _(handTracker, locateInfo, locations) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateHandMeshSpaceMSFT(_) \
    _(handTracker, createInfo, space) \



#define XR_LIST_FUNC_PARAM_NAMES_xrUpdateHandMeshMSFT(_) \
    _(handTracker, updateInfo, handMesh) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetControllerModelKeyMSFT(_) \
    _(session, topLevelUserPath, controllerModelKeyState) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetControllerModelPropertiesMSFT(_) \
    _(session, modelKey, properties) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetControllerModelStateMSFT(_) \
    _(session, modelKey, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateSpatialAnchorFromPerceptionAnchorMSFT(_) \
    _(session, perceptionAnchor, anchor) \



#define XR_LIST_FUNC_PARAM_NAMES_xrTryGetPerceptionAnchorFromSpatialAnchorMSFT(_) \
    _(session, anchor, perceptionAnchor) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateReprojectionModesMSFT(_) \
    _(instance, systemId, viewConfigurationType, modeCapacityInput, modeCountOutput, modes) \



#define XR_LIST_FUNC_PARAM_NAMES_xrUpdateSwapchainFB(_) \
    _(swapchain, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetSwapchainStateFB(_) \
    _(swapchain, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateSceneComputeFeaturesMSFT(_) \
    _(instance, systemId, featureCapacityInput, featureCountOutput, features) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateSceneObserverMSFT(_) \
    _(session, createInfo, sceneObserver) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroySceneObserverMSFT(_) \
    _(sceneObserver) \



#define XR_LIST_FUNC_PARAM_NAMES_xrCreateSceneMSFT(_) \
    _(sceneObserver, createInfo, scene) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDestroySceneMSFT(_) \
    _(scene) \



#define XR_LIST_FUNC_PARAM_NAMES_xrComputeNewSceneMSFT(_) \
    _(sceneObserver, computeInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetSceneComputeStateMSFT(_) \
    _(sceneObserver, state) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetSceneComponentsMSFT(_) \
    _(scene, getInfo, components) \



#define XR_LIST_FUNC_PARAM_NAMES_xrLocateSceneComponentsMSFT(_) \
    _(scene, locateInfo, locations) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetSceneMeshBuffersMSFT(_) \
    _(scene, getInfo, buffers) \



#define XR_LIST_FUNC_PARAM_NAMES_xrDeserializeSceneMSFT(_) \
    _(sceneObserver, deserializeInfo) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetSerializedSceneFragmentDataMSFT(_) \
    _(scene, getInfo, countInput, readOutput, buffer) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateDisplayRefreshRatesFB(_) \
    _(session, displayRefreshRateCapacityInput, displayRefreshRateCountOutput, displayRefreshRates) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetDisplayRefreshRateFB(_) \
    _(session, displayRefreshRate) \



#define XR_LIST_FUNC_PARAM_NAMES_xrRequestDisplayRefreshRateFB(_) \
    _(session, displayRefreshRate) \



#define XR_LIST_FUNC_PARAM_NAMES_xrEnumerateColorSpacesFB(_) \
    _(session, colorSpaceCapacityInput, colorSpaceCountOutput, colorSpaces) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSetColorSpaceFB(_) \
    _(session, colorspace) \



#define XR_LIST_FUNC_PARAM_NAMES_xrSetEnvironmentDepthEstimationVARJO(_) \
    _(session, enabled) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetAudioOutputDeviceGuidOculus(_) \
    _(instance, buffer) \



#define XR_LIST_FUNC_PARAM_NAMES_xrGetAudioInputDeviceGuidOculus(_) \
    _(instance, buffer) \



#endif

