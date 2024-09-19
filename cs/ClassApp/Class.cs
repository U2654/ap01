class Program
{
    // Main method - entry point of the application
    static void Main(string[] args) {
        // an object/instance of the class
        Rectangle rect = new Rectangle(10, 10);
        // access the attributes would 
        // be an error 
        // int w = rect.Width;  
        // call methods
        rect.Draw();
        Console.WriteLine(rect.Area());
        Console.WriteLine(rect.ToString());
    }
}
// this is a class
public class Rectangle 
{
    // attributes, cannot be accessed from outside
    // because they are private 
    private int Width, Height;

    // constructor
    public Rectangle(int w, int h) {
        Width = w;
        Height = h;
    }

    // methods
    public float Area() {
        return (float)Width * (float)Height;
    }

    public void Draw() {
        for (int i = 0; i < Height; i++) {
            for (int j = 0; j < Width; j++) {
                Console.Write("*");
            }
            Console.WriteLine();
        }
    }
}

