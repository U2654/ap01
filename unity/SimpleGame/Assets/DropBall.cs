using UnityEngine;
using TMPro;

public class DropBall : MonoBehaviour
{
    public GameObject ball; // The ball GameObject to reposition
    public GameObject plane; // The plane GameObject
    public GameObject paddel; // The paddel GameObject
    public TextMeshPro scoreText; // The score
    public float dropHeight = 8.0f; // The height from which the ball will be dropped
    public float velY = 1.0f; // The speed of the ball falling
    public int counter = 0; // The counter if the paddel hits the ball

    void Start()
    {
        RepositionBall();
    }

    void Update() 
    {
        Vector3 movement = new Vector3(0.0f, -1.0f, 0.0f);
        transform.Translate(movement * velY * Time.deltaTime, Space.World);
    }

    void OnCollisionEnter(Collision collision)
    {
        // Check if the ball collides with the plane or any other specified GameObject
        if (collision.gameObject == plane)
        {
            RepositionBall();
        }
        else if (collision.gameObject == paddel)
        {
            RepositionBall();
            counter = counter + 1;
            scoreText.text = "Score: " + counter + "";
        }
    }

    void RepositionBall()
    {
        // Get the size of the plane
        Renderer planeRenderer = plane.GetComponent<Renderer>();
        float planeWidth = planeRenderer.bounds.size.x;
        float planeLength = planeRenderer.bounds.size.z;

        // Generate random x and z positions within the plane's bounds
        float randomX = Random.Range(-planeWidth / 2, planeWidth / 2);
        float randomZ = Random.Range(-planeLength / 2, planeLength / 2);

        // Set the new position
        Vector3 newPosition = new Vector3(randomX, dropHeight, randomZ);

        // Reposition the ball
        ball.transform.position = newPosition;
    }
}