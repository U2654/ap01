#include <stdio.h>      /* system wide header and library */
#include "geometry.h"   /* own header and implemenation */

int main() {
    float r = 2;
    float area = area_of_circle(r);
    float circ = circumference_of_circle(r);
    printf("a: %f\n", area);
    return 0;
}