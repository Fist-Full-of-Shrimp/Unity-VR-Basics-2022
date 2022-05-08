using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SlidingDoor : MonoBehaviour
{
    public float duration = 1f;
    public float loweredHeight = 1.5f;

    private bool _lowerDoor = false;
    private Vector3 _raisedPosition;
    // Start is called before the first frame update
    void Start()
    {
        _raisedPosition = transform.position;
    }

    public void ToggleDoorOpen()
    {
        StopAllCoroutines();
        if (!_lowerDoor)
        {
            Vector3 lowerPosition = _raisedPosition + Vector3.down * loweredHeight;
            StartCoroutine(MoveDoor(lowerPosition));
        }
        else
        {
            StartCoroutine(MoveDoor(_raisedPosition));
        }

        _lowerDoor = !_lowerDoor;
    }

    IEnumerator MoveDoor(Vector3 targetPosition)
    {
        float timeElapsed = 0;
        Vector3 startPosition = transform.position;
        while (timeElapsed < duration)
        {
            transform.position = Vector3.Lerp(startPosition, targetPosition, timeElapsed / duration);
            timeElapsed += Time.deltaTime;
            yield return null;
        }
        transform.position = targetPosition;
    }
}
