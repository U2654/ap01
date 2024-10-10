/*
 * Bare metal blink. Still in Arduino environment.
 */

#define GPIO_OUT_REG 0x60091004  // GPIO output register address
#define GPIO_ENABLE_REG 0x60091020  // GPIO enable register address
#define GPIO_PIN 10  // GPIO pin number

#include <stdint.h>

void setup()
{
  // initialize LED digital pin as an output.
    *(volatile uint32_t *)GPIO_ENABLE_REG |= (1 << GPIO_PIN);
}

void loop()
{
    // Toggle GPIO 10
    *(volatile uint32_t *)GPIO_OUT_REG ^= (1 << GPIO_PIN);

    // delay
    volatile uint32_t i;
    for (i = 0; i < 432768; i++);

    // Toggle GPIO 10
    //*(volatile uint32_t *)GPIO_OUT_REG ^= (1 << GPIO_PIN);
    // inline assembly 
    asm("lui a4, 0x60091 \n\t" 
        "lw  a5, 4(a4) \n\t"
        "xor a5, a5, 0x400 \n\t"
        "sw a5, 4(a4) \n\t");

    // delay
    for (i = 0; i < 432768; i++);
}
