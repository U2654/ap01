#include <stdio.h>
int main()
{
    int a, b;        /* variables are typed: integer      */
    printf("a: ");   /* system functions printf and scanf */
    scanf("%d", &a); /* note the parameters and the &a    */
    printf("b: ");   /* which provides the memory address */
    scanf("%d", &b); /* of the variable */
    if (a == b)
    {
        printf("equal\n");
    } /* == compares */
    else
    {
        printf("not equal\n");
    } /* scope by curled brackets */
}
