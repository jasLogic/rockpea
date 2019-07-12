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

typedef struct {
    uint32_t port: 16; // not A ... D but GPIO0 ... GPIO4
    uint32_t pin: 16;
} gpio_pin;

struct gpio_register_map{
        uint32_t SWPORTA_DR; // 0x0
        uint32_t SWPORTA_DDR;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32; // 0x10
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32; // 0x20
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t INTEN; // 0x30
        uint32_t INTMASK;
        uint32_t INTTYPE_LEVEL;
        uint32_t INT_PRIORITY;
        uint32_t INT_STATUS; // 0x40
        uint32_t INT_RAWSTATUS;
        uint32_t DEBOUNCE;
        uint32_t PORTA_EOI;
        uint32_t EXT_PORTA; // 0x50
        uint32_t: 32;
        uint32_t: 32;
        uint32_t: 32;
        uint32_t LS_SYNC; // 0x60
};

enum {
    GPIO_ALL = -1,
    GPIO0 = 0,
    GPIO1 = 1,
    GPIO2 = 2,
    GPIO3 = 3,
    GPIO4 = 4
};

// usage: GPIO[GPIOx]->register , with x = 0 .. 4
extern volatile struct gpio_register_map *GPIO[5];

// use GPIO_ALL (-1) to (un)map all gpios
int  gpio_map(int num);
void gpio_unmap(int num);

void gpio_out(gpio_pin pin);
void gpio_inp(gpio_pin pin);

extern void gpio_set(gpio_pin pin);
extern void gpio_clr(gpio_pin pin);
extern uint32_t gpio_tst(gpio_pin pin);

//************* gpio_pin intializers *************
#define GPIO0_A0    ((gpio_pin) {.port = 0, .pin = 0})
#define GPIO0_A1    ((gpio_pin) {.port = 0, .pin = 1})
#define GPIO0_A2    ((gpio_pin) {.port = 0, .pin = 2})
#define GPIO0_A3    ((gpio_pin) {.port = 0, .pin = 3})
#define GPIO0_A4    ((gpio_pin) {.port = 0, .pin = 4})
#define GPIO0_A5    ((gpio_pin) {.port = 0, .pin = 5})
#define GPIO0_A6    ((gpio_pin) {.port = 0, .pin = 6})
#define GPIO0_B0    ((gpio_pin) {.port = 0, .pin = 8})
#define GPIO0_B1    ((gpio_pin) {.port = 0, .pin = 9})
#define GPIO0_B2    ((gpio_pin) {.port = 0, .pin = 10})
#define GPIO0_B3    ((gpio_pin) {.port = 0, .pin = 11})
#define GPIO0_B4    ((gpio_pin) {.port = 0, .pin = 12})
#define GPIO0_B5    ((gpio_pin) {.port = 0, .pin = 13})
#define GPIO0_B6    ((gpio_pin) {.port = 0, .pin = 14})
#define GPIO0_B7    ((gpio_pin) {.port = 0, .pin = 15})
#define GPIO0_C0    ((gpio_pin) {.port = 0, .pin = 16})
#define GPIO0_C1    ((gpio_pin) {.port = 0, .pin = 17})
#define GPIO0_C2    ((gpio_pin) {.port = 0, .pin = 18})
#define GPIO0_C3    ((gpio_pin) {.port = 0, .pin = 19})
#define GPIO0_C4    ((gpio_pin) {.port = 0, .pin = 20})
#define GPIO0_C5    ((gpio_pin) {.port = 0, .pin = 21})
#define GPIO0_C6    ((gpio_pin) {.port = 0, .pin = 22})
#define GPIO0_D0    ((gpio_pin) {.port = 0, .pin = 24})
#define GPIO0_D1    ((gpio_pin) {.port = 0, .pin = 25})
#define GPIO0_D2    ((gpio_pin) {.port = 0, .pin = 26})
#define GPIO0_D3    ((gpio_pin) {.port = 0, .pin = 27})
#define GPIO0_D4    ((gpio_pin) {.port = 0, .pin = 28})
#define GPIO0_D5    ((gpio_pin) {.port = 0, .pin = 29})
#define GPIO0_D6    ((gpio_pin) {.port = 0, .pin = 30})
#define GPIO0_D7    ((gpio_pin) {.port = 0, .pin = 31})

#define GPIO1_A0    ((gpio_pin) {.port = 1, .pin = 0})
#define GPIO1_A1    ((gpio_pin) {.port = 1, .pin = 1})
#define GPIO1_A2    ((gpio_pin) {.port = 1, .pin = 2})
#define GPIO1_A3    ((gpio_pin) {.port = 1, .pin = 3})
#define GPIO1_A4    ((gpio_pin) {.port = 1, .pin = 4})
#define GPIO1_A5    ((gpio_pin) {.port = 1, .pin = 5})
#define GPIO1_A6    ((gpio_pin) {.port = 1, .pin = 6})
#define GPIO1_A7    ((gpio_pin) {.port = 1, .pin = 7})
#define GPIO1_B0    ((gpio_pin) {.port = 1, .pin = 8})
#define GPIO1_B1    ((gpio_pin) {.port = 1, .pin = 9})

#define GPIO2_A0    ((gpio_pin) {.port = 2, .pin = 0})
#define GPIO2_A1    ((gpio_pin) {.port = 2, .pin = 1})
#define GPIO2_A2    ((gpio_pin) {.port = 2, .pin = 2})
#define GPIO2_A3    ((gpio_pin) {.port = 2, .pin = 3})
#define GPIO2_A4    ((gpio_pin) {.port = 2, .pin = 4})
#define GPIO2_A5    ((gpio_pin) {.port = 2, .pin = 5})
#define GPIO2_A6    ((gpio_pin) {.port = 2, .pin = 6})
#define GPIO2_A7    ((gpio_pin) {.port = 2, .pin = 7})
#define GPIO2_B0    ((gpio_pin) {.port = 2, .pin = 8})
#define GPIO2_B1    ((gpio_pin) {.port = 2, .pin = 9})
#define GPIO2_B2    ((gpio_pin) {.port = 2, .pin = 10})
#define GPIO2_B3    ((gpio_pin) {.port = 2, .pin = 11})
#define GPIO2_B4    ((gpio_pin) {.port = 2, .pin = 12})
#define GPIO2_B5    ((gpio_pin) {.port = 2, .pin = 13})
#define GPIO2_B6    ((gpio_pin) {.port = 2, .pin = 14})
#define GPIO2_B7    ((gpio_pin) {.port = 2, .pin = 15})
#define GPIO2_C0    ((gpio_pin) {.port = 2, .pin = 16})
#define GPIO2_C1    ((gpio_pin) {.port = 2, .pin = 17})
#define GPIO2_C2    ((gpio_pin) {.port = 2, .pin = 18})
#define GPIO2_C3    ((gpio_pin) {.port = 2, .pin = 19})
#define GPIO2_C4    ((gpio_pin) {.port = 2, .pin = 20})
#define GPIO2_C5    ((gpio_pin) {.port = 2, .pin = 21})
#define GPIO2_C6    ((gpio_pin) {.port = 2, .pin = 22})
#define GPIO2_C7    ((gpio_pin) {.port = 2, .pin = 23})
#define GPIO2_D0    ((gpio_pin) {.port = 2, .pin = 24})
#define GPIO2_D1    ((gpio_pin) {.port = 2, .pin = 25})
#define GPIO2_D2    ((gpio_pin) {.port = 2, .pin = 26})
#define GPIO2_D3    ((gpio_pin) {.port = 2, .pin = 27})
#define GPIO2_D4    ((gpio_pin) {.port = 2, .pin = 28})
#define GPIO2_D5    ((gpio_pin) {.port = 2, .pin = 29})
#define GPIO2_D6    ((gpio_pin) {.port = 2, .pin = 30})
#define GPIO2_D7    ((gpio_pin) {.port = 2, .pin = 31})

#define GPIO3_A0    ((gpio_pin) {.port = 3, .pin = 0})
#define GPIO3_A1    ((gpio_pin) {.port = 3, .pin = 1})
#define GPIO3_A2    ((gpio_pin) {.port = 3, .pin = 2})
#define GPIO3_A3    ((gpio_pin) {.port = 3, .pin = 3})
#define GPIO3_A4    ((gpio_pin) {.port = 3, .pin = 4})
#define GPIO3_B0    ((gpio_pin) {.port = 3, .pin = 8})
#define GPIO3_B1    ((gpio_pin) {.port = 3, .pin = 9})
#define GPIO3_B2    ((gpio_pin) {.port = 3, .pin = 10})
#define GPIO3_B3    ((gpio_pin) {.port = 3, .pin = 11})
#define GPIO3_B4    ((gpio_pin) {.port = 3, .pin = 12})
#define GPIO3_B5    ((gpio_pin) {.port = 3, .pin = 13})
#define GPIO3_B6    ((gpio_pin) {.port = 3, .pin = 14})
#define GPIO3_B7    ((gpio_pin) {.port = 3, .pin = 15})
#define GPIO3_C0    ((gpio_pin) {.port = 3, .pin = 16})
#define GPIO3_C1    ((gpio_pin) {.port = 3, .pin = 17})
#define GPIO3_C2    ((gpio_pin) {.port = 3, .pin = 18})
#define GPIO3_C3    ((gpio_pin) {.port = 3, .pin = 19})
#define GPIO3_C4    ((gpio_pin) {.port = 3, .pin = 20})
#define GPIO3_C5    ((gpio_pin) {.port = 3, .pin = 21})
#define GPIO3_C6    ((gpio_pin) {.port = 3, .pin = 22})

#define GPIO4_A0    ((gpio_pin) {.port = 4, .pin = 16})
#define GPIO4_A1    ((gpio_pin) {.port = 4, .pin = 17})
#define GPIO4_A2    ((gpio_pin) {.port = 4, .pin = 18})
#define GPIO4_A3    ((gpio_pin) {.port = 4, .pin = 19})
#define GPIO4_A4    ((gpio_pin) {.port = 4, .pin = 20})
#define GPIO4_A5    ((gpio_pin) {.port = 4, .pin = 21})
#define GPIO4_A6    ((gpio_pin) {.port = 4, .pin = 22})
#define GPIO4_A7    ((gpio_pin) {.port = 4, .pin = 23})

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//_GPIO_H
