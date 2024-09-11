# use enum in Python.
from enum import Enum
# define enum for color
class Color(Enum):
    RED = 1
    GREEN = 2
    BLUE = 3
    YELLOW = 4
    WHITE = 5
    BLACK = 6
# use enum variable
current_color = Color.RED

# selection using match
match(current_color):
    case Color.BLUE:
        print("blue")
    case _:
        print("other than blue")

# selection using if...
x = -5

# y gives a hint about x sign
if x > 0:   
    y = 1
elif x < 0:
    y = -1
else:
    y = 0

# combined condition
if (x < 0) and not (y < 0):
    print ("cannot be.")
else: 
    print ("everything ok.")

print(y)
