# About the Oculus XR Plugin

The Oculus XR Plugin enables you to build applications for a variety of Oculus devices including the Rift, Rift S, Quest, and Quest 2.

## Supported XR plugin subsystems

### Display 

The display subsystem provides stereo rendering support for the XR Plugin. It supports the following graphics APIs:

* Windows (Rift, Rift S)
    * DX11
* Android (Quest, Quest 2)
    * OpenGL ES 3.0
    * Vulkan (Quest/Quest 2, experimental in Unity versions prior to 2021.2)

### Input 

The input subsystem provides controller support, haptics, and tracking for the controllers and HMD.

## XR Management support

Integration with XR Management isn't required to use the Oculus XR Plugin, but it provides for a simpler and easier way of using this and other Providers within Unity. The Oculus XR Plugin package ships with built-in XR Management support. For more information, see [XR Management Documention](https://docs.unity3d.com/Packages/com.unity.xr.management@latest)

The Oculus XR Plugin integration with XR Management provides the following functionality:

* **Runtime Settings** - Configure runtime settings such as rendering modes, depth buffer sharing, Dash support, etc.
* **Lifecycle Management** - The Oculus XR Plugin ships with a default XR Plugin loader implementation that handles subsystem lifecycle such as application initialization, shutdown, pausing, and resuming.

### Windows standalone settings (Rift, Rift S)

* **Stereo Rendering Mode** - You can select *Multi Pass* or *Single Pass Instanced* stereo rendering mode.
	* *Multi Pass* - Unity renders each eye independently by making two passes across the scene graph. Each pass has its own eye matrices and render target. Unity draws everything twice, which includes setting the graphics state for each pass. This is a slow and simple rendering method which doesn't require any special modification to shaders.
	* *Single Pass Instanced* - Unity uses a texture array with two slices, and uses instanced draw calls (converting non-instanced draws call to instanced versions when necessary) to direct rendering to the appropriate texture slice.  Custom shaders need to be modified for rendering in this mode.  Use Unity's XR shader macros to simplify authoring custom shaders. 
* **Shared Depth Buffer** - Enable or disable support for using a shared depth buffer. This allows Unity and Oculus to use a common depth buffer, which enables Oculus to composite the Oculus Dash and other utilities over the Unity application.
* **Dash Support** - Enable or disable Dash support. This inintializes the Oculus Plugin with Dash support, which enables the Oculus Dash to composite over the Unity application.

### Android settings (Quest, Quest 2)

* **Stereo Rendering Mode** - You can select *Multi Pass* or *Multiview* stereo rendering mode.
	* *Multi Pass* - Unity renders each eye independently by making two passes across the scene graph. Each pass has its own eye matrices and render target. Unity draws everything twice, which includes setting the graphics state for each pass. This is a slow and simple rendering method which doesn't require any special modification to shaders.
	* *Multiview* - Multiview is essentially the same as the *Single Pass Instanced* option described above, except the graphics driver does the draw call conversion, requiring less work from the Unity engine. As with *Single Pass Instanced*, shaders need to be authored to enable Multiview.  Using Unity's XR shader macros will simplify custom shader development.
* **Low Overhead Mode** - If enabled, the GLES graphics driver will bypass validation code, potentially running faster. Disable this if you experience graphics instabilities. GLES only.
* **Optimize Buffer Discards** - If enabled, the depth buffer contents will be discarded rather than resolved and the MSAA color buffer will be resolved rather than stored after rendering. This is a performance optimization that can possibly break rendering effects that sample from the depth buffer, such as camera stacking. Vulkan only.
* **Phase Sync** - This enables a latency optimization technique which can reduce simulation latency by several ms, depending on application workload. This is currently disabled by default, but we encourage trying it with your projects.
* **System Splash Screen** - You can add a PNG under the Assets folder as the splash screen image. If set, Oculus OS will display the system splash screen as a high quality compositor layer as soon as the app is starting to launch until the app submits the first frame.
* **Subsampled Layout** - If enabled, the eye textures will use a subsampled layout. When using FFR, the subsampled layout will improve app GPU performance and reduce FFR-related visual artifacts. However, this feature will slightly increase the GPU cost of Timewarp. Therefore, we only recommend enabling it if the app is using FFR level 2 or higher, in which case, the app GPU performance improvement should outweigh the extra Timewarp cost. Vulkan and Quest 2 only. Note that this requires Unity 2020.3.11f1 or 2021.1.9f1 or higher, and will result in a black screen if enabled on earlier versions of Unity.

## Technical details

### Fixed-Foveated Rendering (FFR)

Quest and Quest 2 support [fixed-foveated rendering](https://developer.oculus.com/documentation/quest/latest/concepts/mobile-ffr/) to provide better performance for [pixel-fill limited](https://en.wikipedia.org/wiki/Fillrate) applications. Controlling the level of foveation is made available through APIs in the Oculus XR Plugin.

FFR works best when rendering directly into the *eye textures* using the [foward rendering mode](https://docs.unity3d.com/Manual/RenderTech-ForwardRendering.html).  [*Deferred rendering* mode](https://docs.unity3d.com/Manual/RenderTech-DeferredShading.html), which is characterized by rendering into an intermediate render texture, is not recommended for use with FFR. This situation arises often when using the default *Universal Rendering Pipeline*, which includes a blit operation by default at the end of the frame. 

### Vulkan

As of Unity 2021.2, Vulkan support for Oculus Quest and Quest 2 is no longer considered experimental. The implementation supports multiview rendering and fixed-foveated rendering, and is only supported on Quest and Quest 2.

In versions of Unity prior to 2021.2, Vulkan will be disabled by default. To enable Vulkan on those versions, follow the steps below:

* Open the **Project Settings** window (menu: **Edit > Project Settings**), and select **Player**.
* Under the **Android** settings, add and move **Vulkan** to the top of the list of **Graphic APIs** so that it is selected ahead of others.

Note that unless otherwise modified, OpenGL ES 3.0 is the default graphics API used in Unity versions prior to 2021.2.
