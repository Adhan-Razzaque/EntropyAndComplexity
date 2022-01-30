using UnityEngine;

namespace UnityStandardAssets.Characters.FirstPerson
{
    public class CharacterManager : MonoBehaviour
    {
        // Singleton instance
    public static CharacterManager Instance = null;
    [SerializeField]
    private CharacterManager characterManagerPrefab;
    
    // Maintain state of RigidBody
    public Vector3 playerLocation;
    public Quaternion playerRotation;

    // Maintain state of camera component
    public Quaternion cameraRotation;
    


    public void Reset()
    {
        // PrefabUtility.RevertObjectOverride(Instance, InteractionMode.AutomatedAction);
        // Reset to default values, there must be a better way to do this
        playerLocation = Vector3.zero;
        playerRotation = cameraRotation = Quaternion.identity;
    }

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
        }
        else if (Instance != this)
        {
            Destroy(gameObject);
        }
        
        DontDestroyOnLoad(gameObject);
    }

    }
}