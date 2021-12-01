# what was changed from original mbed:
### nano .platformio/packages/framework-mbed/targets/TARGET_NORDIC/TARGET_NRF5x/TARGET_NRF52/gpio_api.c
```
#if defined(TARGET_MCU_NRF51822)
#define GPIO_PIN_COUNT 31
#elif defined(TARGET_MCU_NRF52832) || defined(TARGET_MCU_NRF52810)
#define GPIO_PIN_COUNT 32
#elif defined(TARGET_MCU_NRF52840)
#define GPIO_PIN_COUNT 48
#else
#error not recognized gpio count for mcu
#endif
```

### nano .platformio/packages/framework-mbed/targets/TARGET_NORDIC/TARGET_NRF5x/port_api.c
```
#if defined(TARGET_MCU_NRF51822)
    static const uint32_t m_gpio_pin_count[] = {31};
#elif defined(TARGET_MCU_NRF52832) || defined(TARGET_MCU_NRF52810)
    static const uint32_t m_gpio_pin_count[] = {32};
#elif defined(TARGET_MCU_NRF52840)
    static const uint32_t m_gpio_pin_count[] = {32, 16};
#else
    #error not recognized gpio count for mcu
#endif

```

# blink app compilation output
```
Generating LD script .pio/build/release/NRF52810.ld.link_script.ld
Linking .pio/build/release/firmware.elf
Checking size .pio/build/release/firmware.elf
Advanced Memory Usage is available via "PlatformIO Home > Project Inspect"
RAM:   [=         ]   5.1% (used 1232 bytes from 24000 bytes)
Flash: [=         ]  10.7% (used 20948 bytes from 196000 bytes)
Building .pio/build/release/firmware.hex
```