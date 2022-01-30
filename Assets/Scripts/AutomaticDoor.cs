using UnityEngine;

public class AutomaticDoor : MonoBehaviour
{
    public GameObject movingDoor;
    
    private static readonly int AnimationSendEvent = Animator.StringToHash("AnimationSendEvent");
    private static readonly int AnimationEndEvent = Animator.StringToHash("AnimationEndEvent");

    private void OnTriggerEnter(Collider Other)
    {
        if (Other.gameObject.CompareTag("Player"))
        {
            movingDoor.GetComponent<Animator>().SetTrigger(AnimationSendEvent);
        }
    }

    private void OnTriggerExit(Collider Other)
    {
        if (Other.gameObject.CompareTag("Player"))
        {
            movingDoor.GetComponent<Animator>().SetTrigger(AnimationEndEvent);
        }
    }
}
