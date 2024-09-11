// function with two arguments
int second_binomial(int a, int b) {
    int twice_a_b = 2*a*b;          /* temporary variable in function */
    return a*a + twice_a_b + b*b;   /* return value */
}

int f(int x) {  // x is a copy of caller's var.
    x = x+1;        
    return x; }

// main
int y = 4;
int z = f(y); // herefter y = 4 and z = 5

int x = 4;
int r = second_binomial(x, y);
Console.WriteLine(r);
