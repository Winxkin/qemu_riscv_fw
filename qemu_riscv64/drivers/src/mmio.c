#include "mmio.h"


void mmio_device_write(uint32_t offset, uint32_t value) {
    *(volatile uint32_t*)(MMIO_DEVICE_BASE + offset) = value;
}

uint32_t mmio_device_read(uint32_t offset) {
    return *(volatile uint32_t*)(MMIO_DEVICE_BASE + offset);
}
