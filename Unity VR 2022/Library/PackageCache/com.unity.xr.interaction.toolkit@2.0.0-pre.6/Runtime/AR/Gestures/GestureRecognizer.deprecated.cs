//-----------------------------------------------------------------------
// <copyright file="GestureRecognizer.cs" company="Google">
//
// Copyright 2018 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// </copyright>
//-----------------------------------------------------------------------

// Modifications copyright © 2020 Unity Technologies ApS

#if AR_FOUNDATION_PRESENT || PACKAGE_DOCS_GENERATION

using System;
using System.Collections.Generic;
using UnityEngine.XR.ARFoundation;

namespace UnityEngine.XR.Interaction.Toolkit.AR
{
    public abstract partial class GestureRecognizer<T> where T : Gesture<T>
    {
        /// <summary>
        /// The <a href="https://docs.unity3d.com/Packages/com.unity.xr.arfoundation@4.1/api/UnityEngine.XR.ARFoundation.ARSessionOrigin.html">ARSessionOrigin</a>
        /// that will be used by gestures (such as to get the [Camera](xref:UnityEngine.Camera)
        /// or to transform from Session space).
        /// </summary>
        [Obsolete("arSessionOrigin has been deprecated. Use xrOrigin instead for similar functionality.")]
        public ARSessionOrigin arSessionOrigin { get; set; }

#pragma warning disable IDE1006 // Naming Styles
        /// <summary>
        /// (Deprecated) List of current active gestures.
        /// </summary>
        /// <remarks>
        /// <c>m_Gestures</c> has been deprecated. Use <see cref="gestures"/> instead.
        /// </remarks>
        [Obsolete("m_Gestures has been deprecated. Use gestures instead. (UnityUpgradable) -> gestures")]
        protected List<T> m_Gestures = new List<T>();
#pragma warning restore IDE1006 // Naming Styles
    }
}

#endif
