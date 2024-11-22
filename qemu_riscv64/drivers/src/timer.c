#include "timer.h"


void timer_set(uint64_t interval) {
    *(volatile uint64_t*)MTIMECMP = *(volatile uint64_t*)MTIME + interval;
}
