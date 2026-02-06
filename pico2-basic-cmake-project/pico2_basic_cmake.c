/**
 * @file pico2_basic_cmake.c
 * @brief Simple program to blink the on-board LED on a Raspbery Pico microcontroller.
 * @author Brendan Leber <n0bml@brendanleber.com>
 *
 * The author disclaims copyright to this source code.
 */

#include <stdio.h>
#include <pico/stdlib.h>
#include <pico/binary_info.h>

/**
 * This macro must be defined so we know what pin to use for the on-board LED.
 *
 * It should be defined by the SDK but can be overridden to use a different pin.
 * The macro must also have a value.
 */
#if !defined(PICO_DEFAULT_LED_PIN) && !(PICO_DEFAULT_LED_PIN + 0)
#error "The macro PICO_DEFAULT_LED_PIN must be defined!"
#endif

// Set the default delay to 1000 ms, unless overridden by compiler directives.
#if !defined(LED_DELAY_MS)
#define LED_DELAY_MS 1000
#endif

/**
 * These declarations are not required but are helpful to get information about the
 * binary using `picotool`.
 */
bi_decl(bi_program_name("pico2_basic_cmake"));
bi_decl(bi_program_description("Pico 2 Basic CMake Project."));
bi_decl(bi_1pin_with_name(PICO_DEFAULT_LED_PIN, "On-board LED"));

void led_init(void)
{
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
}

void led_set(bool led_on)
{
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
}

int main()
{
    stdio_init_all();
    led_init();

    while (true) {
        puts("Hello from the Pico 2 basic CMake project!");

        led_set(true);
        sleep_ms(LED_DELAY_MS);

        led_set(false);
        sleep_ms(LED_DELAY_MS);
    }

    return 0;
}
