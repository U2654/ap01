/* C using iterations / loops */
#include <stdio.h>
int main(){
    int y = 0;
    int i = 0;
    /* 10 times do, i++ is the same as i = i + 1 */
    for (i = 0; i < 10; i++) {
        y = y + 1;  /* increment of y */
    }

    int z = 0;
    /* y is 10 now, so 10 times the loop*/
    while (y > 0) {
        y = y - 1;  /* decrement by 1 (same as y--)*/
        z = z + 2;  /* increment by 2*/
    }
    /* z now 20 */
    printf("z: %d\n", z);
}
