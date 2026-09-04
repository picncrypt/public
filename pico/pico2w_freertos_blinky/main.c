#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main() {

    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("cyw43 init failed\n");
        return -1;
    }

    while (true) {
        // Turn the onboard LED ON
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(500);

        // Turn the onboard LED OFF
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(500);
    }
}
