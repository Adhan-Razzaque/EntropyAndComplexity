using UnityEngine;
using UnityEngine.SceneManagement;

namespace UnityStandardAssets.Characters.FirstPerson
{
    public class MainMenu : MonoBehaviour
    {
        public bool isStart;
        public bool isQuit;
        
        private void OnMouseUp(){
            if(isStart)
            {
                SceneManager.LoadScene("Level_1Scene");
                GetComponent<Renderer>().material.color = Color.cyan;
            }
            if (isQuit)
            {
                Application.Quit();
            }
        } 
    }
}