// init variables
int x = -5;
int y = 0;

// let y code the sign of x
if (x > 0) {
    y = 1;
}
else if (x < 0) {
    y = -1;
}
else {
    y = 0;
}
Console.WriteLine(y);

// switch case 
switch (y) {
    case 0: 
        y = 0;
        break; // break is important
    case 1:
        y = 1;
        break;
    default:
        y = -1;
        break;
}
Console.WriteLine(y);

// enum type (s. below) current_color is of type Color 
Color current_color = Color.GREEN;    

// use switch case
switch (current_color) {
    case Color.BLACK:
        Console.WriteLine("black");
    break;
    default:
        Console.WriteLine("not black");
    break;
}

// now iterations, first some variables
int i = 0;
int z = 0;
y = 0;

/* i, y, z all initialised = 0 */
for (i = 0; i < 10; i++) {  /* i++ is the same as i = i + 1 */
    y = y + 1;              /* y = y + 1 is the same as y++ */
}
while (y > 0) {
    y = y - 1;              /* same as y-- */
    z = z + 2;              /* same as z+= 2 */
}
Console.WriteLine(z); // should be 20...


// type declaration in C# are after its usage on top-level
enum Color {RED, GREEN, BLUE, YELLOW, WHITE, BLACK};
