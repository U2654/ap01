#include <iostream>
#include <math.h>

enum Color {
    BLUE, GREEN, RED, YELLOW, WHITE, BLACK
};

// this is not good design, it is just for 
// illustration of inheritance.
// assume all objects stand horizontally
// base class 
class Shape {
    public: 
        unsigned int width = 0;
        unsigned int height = 0;
        Color color = Color::WHITE;
        // class is pure virtual / abstract, 
        // cannot be instantiated
        virtual float area() = 0;
        virtual void draw() = 0;
    protected:
        Shape(int w, int h) : width(w), height(h) { }
    private:
};

// derived class, can be instantiated
class Rectangle : public Shape {
    public:
        Rectangle(int w, int h) : Shape (w, h) {}
        float area()  {
            return width * height;
        }
        void draw()  { /* .. */ }
};

class Circle : public Shape {
    private: 
        float radius = 0.0f;
    public: 
        Circle(int w, int h) : Shape (w, h) {}
        float area()  {
            // assume height = width here
            radius = float(height)/2;
            return radius*radius*M_PI;
        }
        void draw()  { /* .. */ }
};

class Triangle : public Shape {
    public: 
        Triangle(int w, int h) : Shape (w, h) {}
        float area () {
            return height * width * 0.5f;
        }
        void draw () { /* ... */}
};

int main() {
//    Shape* s = new Shape(); // not allowed, it is abstract
    Rectangle* rect = new Rectangle(10, 10);
    Triangle* tria = new Triangle(20, 10);
    Circle* circle = new Circle(15, 15);

    Shape* shape = circle;
    std::cout << " " << shape->area() << std::endl;
    shape = rect;
    std::cout << " " << shape->area() << std::endl;

    delete rect;
    delete tria;
    delete circle;
    return 0;
}