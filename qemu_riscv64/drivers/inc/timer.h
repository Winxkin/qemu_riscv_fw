#ifndef _TIMER_H
#define _TIMER_H
#include <stdint.h>

#define CLINT_BASE 0x2004000
#define MTIME       (CLINT_BASE + 0xBFF8)
#define MTIMECMP    (CLINT_BASE + 0x4000)

void timer_set(uint64_t interval);

#endif