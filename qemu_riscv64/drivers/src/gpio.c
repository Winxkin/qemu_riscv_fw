#include "gpio.h"

void gpio_write(uint32_t value) {
    *(volatile uint32_t*)GPIO_OUTPUT = value;
}

uint32_t gpio_read() {
    return *(volatile uint32_t*)GPIO_INPUT;
}
