#include <stdio.h>
int main() {
    char text[5];
    text[0] = 'h';
    text[1] = 'e'; /* [2],[3],[4] are not initialised */
                   /* could contain any data */

    int nb[3];
    nb[0] = 1;
    nb[1] = 2;
    nb[2] = nb[0] + nb[1];
/* out of bounds, error:    nb[3] = 4; */

    char hi[] = "hello";
    printf("%s", hi);
}