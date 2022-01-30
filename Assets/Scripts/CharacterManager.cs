using UnityEngine;

namespace UnityStandardAssets.Characters.FirstPerson
{
    public class CharacterManager : MonoBehaviour
    {
        // Singleton instance
    public static CharacterManager Instance = null;
    [SerializeField]
    private CharacterManager characterManagerPrefab;
    

    public Vector3 playerLocation;

    public Quaternion playerRotation;
    


    public void Reset()
    {
        // PrefabUtility.RevertObjectOverride(Instance, InteractionMode.AutomatedAction);
        // Reset to default values, there must be a better way to do this
        playerLocation = Vector3.zero;
        playerRotation = Quaternion.identity;
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