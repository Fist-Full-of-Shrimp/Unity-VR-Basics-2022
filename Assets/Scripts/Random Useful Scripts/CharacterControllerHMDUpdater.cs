using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.Interaction.Toolkit;
using Unity.XR.CoreUtils;
public class CharacterControllerHMDUpdater : MonoBehaviour
{
    public float gravity = 1f;

    private XROrigin _xrRig;
    private CharacterController _characterController;
    private CharacterControllerDriver _driver;

    private bool _climbing = false;
    // Start is called before the first frame update
    void Start()
    {
        _xrRig = GetComponent<XROrigin>();
        _characterController = GetComponent<CharacterController>();
        _driver = GetComponent<CharacterControllerDriver>();


    }
    // Update is called once per frame
    void Update()
    {
       UpdateCharacterController();
    }

    void UpdateCharacterController()
    {
        if (_xrRig == null || _characterController == null)
            return;

        var height = Mathf.Clamp(_xrRig.CameraInOriginSpaceHeight, _driver.minHeight, _driver.maxHeight);

        Vector3 center = _xrRig.CameraInOriginSpacePos;
        center.y = height/3f + _characterController.skinWidth;

        _characterController.height = height;
        _characterController.center = center;
    }

}
