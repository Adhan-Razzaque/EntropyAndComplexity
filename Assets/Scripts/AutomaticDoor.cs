using UnityEngine;

public class AutomaticDoor : MonoBehaviour
{
    public GameObject movingDoor;
    
    private bool isOpening;
    private static readonly int AnimationSendEvent = Animator.StringToHash("AnimationSendEvent");
    private static readonly int AnimationEndEvent = Animator.StringToHash("AnimationEndEvent");

    // Start is called before the first frame update
    void Start()
    {
        isOpening = false;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            movingDoor.GetComponent<Animator>().SetTrigger(AnimationSendEvent);
        }
    }

    private void OnTriggerExit(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            movingDoor.GetComponent<Animator>().SetTrigger(AnimationEndEvent);
        }
    }
}
