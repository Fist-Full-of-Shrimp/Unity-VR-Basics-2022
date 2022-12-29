using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.XR.Interaction.Toolkit;

public class LocomotionManager : MonoBehaviour
{
    public GameObject leftRayTeleport;
    public GameObject rightRayTeleport;


    private TeleportationProvider _teleportationProvider;
    private ActionBasedContinuousMoveProvider _continuousMoveProvider;

    // A Unity bug was found when disabling our Teleportation/Continuous Move Providers. It will sometimes lose the reference to the
    // Input Actions associated with them. As a bandaid fix, we'll just store a reference to them with these variables and reassign
    // them when we set them to active.
    private InputActionReference _continuousMoveInputReference;
    private InputActionAsset _teleportationInputReference;
    // Start is called before the first frame update
    void Start()
    {
        _teleportationProvider = GetComponent<TeleportationProvider>();
        _continuousMoveProvider = GetComponent<ActionBasedContinuousMoveProvider>();
        SetContinuousMoveInputReference();
        SetTeleportationInputReference();
    }

    public void SwitchLocomotion(int locomotionValue)
    {
        if(locomotionValue == 0)
        {
            DisableTeleport();
            EnableContinuous();
        }
        else if (locomotionValue == 1)
        {
            DisableContinuous();
            EnableTeleport();
        }
    }

    //This function assumes that the user will only have the left hand needed for input with their Continuous Move Provider
    private void SetContinuousMoveInputReference()
    {
        if(_continuousMoveProvider.leftHandMoveAction.reference != null)
        {
            _continuousMoveInputReference = _continuousMoveProvider.leftHandMoveAction.reference;
        }
        else
        {
            Debug.Log("No Continuous Move Provider Input Action was found on the Left Hand. Please set it on your  Left hand Move Action found on the Continuous Move Provider use the Locomotion Manager");
        }
    }

    private void SetTeleportationInputReference()
    {
        _teleportationInputReference = leftRayTeleport.GetComponent<TeleportationControllerFixed>().inputAction;
        if(_teleportationInputReference == null)
        {
            Debug.Log("No Input Action Asset reference was found in the Teleportation Controller Fixed script. Please assign to use Locomotion Manager");
        }
    }
    private void DisableTeleport()
    {
        leftRayTeleport.SetActive(false);
        rightRayTeleport.SetActive(false);
        _teleportationProvider.enabled = false;
    }

    private void EnableTeleport()
    {
        leftRayTeleport.GetComponent<TeleportationControllerFixed>().inputAction = _teleportationInputReference;
        rightRayTeleport.GetComponent<TeleportationControllerFixed>().inputAction = _teleportationInputReference;
        leftRayTeleport.SetActive(true);
        rightRayTeleport.SetActive(true);
        _teleportationProvider.enabled = true;
    }

    private void DisableContinuous()
    {
        _continuousMoveProvider.enabled = false;
    }

    private void EnableContinuous()
    {
        _continuousMoveProvider.leftHandMoveAction = new InputActionProperty(_continuousMoveInputReference);
        _continuousMoveProvider.enabled = true;
    }
}
