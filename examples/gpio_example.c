// gcc -o gpio_example examples/gpio_example.c src/peripheral.c src/gpio.c

#include <stdio.h>
#include <unistd.h>

#include "../src/gpio.h"

int main(void)
{
    // you can map seperate with GPIOx (x = 0 ... 4) or all gpios with GPIO_ALL
    if (gpio_map(GPIO_ALL) < 0) {
        return 1; // return if mapping failed
    }

    gpio_pin out = GPIO1_A0;
    gpio_pin inp = GPIO1_A4;

    gpio_out(out);
    gpio_inp(inp);

    while(gpio_tst(inp) == 0) {
        gpio_set(out);
        sleep(1);
        gpio_clr(out);
        sleep(1);
    }

    gpio_unmap(GPIO_ALL);

    return 0;
}
