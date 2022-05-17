using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
public class ShotCounter : MonoBehaviour
{
    private int _shotCounter = 0;
    private TextMeshProUGUI _text;
    // Start is called before the first frame update
    void Start()
    {
        _text = GetComponent<TextMeshProUGUI>();
        FireBullet.GunFired += IncreaseCounter;
        UpdateText();
    }
    private void OnDestroy()
    {
        FireBullet.GunFired -= IncreaseCounter;
    }

    public void ResetCounter()
    {
        _shotCounter = 0;
        UpdateText();
    }

    private void IncreaseCounter()
    {
        _shotCounter++;
        UpdateText();
    }

    private void UpdateText()
    {
        _text.text = _shotCounter.ToString();
    }
}
