#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "FreeRTOS.h"
#include "task.h"


void cyw43_BlinkTask() {

    while (true) {

        // Turn the onboard LED ON
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        vTaskDelay(500);

        // Turn the onboard LED OFF
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        vTaskDelay(500);
    }
}

int main() {

    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("cyw43 init failed\n");
        return -1;
    }

    xTaskCreate(cyw43_BlinkTask, "Blink Task", 256, NULL, 1, NULL);

    vTaskStartScheduler();
}
