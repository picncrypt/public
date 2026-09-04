cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico_w)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(blinky C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(blinky
    main.c
)

target_link_libraries(blinky
    pico_stdlib
    pico_cyw43_arch_none
)

# Enable usb and uart
pico_enable_stdio_usb(blinky 1)
pico_enable_stdio_uart(blinky 0)

# Generate UF2
pico_add_extra_outputs(blinky)
