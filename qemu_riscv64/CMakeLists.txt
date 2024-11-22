# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(riscv64app)

set(DRIVERS_SRC
    drivers/src/gpio.c
    drivers/src/mmio.c
    drivers/src/timer.c
    drivers/src/uart.c
)

set(DRIVERS_INC
    drivers/inc/gpio.h
    drivers/inc/mmio.h
    drivers/inc/timer.h
    drivers/inc/uart.h
)

set(HAL_SRC
    hal/src/hal_gpio.c
    hal/src/hal_timer.c
    hal/src/hal_uart.c
)

set(HAL_INC
    hal/inc/hal_gpio.h
    hal/inc/hal_timer.h
    hal/inc/hal_uart.h
)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/drivers/inc)
include_directories(${CMAKE_SOURCE_DIR}/hal/inc)

target_sources(app PRIVATE src/main.c ${DRIVERS_SRC} ${DRIVERS_INC} ${HAL_SRC} ${HAL_INC})
