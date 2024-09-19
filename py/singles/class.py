# Python always need self to access 
# instance attributes and methods
class Rectangle:
    # Constructor/initializer
    # __...__ marks special methods
    def __init__(self, width, height):
        # but __ prefix marks private 
        self.__width = width
        self.__height = height

    # __ marks private
    def __i_am_private(self) :
        print("private")

    # Method to calculate area
    def area(self):
        return self.__width * self.__height

    # Method to draw the rectangle
    def draw(self):
        self.__i_am_private()
        for i in range(self.__height):
            print('*' * self.__width)

    # String representation of the object
    def __str__(self):
        return f"R(width={self.__width}, height={self.__height})"

# Create an instance of the class with width and height
rect = Rectangle(10, 10)
# Call methods
rect.draw()
print(rect.area())
print(rect)
#rect.__i_am_private() does not work
