#include <stdio.h>

int main() {
    int number = 6502;  
    int *pointer;       /* the * is for pointer */
                        /* pointer is not initialised  */
    pointer = &number;  /* pointer gets the address, not */
                        /* the value of number */
    printf("%x\n", number);
    printf("%x\n", pointer);

    *pointer = 68000;   /* the * dereferences the pointer */
                        /* change that what is pointed to */
    printf("%x\n", number);
    printf("%x\n", pointer);
}