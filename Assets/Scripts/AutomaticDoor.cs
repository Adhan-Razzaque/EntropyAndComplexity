using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AutomaticDoor : MonoBehaviour
{
    public GameObject movingDoor;

    private bool playerIsHere;
    private bool isOpening;
    private static readonly int AnimationSendEvent = Animator.StringToHash("AnimationSendEvent");
    private static readonly int AnimationEndEvent = Animator.StringToHash("AnimationEndEvent");

    // Start is called before the first frame update
    void Start()
    {
        playerIsHere = false;
        isOpening = false;
    }

    // Update is called once per frame
    void Update()
    {
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            playerIsHere = true;
            movingDoor.GetComponent<Animator>().SetTrigger(AnimationSendEvent);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            playerIsHere = false;
            other.GetComponent<Animator>().SetTrigger(AnimationEndEvent);
        }
    }
}
