#ifndef _GPIO_H
#define _GPIO_H
#include <stdint.h>

#define GPIO_BASE 0x20000000
#define GPIO_INPUT  (GPIO_BASE + 0x00)
#define GPIO_OUTPUT (GPIO_BASE + 0x04)

void gpio_write(uint32_t value);
uint32_t gpio_read();

#endif