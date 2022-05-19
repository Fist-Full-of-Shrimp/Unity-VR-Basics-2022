using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WristUI : MonoBehaviour
{
    private Canvas _wristUICanvas;

    private void Start()
    {
        _wristUICanvas = GetComponent<Canvas>();
    }
    public void ToggleMenu()
    {
        _wristUICanvas.enabled = !_wristUICanvas.enabled;
    }
}
