#include <stdio.h>
/* enum in C*/
enum color {RED, GREEN, BLUE, YELLOW, WHITE, BLACK};

int main() {
    /* some variables */
    int x = -5;
    int y = 0;

    /* y should contain info about sign of x*/
    if (x > 0) {
        y = 1;
    }
    else if (x < 0) {
        y = -1;
    }
    else {
        y = 0;
    }

    /* now use y in a switch case */
    switch (y) {
        case 0: 
            x = 0;
            break;  /* break is important */
        case 1:
            x = 1;
            break;
        default:
            x = -1;
            break;
    }

    /* combined conditions */
    if ((x > 0) || (y < 0)) {
        /* shoud not come here ... */
    }

    /* enum variable */
    enum color current_color = GREEN;

    switch (current_color) {
        case BLACK:
            printf("black\n");
            break;
        case RED:
            printf("red\n");
            break;
        default:
            printf("not black and not red\n");
            break;
    }

    return 0;
}