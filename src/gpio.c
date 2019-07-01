/*
 * gpio.c
 * Copyright (C) 2019  jasLogic
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "gpio.h"

#include <stdint.h>

#include "peripheral.h"

const size_t GPIO_OFFSET[5] = {
    0xFF720000, // GPIO0
    0xFF730000, // GPIO1
    0xFF780000, // GPIO2
    0xFF788000, // GPIO3
    0xFF790000 // GPIO4
};
const size_t GPIO_SIZE = 0x64;

volatile uint32_t *gpio_base_ptr[5] = {NULL, NULL, NULL, NULL, NULL};

int gpio_map(int num)
{
    if (num >= 0) {
        return peripheral_map(&gpio_base_ptr[num], GPIO_OFFSET[num], GPIO_SIZE);
    } else {
        for (unsigned int i = 0; i < 5; ++i) {
            int ret = peripheral_map(&gpio_base_ptr[i], GPIO_OFFSET[i], GPIO_SIZE);
            if (ret < 0) {
                return ret;
            }
        }
        return 0;
    }
}
void gpio_unmap(int num)
{
    if (num >= 0) {
        peripheral_unmap(gpio_base_ptr[num], GPIO_SIZE);
    } else {
        for (unsigned int i = 0; i < 5; ++i) {
            peripheral_unmap(gpio_base_ptr[i], GPIO_SIZE);
        }
    }
}

void gpio_out(gpio_pin pin)
{
    GPIO(pin.port)->SWPORTA_DDR |= 1 << pin.pin;
}
void gpio_inp(gpio_pin pin)
{
    GPIO(pin.port)->SWPORTA_DDR &= ~(1 << pin.pin);
}

inline void gpio_set(gpio_pin pin)
{
    GPIO(pin.port)->SWPORTA_DR |= 1 << pin.pin;
}
inline void gpio_clr(gpio_pin pin)
{
    GPIO(pin.port)->SWPORTA_DR &= ~(1 << pin.pin);
}
inline uint32_t gpio_tst(gpio_pin pin)
{
    return GPIO(pin.port)->EXT_PORTA & (1 << pin.pin);
}
