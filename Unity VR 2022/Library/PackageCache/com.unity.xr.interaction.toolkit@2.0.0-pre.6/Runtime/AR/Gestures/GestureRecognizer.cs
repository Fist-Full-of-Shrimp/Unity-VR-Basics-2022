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
using Unity.XR.CoreUtils;

namespace UnityEngine.XR.Interaction.Toolkit.AR
{
    /// <summary>
    /// A Gesture Recognizer processes touch input to determine if a gesture should start
    /// and fires an event when the gesture is started.
    /// </summary>
    /// <typeparam name="T">The actual gesture.</typeparam>
    /// <remarks>
    /// To determine when a gesture is finished/updated, listen to events on the
    /// <see cref="Gesture{T}"/> object.
    /// </remarks>
    public abstract partial class GestureRecognizer<T> where T : Gesture<T>
    {
        /// <summary>
        /// Calls the methods in its invocation list when a gesture is started.
        /// To receive an event when the gesture is finished/updated, listen to
        /// events on the <see cref="Gesture{T}"/> object.
        /// </summary>
        public event Action<T> onGestureStarted;

        /// <summary>
        /// The <see cref="XROrigin"/>
        /// that will be used by gestures (such as to get the [Camera](xref:UnityEngine.Camera)
        /// or to transform from Session space).
        /// </summary>
        public XROrigin xrOrigin { get; set; }

        /// <summary>
        /// List of current active gestures.
        /// </summary>
        /// <remarks>
        /// Gestures must be added or removed using <see cref="AddGesture"/> and <see cref="RemoveGesture"/>
        /// rather than by directly modifying this list. This list should be treated as read-only.
        /// </remarks>
        /// <seealso cref="AddGesture"/>
        /// <seealso cref="RemoveGesture"/>
        protected List<T> gestures { get; } = new List<T>();

        readonly List<T> m_PostponedGesturesToRemove = new List<T>();

        bool m_IsUpdatingGestures;

        /// <summary>
        /// Instantiate and update all gestures.
        /// </summary>
        public void Update()
        {
            // Instantiate gestures based on touch input.
            // Just because a gesture was created, doesn't mean that it is started.
            // For example, a DragGesture is created when the user touches down,
            // but doesn't actually start until the touch has moved beyond a threshold.
            TryCreateGestures();

            // Update all gestures
            m_IsUpdatingGestures = true;

            foreach (var gesture in gestures)
            {
                gesture.Update();
            }

            m_IsUpdatingGestures = false;

            // Gestures that finished can now be removed. Removals may have been postponed
            // while the gestures list was being iterated.
            if (m_PostponedGesturesToRemove.Count > 0)
            {
                foreach (var gesture in m_PostponedGesturesToRemove)
                {
                    gestures.Remove(gesture);
                }

                m_PostponedGesturesToRemove.Clear();
            }
        }

        /// <summary>
        /// Try to recognize and create gestures.
        /// </summary>
        protected abstract void TryCreateGestures();

        /// <summary>
        /// Add the given <paramref name="gesture"/> to be managed
        /// so that it can be updated during <see cref="Update"/>.
        /// </summary>
        /// <param name="gesture">The gesture to add.</param>
        /// <seealso cref="RemoveGesture"/>
        protected void AddGesture(T gesture)
        {
            // Should not attempt to add to Gestures list while iterating that list
            if (m_IsUpdatingGestures)
            {
                Debug.LogError($"Cannot add {typeof(T).Name} while updating Gestures." +
                    $" It should be done during {nameof(TryCreateGestures)} instead.");
                return;
            }

            gesture.onStart += OnStart;
            gesture.onFinished += OnFinished;
            gestures.Add(gesture);
        }

        /// <summary>
        /// Remove the given <paramref name="gesture"/> from being managed.
        /// After being removed, it will no longer be updated during <see cref="Update"/>.
        /// </summary>
        /// <param name="gesture">The gesture to remove.</param>
        /// <seealso cref="AddGesture"/>
        protected void RemoveGesture(T gesture)
        {
            // Should not attempt to remove from Gestures list while iterating that list
            if (m_IsUpdatingGestures)
                m_PostponedGesturesToRemove.Add(gesture);
            else
                gestures.Remove(gesture);
        }

        /// <summary>
        /// Helper function for creating one finger gestures when a touch begins.
        /// </summary>
        /// <param name="createGestureFunction">Function to be executed to create the gesture.</param>
        protected void TryCreateOneFingerGestureOnTouchBegan(Func<Touch, T> createGestureFunction)
        {
            TryCreateOneFingerGestureOnTouchBegan(TouchConverterClosureHelper.GetFunc(createGestureFunction));
        }

        /// <summary>
        /// Helper function for creating one finger gestures when a touch begins.
        /// </summary>
        /// <param name="createGestureFunction">Function to be executed to create the gesture.</param>
        protected void TryCreateOneFingerGestureOnTouchBegan(Func<InputSystem.EnhancedTouch.Touch, T> createGestureFunction)
        {
            TryCreateOneFingerGestureOnTouchBegan(TouchConverterClosureHelper.GetFunc(createGestureFunction));
        }

        void TryCreateOneFingerGestureOnTouchBegan(Func<CommonTouch, T> createGestureFunction)
        {
            foreach (var touch in GestureTouchesUtility.touches)
            {
                if (touch.isPhaseBegan &&
                    !GestureTouchesUtility.IsFingerIdRetained(touch.fingerId) &&
                    !GestureTouchesUtility.IsTouchOffScreenEdge(touch))
                {
                    var gesture = createGestureFunction(touch);
                    AddGesture(gesture);
                }
            }
        }

        /// <summary>
        /// Helper function for creating two finger gestures when a touch begins.
        /// </summary>
        /// <param name="createGestureFunction">Function to be executed to create the gesture.</param>
        protected void TryCreateTwoFingerGestureOnTouchBegan(
            Func<Touch, Touch, T> createGestureFunction)
        {
            TryCreateTwoFingerGestureOnTouchBegan(TouchConverterClosureHelper.GetFunc(createGestureFunction));
        }

        /// <summary>
        /// Helper function for creating two finger gestures when a touch begins.
        /// </summary>
        /// <param name="createGestureFunction">Function to be executed to create the gesture.</param>
        protected void TryCreateTwoFingerGestureOnTouchBegan(
            Func<InputSystem.EnhancedTouch.Touch, InputSystem.EnhancedTouch.Touch, T> createGestureFunction)
        {
            TryCreateTwoFingerGestureOnTouchBegan(TouchConverterClosureHelper.GetFunc(createGestureFunction));
        }

        void TryCreateTwoFingerGestureOnTouchBegan(
            Func<CommonTouch, CommonTouch, T> createGestureFunction)
        {
            var touches = GestureTouchesUtility.touches;
            if (touches.Count < 2)
                return;

            for (var i = 0; i < touches.Count; ++i)
            {
                TryCreateGestureTwoFingerGestureOnTouchBeganForTouchIndex(i, touches, createGestureFunction);
            }
        }

        void TryCreateGestureTwoFingerGestureOnTouchBeganForTouchIndex(
            int touchIndex,
            IReadOnlyList<CommonTouch> touches,
            Func<CommonTouch, CommonTouch, T> createGestureFunction)
        {
            var touch = touches[touchIndex];

            if (!touch.isPhaseBegan ||
                GestureTouchesUtility.IsFingerIdRetained(touch.fingerId) ||
                GestureTouchesUtility.IsTouchOffScreenEdge(touch))
            {
                return;
            }

            for (var i = 0; i < touches.Count; i++)
            {
                if (i == touchIndex)
                    continue;

                var otherTouch = touches[i];

                // Prevents the same two touches from creating two gestures if both touches began on
                // the same frame.
                if (i < touchIndex && otherTouch.isPhaseBegan)
                {
                    continue;
                }

                if (GestureTouchesUtility.IsFingerIdRetained(otherTouch.fingerId) ||
                    GestureTouchesUtility.IsTouchOffScreenEdge(otherTouch))
                {
                    continue;
                }

                var gesture = createGestureFunction(touch, otherTouch);
                AddGesture(gesture);
            }
        }

        void OnStart(T gesture)
        {
            onGestureStarted?.Invoke(gesture);
        }

        void OnFinished(T gesture)
        {
            RemoveGesture(gesture);
        }

        /// <summary>
        /// Helper class to preallocate delegates to avoid GC Alloc that would happen
        /// when passing the lambda to the methods which create one or two finger gestures.
        /// </summary>
        static class TouchConverterClosureHelper
        {
            // One Touch to Gesture input argument Func
            static Func<Touch, T> s_CreateGestureFromOneTouchFunction;
            static Func<InputSystem.EnhancedTouch.Touch, T> s_CreateGestureFromOneEnhancedTouchFunction;

            // Two Touch to Gesture input argument Func
            static Func<Touch, Touch, T> s_CreateGestureFromTwoTouchFunction;
            static Func<InputSystem.EnhancedTouch.Touch, InputSystem.EnhancedTouch.Touch, T> s_CreateGestureFromTwoEnhancedTouchFunction;

            // Preallocate delegates to avoid GC Alloc
            static readonly Func<CommonTouch, T> s_ConvertUsingOneTouch = ConvertUsingOneTouch;
            static readonly Func<CommonTouch, T> s_ConvertUsingOneEnhancedTouch = ConvertUsingOneEnhancedTouch;
            static readonly Func<CommonTouch, CommonTouch, T> s_ConvertUsingTwoTouch = ConvertUsingTwoTouch;
            static readonly Func<CommonTouch, CommonTouch, T> s_ConvertUsingTwoEnhancedTouch = ConvertUsingTwoEnhancedTouch;

            public static Func<CommonTouch, T> GetFunc(Func<Touch, T> createGestureFunction)
            {
                s_CreateGestureFromOneTouchFunction = createGestureFunction;
                return s_ConvertUsingOneTouch;
            }

            public static Func<CommonTouch, T> GetFunc(Func<InputSystem.EnhancedTouch.Touch, T> createGestureFunction)
            {
                s_CreateGestureFromOneEnhancedTouchFunction = createGestureFunction;
                return s_ConvertUsingOneEnhancedTouch;
            }

            public static Func<CommonTouch, CommonTouch, T> GetFunc(Func<Touch, Touch, T> createGestureFunction)
            {
                s_CreateGestureFromTwoTouchFunction = createGestureFunction;
                return s_ConvertUsingTwoTouch;
            }

            public static Func<CommonTouch, CommonTouch, T> GetFunc(Func<InputSystem.EnhancedTouch.Touch, InputSystem.EnhancedTouch.Touch, T> createGestureFunction)
            {
                s_CreateGestureFromTwoEnhancedTouchFunction = createGestureFunction;
                return s_ConvertUsingTwoEnhancedTouch;
            }

            static T ConvertUsingOneTouch(CommonTouch touch) =>
                s_CreateGestureFromOneTouchFunction(touch.GetTouch());

            static T ConvertUsingOneEnhancedTouch(CommonTouch touch) =>
                s_CreateGestureFromOneEnhancedTouchFunction(touch.GetEnhancedTouch());

            static T ConvertUsingTwoTouch(CommonTouch touch, CommonTouch otherTouch) =>
                s_CreateGestureFromTwoTouchFunction(touch.GetTouch(), otherTouch.GetTouch());

            static T ConvertUsingTwoEnhancedTouch(CommonTouch touch, CommonTouch otherTouch) =>
                s_CreateGestureFromTwoEnhancedTouchFunction(touch.GetEnhancedTouch(), otherTouch.GetEnhancedTouch());
        }
    }
}

#endif
