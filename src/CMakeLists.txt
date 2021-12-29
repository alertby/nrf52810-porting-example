# Copyright (c) 2020-2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(mbed-nrf52-dk INTERFACE)
add_library(mbed-sdt52810b INTERFACE)

target_include_directories(mbed-nrf52-dk
    INTERFACE
        TARGET_NRF52_DK
)

target_include_directories(mbed-sdt52810b
    INTERFACE
        TARGET_SDT52810B
)

if(${MBED_TOOLCHAIN} STREQUAL "ARM")
    set(LINKER_FILE device/TOOLCHAIN_ARM_STD/nRF52810.sct)
    set(STARTUP_FILE device/TOOLCHAIN_ARM_STD/startup_nrf52810.S)
elseif(${MBED_TOOLCHAIN} STREQUAL "GCC_ARM")
    set(LINKER_FILE device/TOOLCHAIN_GCC_ARM/NRF52810.ld)
    set(STARTUP_FILE device/TOOLCHAIN_GCC_ARM/startup_NRF52810.S)
endif()

add_library(mbed-mcu-nrf52810 INTERFACE)

target_include_directories(mbed-mcu-nrf52810
    INTERFACE
        .
        config
        device
)

target_sources(mbed-mcu-nrf52810
    INTERFACE
        PeripheralPins.c

        device/cmsis_nvic.c
        device/system_nrf52.c

        ${STARTUP_FILE}
)

mbed_set_linker_script(mbed-mcu-nrf52810 ${CMAKE_CURRENT_SOURCE_DIR}/${LINKER_FILE})

target_link_libraries(mbed-mcu-nrf528310 INTERFACE mbed-nrf52 mbed-sdk-15-0)
target_link_libraries(mbed-nrf52-dk INTERFACE mbed-mcu-nrf52810)
target_link_libraries(mbed-sdt52810b INTERFACE mbed-mcu-nrf52810)
