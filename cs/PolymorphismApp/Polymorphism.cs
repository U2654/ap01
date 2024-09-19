using System;
// base class
abstract class Shape
{
    public uint Width { get; set; }
    public uint Height { get; set; }
    protected Shape(int width, int height)
    {
        Width = (uint)width;
        Height = (uint)height;
    }
    public abstract float Area();
}

class Rectangle : Shape
{
    public Rectangle(int width, int height) : base(width, height) { }
    public override float Area()
    {
        return Width * Height;
    }
}

class Circle : Shape
{
    public Circle(int width, int height) : base(width, height) { }
    public override float Area()
    {
        return (float)(Height / 2.0 * Height / 2.0 * Math.PI);
    }
}

class Program
{    static void Main()
    {
        Rectangle rect = new Rectangle(10, 10);
        Circle circle = new Circle(15, 15);
        Shape shape = circle;
        Console.WriteLine(" " + shape.Area()); // 176.715
        shape = rect;
        Console.WriteLine(" " + shape.Area()); // 100
    }
}
