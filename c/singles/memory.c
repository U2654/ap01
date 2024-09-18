#include <stdio.h>
#include <stdlib.h>
/* global variable */
int gx = 0; 

int func(int x) {
    /* local variable*/
    int fx = x+1;   
    return fx;
}

int fmain() {
    /* local variable */
    int lx = 1; 
    lx = func(lx);
    return lx;
}

int main() {
    const int nb = 10;
    /* alloc space for nb integers */
    int *p = (int*) malloc(nb*sizeof(int));
    /* pointer p should now have a pointer 
       of a space for nb integers   */
    /* if p contains 0, something went wrong */
    if (p == NULL) {
        /* exit of program here*/
        return -1;
    }
    for (int i = 0; i < nb; i++) {
        /* the integer p points to is assigned
           to i and p is incremented */
        *p++ = i;
    }
    for (int i = 0; i < nb; i++) {
        /* decrement p and then dereferenc */
        printf("%d\n", *(--p));
    }
    /* p has now its initial value */
    free(p);
    return 0;
}
