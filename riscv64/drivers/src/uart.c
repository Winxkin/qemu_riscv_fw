#include "uart.h"

#define UART_BASE 0x1000000
#define UART_TXDATA (UART_BASE + 0x00)
#define UART_RXDATA (UART_BASE + 0x04)

void uart_write(char c) {
    while (*(volatile uint32_t*)UART_TXDATA & 0x80000000) {
        // Wait for TX buffer to be ready
    }
    *(volatile uint32_t*)UART_TXDATA = c;
}

char uart_read() {
    while (*(volatile uint32_t*)UART_RXDATA & 0x80000000) {
        // Wait for RX data
    }
    return *(volatile uint32_t*)UART_RXDATA;
}
