#ifndef _MMIO_H
#define _MMIO_H
#include <stdint.h>

#define MMIO_DEVICE_BASE 0x30000000
#define MMIO_REG1 (MMIO_DEVICE_BASE + 0x00)
#define MMIO_REG2 (MMIO_DEVICE_BASE + 0x04)

void mmio_device_write(uint32_t offset, uint32_t value);

uint32_t mmio_device_read(uint32_t offset);

#endif