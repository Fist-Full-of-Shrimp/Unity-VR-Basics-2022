# Changelog
All notable changes to this package will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [1.11.2] - 2021-12-13
### Fixed
- Changed how init code finds the Unity Surface View to fix an issue related to recent core engine changes

## [1.11.1] - 2021-11-14
### Changed
- Updated Oculus plugins to v34 non-OpenXR
- Modified Oculus plugin initialization on D3D11
- Updated XR Management dependency to 4.2.0

## [1.11.0] - 2021-10-05
### Changed
- Vulkan is no longer experimental for Oculus on Android in Unity 2021.2 and higher, and will no longer be removed from your graphics settings in those versions
- Updated Vulkan docs to reflect the above

## [1.10.1-preview.3] - 2021-09-29
### Changed
- Updated Oculus plugins to v33 non-OpenXR
- Updated AudioSpatializer plugins to v33

### Fixed
- Fixed an issue where eye textures were the incorrect resolution on Rift
- Resolved an issue with configuring FFR when using the OpenXR backend

## [1.10.0] - 2021-07-08
### Changed
No changes since 1.10.0-preview.2

## [1.10.0-preview.2] - 2021-07-08
### Added
- Added `SystemHeadset GetSystemHeadsetType()` to query the active headset type at runtime
- Added the Subsampled Layout option for Vulkan on Quest 2.  Requires Unity 2020.3.11f1 or 2021.1.9f1 or higher, and will result in a black screen if enabled on earlier versions of Unity

### Changed
- Added the Mac audio spatializer plugin back in now that it no longer crashes on M1 based Macs
- Updated Oculus plugins to 1.57.0
- Updated AudioSpatializer plugins to 1.57.0
- Moved updated Oculus library licensing information into `Third Party Notices.md`
- Updated `LICENSE.md`

### Fixed
- Fixed issue when Link disconnected and reconnected while in play mode, a black screen in headset occurred when reentering play mode

## [1.10.0-preview.1] - 2021-05-19
### Added
- Added `event Action InputFocusAcquired` and `event Action InputFocusLost` in `class InputFocus` to detect Oculus input focus when the Universal menu is open or closed
- Added system splash screen support for Quest. Oculus OS will display the system splash screen as a high quality compositor layer as soon as the app is starting to launch until the app submits the first frame

### Fixed
- Fixed issue #1325113, where hand tracking was not working on Quest/Quest 2 when the Unity splash screen was disabled
- Fixed related script initialization timing issues where some calls failed on the first frame but would succeed later

## [1.9.1] - 2021-04-23
### Changed
No changes since 1.9.1-preview.2

## [1.9.1-preview.2] - 2021-04-15
### Fixed
- Fixed issue #1324560, a potential PC crash with certain audio input and/or output device configurations
- Fixed DllNotFoundException error when running standalone players with the Oculus XR Plugin installed but disabled in the loader list
- Fixed an OculusUnity.java compile error when targeting Android API lower than 26

## [1.9.0] - 2021-03-18
### Changed
No changes since 1.9.0-preview.1

## [1.9.0-preview.1] - 2021-03-15
### Added
- Added `bool EnableDynamicFFR(bool enable)` to enable dynamic FFR.  This should be combined with `SetFoveationLevel()` to enable dynamic FFR

### Changed
- FFR APIs still log when called on desktop, but it is now a warning rather than an error.  Conditionally compile out FFR code on non-Android to avoid the messages

### Fixed
- Fixed issue #1300651, where the Oculus XR Plugin would crash with apps built into folders with non-ASCII characters in the path
- Fixed an editor crash when entering playmode with a non-DX11 graphics device
- Fixed `[XR] Error determining if we should quit: Not Initialized` log spam when the runtime fails to initialize

## [1.8.1] - 2021-02-01
### Changed
- Enabling the Oculus Android loader will automatically set the Minimum API Level setting to 23
- Updated XR Management dependency to 4.0.1

## [1.7.0] - 2020-12-10
### Changed
No changes since 1.7.0-preview.2

## [1.7.0-preview.2] - 2020-12-09
### Added
- Added target devices to the Android settings. These are used to configure the supported devices list in the Android manifest. For example, enabling Quest 2 will allow 80/90Hz refresh rates on Quest 2
- Added `bool TryGetAvailableDisplayRefreshRates(out float[] refreshRates)`
- Added `bool TrySetDisplayRefreshRate(float refreshRate)`
- Added `bool TryGetDisplayRefreshRate(out float refreshRate)`

### Fixed
- Fixed `XRDevice.refreshRate` not updating correctly
- Fixed `indexTouch` and `thumbTouch` usages always returning false
- Removed the Mac audio spatializer plugin to work around a crash on startup on M1 based Macs

## [1.7.0-preview.1] - 2020-11-30
### Added
- Added `Phase Sync` option on Android. This enables a latency optimization technique which can reduce simulation latency by several ms, depending on application workload. This is currently disabled by default, but we encourage trying it with your projects
- Added Unity Profiler marker for `OculusRuntime.WaitToBeginFrame` to clarify time spent waiting for frame sync. Note that this marker is only visible in Unity 2020.1+ since the profiler plugin interface is not available in 2019.4

### Changed
- Updated to Oculus plugin 1.55.0
- Updated AudioSpatializer plugins to 1.55.0

### Removed
- Removed `Focus Aware` option since it's now always on by default
- Removed `Protected Context` option since it only applied to Go

## [1.6.1] - 2020-11-09
### Changed
- XR Management dependency changed to 3.2.16

## [1.6.0-preview.2] - 2020-10-29
### Changed
- Updated AudioSpatializer plugins to 1.52.0
- Added more clarifying text if the Oculus XR Plugin fails to initialize on Windows

### Fixed
- Fixed various AudioSpatializer .meta settings and Mac editor support

## [1.6.0-preview.1] - 2020-10-23
### Added
- Added `bool Unity.XR.Oculus.Boundary.GetBoundaryConfigured()`
- Added `bool Unity.XR.Oculus.Boundary.GetBoundaryDimensions(BoundaryType boundaryType, out Vector3 dimensions)`
- Added `bool Unity.XR.Oculus.Boundary.GetBoundaryVisible()`
- Added `void Unity.XR.Oculus.Boundary.SetBoundaryVisible(bool boundaryVisible)`
- Added `void Unity.XR.Oculus.Development.TrySetDeveloperMode(bool enable)` to enable extra Oculus runtime stats.  This is enabled by default in development builds

### Changed
- Updated to Oculus plugin 1.52.0.  Note that this removes support for Go.  If you still need to support Go, please use the integrated VR support in 2019.4 LTS, or use package version 1.5.0
- Removed the Android V2 signing setting
- If the Oculus provider is enabled for Android, generated .apk files will no longer attempt to run on non-Oculus Android devices.  If you need this to work, consider scripting general Android builds to disable Oculus for that build

### Fixed
- Important classes are no longer stripped from Android builds if Minify is set to Proguard in the Android player settings
- Fixed DllImport errors by guarding dllimport calls on unsupported platforms
- Fixed Quest haptics not lasting for their intended duration
- Made the Oculus Dash app termination code more cross platform friendly
- Fixed the build processor to handle scripted build targets correctly
- Fixed `GetLocalTrackingSpaceRecenterCount` log spam
- Fixed incorrect check for DX11 setting when building Mac standalone

## [1.5.0] - 2020-09-23
### Added
- Added **Optimize Buffer Discards** setting for Vulkan.  This prevents depth and MSAA buffers from being resolved, improving GPU performance

### Changed
- Added support for detecting if the application has been closed via the Oculus Dash

### Fixed
- Oculus libraries are no longer added to player builds when Oculus loader isn't enabled for the target
- The BLUETOOTH permission is no longer added to the Android manifest when the Microphone class is used in a project
- The plugin no longer attempts to initialize when playing in editor on unsupported platforms (Mac/Linux)
- User audio configuration changes at runtime on PC are now respected
- Fixed incorrect manufacturer and removed placeholder serial number information on tracked devices

## [1.4.3] - 2020-08-07
### Changed
- Updated to Oculus plugin 1.51.1
- Changed the timing of loading and initializing the Oculus plugin

### Fixed
- Fixed `ScreenCapture.CaptureScreenshot()`
- Fixed a potential crash in eye texture creation

## [1.4.0] - 2020-07-07
### Added
- Added Oculus intent filter to the Android manifest

### Changed
- Bumped the Minimum API Level check up to 23

### Fixed
- Fixed a crash when initializing/deinitializing the loader multiple times at runtime

## [1.4.0-preview.2] - 2020-07-02
### Added
- Mobile settings now support Focus Aware mode, which is enabled by default

### Changed
- Updated to Oculus plugin 1.49
- Oculus plugin is now dynamically loaded
- Vulkan swapchain improvements

### Fixed
- Go controller mappings weren't displaying correctly when using the Input System

## [1.4.0-preview.1] - 2020-06-05
### Added
- Added `int Unity.XR.Oculus.Utils.GetFoveationLevel` to retrieve the current FFR setting for mobile
- Added `bool Unity.XR.Oculus.Performance.TrySetCPULevel(int level)` for mobile
- Added `bool Unity.XR.Oculus.Performance.TrySetGPULevel(int level)` for mobile
- Added **Low Overhead Mode** setting for mobile
- Added **Protected Context** setting for mobile

### Changed
- Consolidated changelog to remove versions that were never publicly released

### Fixed
- Fixed an extraneous blit on mobile
- Added correct display names for Oculus devices in the Input System
- Fixed compiler warnings in DeviceLayouts.cs when using Input System 1.0.0+

## [1.3.4] - 2020-05-12
### Changed
- When Oculus Android is enabled in XR Management, Vulkan is removed from the Android graphics API list. It can manually be added back in to the list

### Fixed
- Stats.PluginVersion wasn't properly null terminating the version string. It is now the correct length

## [1.3.3] - 2020-04-08
### Changed
- Change XR Management dependency to 3.0.6 to resolve a package manager issue

### Fixed
- Fixed a breaking change involving an incompatibility with versions of XR Management earlier than 3.2.4

## [1.3.1] - 2020-04-03
### Changed
- Updated XR Management dependency to 3.2.4

## [1.3.0] - 2020-03-16
### Changed
- Minor version bump to add a loader callback API method
- Updated XR Management dependency to 3.2.0
- Renamed Oculus loader
- Implement XR Management Metadata interfaces

## [1.2.0] - 2020-02-25
### Changed
- Remove preview tag

### Fixed
- Add missing release notes for 1.1.5

## [1.2.0-preview.1] - 2020-02-14
### Added
- Public foveation setting API
- Public Oculus statistics APIs
- Improved recentering support

### Changed
- Cleans up plugin graphics thread lifecylce
- Cleans up documentation
- Updated to Oculus plugin 1.44

### Fixed
- Fixed a crash on exit when using single threaded rendering
- Fixed BeginFrame log spew

## [1.1.5] - 2019-12-20
### Changed
- Cleans up documentation

## [1.1.5-preview] - 2019-12-19
### Changed
- Cleans up plugin graphics thread lifecylce

### Fixed
- Fixed a manifest merging issue with the 1.44 Oculus Integration assets

## [1.1.4] - 2019-12-13
- No changes, version rev only

## [1.1.4-preview.1] - 2019-12-12
### Changed
- Expands internal performance profiling tooling
- Re-enables GLES2

### Fixed
- [Quest] Fixes an issue where resting then waking the device with the power button caused a black screen in the application (v12 Quest runtime and up) 

## [1.1.4-preview] - 2019-12-03
### Fixed
- Occlusion mesh no longer renders in the preview view unless requested by the user
- Fixed an issue where some entries in a custom AndroidManifest.xml were getting removed when V2 signing was enabled

## [1.1.3-preview.1] - 2019-11-27
### Fixed
- Fixes a crash that occured when building an app without the Android loader in the XR Management list

## [1.1.3-preview] - 2019-11-27
### Added
- Adds FFR hookup for Quest with Vulkan 

## [1.1.2] - 2019-11-25
### Changed
- Updated documentation
- Updated minimum Unity version required (for Vulkan support)

## [1.1.2-preview] - 2019-11-25
### Added
- Enables Vulkan support on Quest and Go
- Provider now uses correct occlusion mesh

### Known Issues
- Vulkan on Quest does not currently support Multiview, this will be supported in a later release of the Unity Editor
- FFR on Vulkan on Quest is not currently supported, this feature will be supported in a later release of the Unity Editor

## [1.1.1] - 2019-11-21
### Changed
- Updated XR Management dependency to 3.0.4
- Updated to Oculus plugin 1.41
- Increased the callbackOrder on the Android build processor script so that other scripts can execute first if need be
- Renamed plugin libraries and cleaned up various error messages

### Fixed
- Viewport scale in the mirror view now uses scaled UVs
- Fixed a potential manifest collision issue when using v2 signing

## [1.1.0] - 2019-10-17
- Version bump to 1.1.0, no changes

## [1.1.0-preview] - 2019-10-17
### Changed
- Minor version bump for new backwards compatible functionality (color scale API, input subsystem layouts)

## [1.0.3-preview.1] - 2019-10-15
### Fixed
- Thread safe color scale
- Screenshot artifacts with SPI

## [1.0.3-preview] - 2019-09-27
### Added
- Color scale and offset api and helper class
- More Oculus statistics (accessible via display subsystem api)
- User presence usage when using new input system 

### Changed
- Disables main framebuffer flag to save memory (~36MB on Quest)
- Input subsystem layouts to package

### Fixed
- Fixed MSAA issues on Quest
- Fixed side-by-side screenshot functionality

## [1.0.2] - 2019-09-03
### Added
- V2 signing checkbox for properly signed APKs on Quest

### Changed
- XR Plugin Management dependency

### Fixed
- Input bugs
  - Go reported sceondary button when it should have reported a menu button
  - Quest and Rift S reported a thumbrest when they did not have one
  - Oculus Remote would never connect
- Timing issues upon pausing/resuming app on standalone HMDs

## [1.0.0] - 2019-07-10
### Added
- Oculus audio spatializer plugin

### Changed
- Removed preview tag
- Update XR Management dependency version
- Migrate away from the Experience subsystem
- Update Boundary Points when recentering and changing the tracking space origin mode
- Fixed spatializer .meta files
- Updated to Oculus plugin 1.37

## [0.8.4-preview] - 2019-06-10
### Added
- Single Pass Instancing support for PC DX11
- Rendering and input support
- Arm64 support for mobile builds
- Depth support
- Render viewport scale
- Eye texture resolution scale
- Culling pose pullback
- Win32 compatibility
- Updates minimum unity version to 2019.2
- Input tracking reference node reporting
- Updates to Oculus plugin 1.34
- XRStats support
- Device relative eye positions
- Recenter functionality
- Registration of tracking references
- Moved tests to a package
- Haptics Functionality
