/* illustration of function */
#include <stdio.h>

/* purpose: compute the second binomial 
   for given input parameters of integer a and b,
   it returns integer value of a*a + 2*a*b + b*b */
int second_binomial(int a, int b) {
    int twice_a_b = 2*a*b;          /* temporary variable in function */
    return a*a + twice_a_b + b*b;
}

int main() {
    const int x = 3; /* const values */
    const int y = 4; 
    /* call function and result comes to r*/
    int r = second_binomial(x, y);
    printf("r: %d\n", r);
}