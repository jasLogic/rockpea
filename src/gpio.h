/*
 * gpio.h
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

#ifndef _GPIO_H
#define _GPIO_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

enum {
    GPIO_ALL = -1,
    GPIO0 = 0,
    GPIO1,
    GPIO2,
    GPIO3,
    GPIO4
};
enum {
    GPIO0_A0=0 , GPIO0_A1, GPIO0_A2, GPIO0_A3, GPIO0_A4, GPIO0_A5, GPIO0_A6,
    GPIO0_B0=8 , GPIO0_B1, GPIO0_B2, GPIO0_B3, GPIO0_B4, GPIO0_B5, GPIO0_B6, GPIO0_B7,
    GPIO0_C0=16, GPIO0_C1, GPIO0_C2, GPIO0_C3, GPIO0_C4, GPIO0_C5, GPIO0_C6,
    GPIO0_D0=24, GPIO0_D1, GPIO0_D2, GPIO0_D3, GPIO0_D4, GPIO0_D5, GPIO0_D6, GPIO0_D7
};
enum {
    GPIO1_A0=0, GPIO1_A1, GPIO1_A2, GPIO1_A3, GPIO1_A4, GPIO1_A5, GPIO1_A6, GPIO1_A7,
    GPIO1_B0=8, GPIO1_B1
};

extern volatile uint32_t *gpio_base_ptr[5];

struct gpio_register_map {
        uint32_t SWPORTA_DR;
        uint32_t SWPORTA_DDR;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t INTEN;
        uint32_t INTMASK;
        uint32_t INTTYPE_LEVEL;
        uint32_t INT_PRIORITY;
        uint32_t INT_STATUS;
        uint32_t INT_RAWSTATUS;
        uint32_t DEBOUNCE;
        uint32_t PORTA_EOI;
        uint32_t EXT_PORTA;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t LS_SYNC;
};
// usage: GPIO(GPIOx)->register , x = 0 ... 4
#define GPIO(n) ((volatile struct gpio_register_map *)gpio_base_ptr[n])

int  gpio_map(int num);
void gpio_unmap(int num);

void gpio_out(int num, uint32_t pin);
void gpio_inp(int num, uint32_t pin);

extern void gpio_set(int num, uint32_t pin);
extern void gpio_clr(int num, uint32_t pin);
extern uint32_t gpio_tst(int num, uint32_t pin);

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//_GPIO_H
