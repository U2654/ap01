from math import pi

# base class
class Shape:
    def __init__(self, w, h):
        self.width = w
        self.height = h

    def area(self):
        raise NotImplementedError("Subclasses should implement this!")

# derived classes
class Rectangle(Shape):
    def __init__(self, w, h):
        super().__init__(w, h)

    def area(self):
        return self.width * self.height

class Circle(Shape):
    def __init__(self, w, h):
        super().__init__(w, h)

    def area(self):
        return (self.height / 2) ** 2 * pi

# main functionality
if __name__ == "__main__":
    rect = Rectangle(10, 10)
    circle = Circle(15, 15)
    
    shape = circle 
    print(f" {shape.area()}") # Output will be based on pi value used
    
    shape = rect
    print(f" {shape.area()}")
