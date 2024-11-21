#include <stdint.h>

#define CLINT_BASE 0x02000000
#define MTIME       (CLINT_BASE + 0xBFF8)
#define MTIMECMP    (CLINT_BASE + 0x4000)

void timer_set(uint64_t interval) {
    *(volatile uint64_t*)MTIMECMP = *(volatile uint64_t*)MTIME + interval;
}
