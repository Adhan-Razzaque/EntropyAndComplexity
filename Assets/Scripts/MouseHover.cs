using System;
using UnityEngine;

namespace UnityStandardAssets.Characters.FirstPerson
{
    public class MouseHover : MonoBehaviour
    {
        private void Start()
        {
            GetComponent<Renderer>().material.color = Color.white;
            Cursor.lockState = CursorLockMode.None;
        }

        private void OnMouseEnter()
        {
            GetComponent<Renderer>().material.color = Color.gray;
        }

        private void OnMouseExit()
        {
            GetComponent<Renderer>().material.color = Color.white;
        }
    }
}