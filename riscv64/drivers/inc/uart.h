#ifndef _UART_H
#define _UART_H
#include <stdint.h>

#define UART_BASE 0x1000000
#define UART_TXDATA (UART_BASE + 0x00)
#define UART_RXDATA (UART_BASE + 0x04)

void uart_write(char c);
char uart_read();

#endif