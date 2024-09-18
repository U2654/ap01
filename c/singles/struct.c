#include <stdio.h>
#include <string.h>

struct Address {
    char name[50];          /* attention only space for 50 characters */
    char street[50];
    unsigned int postcode;
    char city[50];
};

int main() {
    struct Address address;

    strcpy(address.name, "S. Error");   /* error prone, second string */
    strcpy(address.street, "Bus 0");    /* must have less 50 characters */
    strcpy(address.city, "Processor");  /* function copies the characters*/
    address.postcode = 6502;

    printf("%s", address.name);
    return 0;
}