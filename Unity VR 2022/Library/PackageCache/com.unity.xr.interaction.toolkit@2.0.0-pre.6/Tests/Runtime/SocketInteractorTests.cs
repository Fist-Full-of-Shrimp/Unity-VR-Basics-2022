using System.Collections;
using System.Collections.Generic;
using NUnit.Framework;
using UnityEngine.TestTools;

namespace UnityEngine.XR.Interaction.Toolkit.Tests
{
    [TestFixture]
    class SocketInteractorTests
    {
        [TearDown]
        public void TearDown()
        {
            TestUtilities.DestroyAllSceneObjects();
        }

        [UnityTest]
        public IEnumerator SocketInteractorCanSelectInteractable()
        {
            TestUtilities.CreateInteractionManager();
            var socketInteractor = TestUtilities.CreateSocketInteractor();
            var interactable = TestUtilities.CreateGrabInteractable();

            yield return new WaitForFixedUpdate();
            yield return null;

            Assert.That(socketInteractor.interactablesSelected, Is.EqualTo(new[] { interactable }));
            Assert.That(socketInteractor.hasSelection, Is.True);
        }

        [UnityTest]
        public IEnumerator SocketInteractorHandlesUnregisteredInteractable()
        {
            var manager = TestUtilities.CreateInteractionManager();
            var socketInteractor = TestUtilities.CreateSocketInteractor();
            var selectedInteractable = TestUtilities.CreateGrabInteractable();
            var hoveredInteractable = TestUtilities.CreateGrabInteractable();
            // Move to a position so it won't be the closest to ensure selectedInteractable is the one selected
            hoveredInteractable.transform.localPosition = new Vector3(0.001f, 0f, 0f);

            yield return new WaitForFixedUpdate();
            yield return null;

            Assert.That(socketInteractor.interactablesSelected, Is.EqualTo(new[] { selectedInteractable }));

            var validTargets = new List<IXRInteractable>();
            manager.GetValidTargets(socketInteractor, validTargets);
            Assert.That(validTargets, Is.EquivalentTo(new[] { selectedInteractable, hoveredInteractable }));
            socketInteractor.GetValidTargets(validTargets);
            Assert.That(validTargets, Is.EquivalentTo(new[] { selectedInteractable, hoveredInteractable }));

            Assert.That(socketInteractor.interactablesHovered, Is.EquivalentTo(new[] { selectedInteractable, hoveredInteractable }));

            Object.Destroy(hoveredInteractable);

            yield return null;
            // ReSharper disable once ConditionIsAlwaysTrueOrFalse -- Object operator==
            Assert.That(hoveredInteractable == null, Is.True);

            manager.GetValidTargets(socketInteractor, validTargets);
            Assert.That(validTargets, Is.EquivalentTo(new[] { selectedInteractable }));
            socketInteractor.GetValidTargets(validTargets);
            Assert.That(validTargets, Is.EquivalentTo(new[] { selectedInteractable }));

            Assert.That(socketInteractor.interactablesHovered, Is.EquivalentTo(new[] { selectedInteractable }));

            Object.Destroy(selectedInteractable);

            yield return null;
            Assert.That(selectedInteractable == null, Is.True);
            Assert.That(socketInteractor.interactablesSelected, Is.Empty);
        }

        [UnityTest]
        public IEnumerator SocketInteractorCanDirectInteractorStealFrom()
        {
            TestUtilities.CreateInteractionManager();
            var socketInteractor = TestUtilities.CreateSocketInteractor();
            var interactable = TestUtilities.CreateGrabInteractable();

            var directInteractor = TestUtilities.CreateDirectInteractor();
            var controller = directInteractor.GetComponent<XRController>();
            var controllerRecorder = TestUtilities.CreateControllerRecorder(controller, (recording) =>
            {
                recording.AddRecordingFrameNonAlloc(new XRControllerState(0.0f, Vector3.zero, Quaternion.identity, InputTrackingState.All,
                    true, false, false));
                recording.AddRecordingFrameNonAlloc(new XRControllerState(float.MaxValue, Vector3.zero, Quaternion.identity, InputTrackingState.All,
                    true, false, false));
            });
            controllerRecorder.isPlaying = true;

            yield return new WaitForSeconds(0.1f);

            Assert.That(socketInteractor.interactablesSelected, Is.Empty);
            Assert.That(directInteractor.interactablesSelected, Is.EqualTo(new[] { interactable }));
        }

        [UnityTest]
        public IEnumerator SocketInteractorReportsValidTargetWhenInteractableRegisteredAfterContact()
        {
            TestUtilities.CreateInteractionManager();
            var interactor = TestUtilities.CreateSocketInteractor();
            var interactable = TestUtilities.CreateGrabInteractable();

            yield return new WaitForFixedUpdate();
            yield return null;

            Assert.That(interactor.interactablesSelected, Is.EqualTo(new[] { interactable }));
            Assert.That(interactable.interactorsSelecting, Is.EqualTo(new[] { interactor }));

            var validTargets = new List<IXRInteractable>();
            interactor.GetValidTargets(validTargets);
            Assert.That(validTargets, Is.EquivalentTo(new[] { interactable }));

            // Disable the Interactable so it will be removed as a valid target
            interactable.enabled = false;

            yield return null;

            Assert.That(interactor.interactablesSelected, Is.Empty);
            Assert.That(interactable.interactorsSelecting, Is.Empty);

            interactor.GetValidTargets(validTargets);
            Assert.That(validTargets, Is.Empty);

            // Re-enable the Interactable. It should not be required to leave and enter the collider to be selected again.
            interactable.enabled = true;

            yield return null;

            Assert.That(interactor.interactablesSelected, Is.EqualTo(new[] { interactable }));
            Assert.That(interactable.interactorsSelecting, Is.EqualTo(new[] { interactor }));

            interactor.GetValidTargets(validTargets);
            Assert.That(validTargets, Is.EquivalentTo(new[] { interactable }));
        }
    }
}
