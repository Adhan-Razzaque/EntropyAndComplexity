using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityStandardAssets.Characters.FirstPerson;

public class GravityPad : MonoBehaviour
{
    public Vector3 rotateBy;
    
    private void OnTriggerEnter(Collider Other)
    {
        if (Other.gameObject.CompareTag("Player"))
        {
            // Rotate Player
            var Controller = Other.GetComponent<RigidbodyFirstPersonController>();
            if (!Controller) return;

            Controller.mouseLook.m_CameraTargetRot *= Quaternion.Euler(rotateBy);
            Controller.mouseLook.m_CharacterTargetRot *= Quaternion.Euler(rotateBy);

            // Rotate Gravity
            Vector3 NewGravity = Quaternion.Euler(rotateBy) * Physics.gravity;
            Physics.gravity = NewGravity;
        }
    }
}
