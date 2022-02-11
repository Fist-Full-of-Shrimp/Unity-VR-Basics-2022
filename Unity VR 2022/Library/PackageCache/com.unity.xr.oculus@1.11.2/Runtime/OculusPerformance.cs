﻿using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using UnityEngine;
using UnityEngine.XR;
using XRStats = UnityEngine.XR.Provider.XRStats;

namespace Unity.XR.Oculus
{
    public static class Performance
    {
        /// <summary>
        /// Set the CPU Level for the device
        /// </summary>
        /// <param name="level">
        /// Allowable values are integers in the range 0 - 4 (inclusive). A value of 0 is the lowest performance level but is the most power efficient.
        /// Please note: as this is a hint, it may not be immediately reflected by the system.
        /// </param>
        /// <returns>
        /// True if we have no errors returned by the native function. We return false when the native function returns a failure condition.
        ///  Check the log for more information.
        /// </returns>
        public static bool TrySetCPULevel(int level)
        {
            return (NativeMethods.SetCPULevel(level) == 0);
        }

        /// <summary>
        /// Set the GPU performance level
        /// </summary>
        /// <param name="level">
        /// Allowable values are integers in the range 0 - 4 (inclusive). A value of 0 is the lowest performance level but is the most power efficient.
        /// Please note: as this is a hint, it may not be immediately reflected by the system.
        /// </param>
        /// <returns>
        /// True if we have no errors returned by the native function. We return false when the native function returns a failure condition. Check
        /// the log for more information.
        /// </returns>
        public static bool TrySetGPULevel(int level)
        {
            return (NativeMethods.SetGPULevel(level) == 0);
        }

        private static float[] cachedDisplayAvailableFrequencies = null;

        /// <summary>
        /// Get an array of available display frequencies supported by this hardware.
        /// </summary>
        public static bool TryGetAvailableDisplayRefreshRates(out float[] refreshRates)
        {
            if (cachedDisplayAvailableFrequencies == null || cachedDisplayAvailableFrequencies.Length == 0)
            {
                cachedDisplayAvailableFrequencies = new float[0];
                int numFrequencies = 0;
                if (NativeMethods.GetDisplayAvailableFrequencies(IntPtr.Zero, ref numFrequencies) && numFrequencies > 0)
                {                   
                    int size = sizeof(float) * numFrequencies;
                    IntPtr ptr = Marshal.AllocHGlobal(size);
                    if (NativeMethods.GetDisplayAvailableFrequencies(ptr, ref numFrequencies) && numFrequencies > 0)
                    {
                        cachedDisplayAvailableFrequencies = new float[numFrequencies];
                        Marshal.Copy(ptr, cachedDisplayAvailableFrequencies, 0, numFrequencies);
                    }
                    Marshal.FreeHGlobal(ptr);
                }
            }

            refreshRates = cachedDisplayAvailableFrequencies;
            return (cachedDisplayAvailableFrequencies.Length > 0);
        }

        /// <summary>
        /// Set the current display frequency.
        /// </summary>
        public static bool TrySetDisplayRefreshRate(float refreshRate)
        {
            return NativeMethods.SetDisplayFrequency(refreshRate);
        }

        /// <summary>
        /// Get the current display frequency.
        /// </summary>
        public static bool TryGetDisplayRefreshRate(out float refreshRate)
        {
            return NativeMethods.GetDisplayFrequency(out refreshRate);
        }
    }

    public class Stats
    {
        private static IntegratedSubsystem m_Display;
        private static string m_PluginVersion = string.Empty;

        /// <summary>
        /// Gets the version of OVRPlugin currently in use. Format: "major.minor.release"
        /// </summary>
        public static string PluginVersion
        {
            get
            {
                if (string.Equals(string.Empty, m_PluginVersion))
                {
                    byte[] buf = new byte[256];
                    NativeMethods.GetOVRPVersion(buf);
                    var end = Array.IndexOf<byte>(buf, 0);
                    m_PluginVersion = System.Text.Encoding.ASCII.GetString(buf, 0, end);
                }
                return m_PluginVersion;
            }
        }

        /// <summary>
        /// Provides performance statistics useful for adaptive performance systems. Not every stat is supported on every Oculus platform and will always return a value of 0 if unsupported.
        /// </summary>
        public static class AdaptivePerformance
        {
            /// <summary>
            /// Reports the time the application spent on the GPU last frame in seconds.
            /// </summary>
            public static float GPUAppTime
            {
                get
                {
                    float val;
                    ((XRDisplaySubsystem) GetOculusDisplaySubsystem()).TryGetAppGPUTimeLastFrame(out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the time the compositor spent on the GPU last frame in seconds.
            /// </summary>
            public static float GPUCompositorTime
            {
                get
                {
                    float val;
                    ((XRDisplaySubsystem) GetOculusDisplaySubsystem()).TryGetCompositorGPUTimeLastFrame(out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the latency from when the last predicted tracking information was queried by the application to the moment the middle scaline of the target frame is illuminated on the display.
            /// </summary>
            public static float MotionToPhoton
            {
                get
                {
                    float val;
                    ((XRDisplaySubsystem) GetOculusDisplaySubsystem()).TryGetMotionToPhoton(out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the display's refresh rate in frames per second
            /// </summary>
            public static float RefreshRate
            {
                get
                {
                    float val;
                    ((XRDisplaySubsystem) GetOculusDisplaySubsystem()).TryGetDisplayRefreshRate(out val);
                    return val;
                }
            }

            /// <summary>
            /// Gets the current battery temperature in degrees Celsius.
            /// </summary>
            public static float BatteryTemp
            {
                get
                {
                    float batteryTemp;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "batteryTemperature", out batteryTemp);
                    return batteryTemp;
                }
            }

            /// <summary>
            /// Gets the current available battery charge, ranging from 0.0 (empty) to 1.0 (full).
            /// </summary>
            public static float BatteryLevel
            {
                get
                {
                    float batteryLevel;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "batteryLevel", out batteryLevel);
                    return batteryLevel;
                }
            }

            /// <summary>
            /// If true, the system is running in a reduced performance mode to save power.
            /// </summary>
            public static bool PowerSavingMode
            {
                get
                {
                    float powerSavingMode;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "powerSavingMode", out powerSavingMode);
                    return !(powerSavingMode == 0.0f);
                }
            }

            /// <summary>
            /// Returns the recommended amount to scale GPU work in order to maintain framerate.
            /// Can be used to adjust viewportScale and textureScale
            /// </summary>
            public static float AdaptivePerformanceScale
            {
                get
                {
                    float performanceScale;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "adaptivePerformanceScale", out performanceScale);
                    return performanceScale;
                }
            }

            /// <summary>
            /// Gets the current CPU performance level, integer in the range 0 - 3.
            /// </summary>
            public static int CPULevel
            {
                get
                {
                    float cpuLevel;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "cpuLevel", out cpuLevel);
                    return (int) cpuLevel;
                }
            }

            /// <summary>
            /// Gets the current GPU performance level, integer in the range 0 - 3.
            /// </summary>
            public static int GPULevel
            {
                get
                {
                    float gpuLevel;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "gpuLevel", out gpuLevel);
                    return (int) gpuLevel;
                }
            }
        }

        /// <summary>
        /// Provides additional perf metrics. These stats will not be tracked unless the user makes a PerfMetrics.EnablePerfMetrics(true) method call. Not every stat is supported on every Oculus platform and will always return a value of 0 if unsupported.
        /// </summary>
        public static class PerfMetrics
        {
            /// <summary>
            /// Reports the time the application spent on the CPU last frame in seconds.
            /// </summary>
            public static float AppCPUTime
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "perfmetrics.appcputime", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the time the application spen on the GPU last frame in seconds.
            /// </summary>
            public static float AppGPUTime
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "perfmetrics.appgputime", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the time the compositor spent on the CPU last frame in seconds.
            /// </summary>
            public static float CompositorCPUTime
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "perfmetrics.compositorcputime", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the time the compositor spent on the GPU last frame in seconds.
            /// </summary>
            public static float CompositorGPUTime
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "perfmetrics.compositorgputime", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the GPU utilization as a value from 0.0 - 1.0.
            /// </summary>
            public static float GPUUtilization
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "perfmetrics.gpuutil", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the average CPU utilization as a value from 0.0 - 1.0.
            /// </summary>
            public static float CPUUtilizationAverage
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "perfmetrics.cpuutilavg", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the worst CPU utilization as a value from 0.0 - 1.0.
            /// </summary>
            public static float CPUUtilizationWorst
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "perfmetrics.cpuutilworst", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the CPU clock frequency
            /// </summary>
            public static float CPUClockFrequency
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "perfmetrics.cpuclockfreq", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the GPU clock frequency
            /// </summary>
            public static float GPUClockFrequency
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "perfmetrics.gpuclockfreq", out val);
                    return val;
                }
            }

            /// <summary>
            /// Enable or disable provider tracking perf metrics. Perf metrics are disabled by default.
            /// </summary>
            public static void EnablePerfMetrics(bool enable)
            {
                NativeMethods.EnablePerfMetrics(enable);
            }
        }

        /// <summary>
        /// Provides additional application metrics. These metrics will not be tracked unless the user makes a AppMetrics.EnableAppMetrics(true) method call. Not every stat is supported on every Oculus platform and will always return a value of 0 if unsupported.
        /// </summary>
        public static class AppMetrics
        {
            public static float AppQueueAheadTime
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "appstats.appqueueahead", out val);
                    return val;
                }
            }

            public static float AppCPUElapsedTime
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "appstats.cpuelapsedtime", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the number of frames dropped by the compositor.
            /// </summary>
            public static float CompositorDroppedFrames
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "appstats.compositordroppedframes", out val);
                    return val;
                }
            }

            public static float CompositorLatency
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "appstats.compositorlatency", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the time the compositor spent on the CPU last frame in seconds.
            /// </summary>
            public static float CompositorCPUTime
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "appstats.compositorcputime", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the total time from beginning of the main thread until compositor frame submission.
            /// </summary>
            public static float CPUStartToGPUEnd
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "appstats.compositorcpustartgpuendelapsedtime", out val);
                    return val;
                }
            }

            /// <summary>
            /// Reports the total time from compositor frame submission until the frame sync point.
            /// </summary>
            public static float GPUEndToVsync
            {
                get
                {
                    float val;
                    XRStats.TryGetStat(GetOculusDisplaySubsystem(), "appstats.compositorgpuendtovsyncelapsedtime", out val);
                    return val;
                }
            }

            public static void EnableAppMetrics(bool enable)
            {
                NativeMethods.EnableAppMetrics(enable);
            }
        }


        private static IntegratedSubsystem GetOculusDisplaySubsystem()
        {
            if (m_Display != null)
                return m_Display;
            List<XRDisplaySubsystem> displays = new List<XRDisplaySubsystem>();
            SubsystemManager.GetInstances(displays);

            foreach (XRDisplaySubsystem xrDisplaySubsystem in displays)
            {
                if (xrDisplaySubsystem.SubsystemDescriptor.id == "oculus display" && xrDisplaySubsystem.running)
                {
                    m_Display = xrDisplaySubsystem;
                    return m_Display;
                }
            }

            Debug.LogError("No active Oculus display subsystem was found.");
            return m_Display;
        }
    }
}
