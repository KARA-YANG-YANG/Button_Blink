#include <stdio.h>
#include "blinkled.h"

#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"


#define BLINK_GPIO CONFIG_BLINK_GPIO
static const char *TAG = "blinkled2";

void blink_led(uint8_t s_led_state)
    {
        /* Set the GPIO level according to the state (LOW or HIGH)*/
        gpio_set_level(BLINK_GPIO, s_led_state);
    }
    
 void configure_led(void)
    {
        ESP_LOGI(TAG, "Example configured to blink GPIO LED!");
        gpio_reset_pin(BLINK_GPIO);
        /* Set the GPIO as a push/pull output */
        gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    }


