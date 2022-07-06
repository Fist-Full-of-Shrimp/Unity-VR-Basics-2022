using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CharacterControllerGravity : MonoBehaviour
{
    private CharacterController _characterController;
    private bool _climbing = false;

    // Start is called before the first frame update
    void Start()
    {
        _characterController = GetComponent<CharacterController>();
        ClimbProvider.ClimbActive += ClimbActive;
        ClimbProvider.ClimbInActive += ClimbInActive;
    }
    private void OnDestroy()
    {
        ClimbProvider.ClimbActive -= ClimbActive;
        ClimbProvider.ClimbInActive -= ClimbInActive;
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        if (!_characterController.isGrounded && !_climbing)
        {
            _characterController.SimpleMove(new Vector3());
        }
    }
    private void ClimbActive()
    {
        _climbing = true;
    }

    private void ClimbInActive()
    {
        _climbing = false;
    }
}
