#include <math.h> /* has M_PI defined*/
#include "geometry.h"

float area_of_circle(float radius) {
    return M_PI * radius * radius;
}

float circumference_of_circle(float radius) {
    return M_PI * radius * 2.0f;
}