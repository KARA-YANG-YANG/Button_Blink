#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include  "blinkled.h"

#include "iot_button.h"
#include "button_gpio.h"

static const char *TAG = "button-led-test";

/* Use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define BLINK_GPIO CONFIG_BLINK_GPIO

static uint8_t s_led_state = 0;

const button_config_t btn_cfg={0};

//按鍵回調執行事件函數
static void button_single_click_cb(void *arg,void *usr_data)
{
    ESP_LOGI(TAG, "Button single click");
    ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF"); 
    blink_led(s_led_state);
    s_led_state = !s_led_state;
}

void app_main(void)
{

    /* Configure the peripheral according to the LED type */
   configure_led();  

    const button_gpio_config_t btn_gpio_cfg={
        .gpio_num=0,               /**< num of gpio */
        .active_level=0,          /**< gpio level when press down */
    };
    button_handle_t gpio_btn = NULL;
    esp_err_t ret = iot_button_new_gpio_device(&btn_cfg,&btn_gpio_cfg,&gpio_btn);
    if(NULL == gpio_btn)
    {
     ESP_LOGE(TAG,"iot_button_Create fail");
    }

   // 註冊回調事件 
  
    iot_button_register_cb(gpio_btn,BUTTON_SINGLE_CLICK,NULL,button_single_click_cb,NULL);



    while (1) {
     // ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
     //   blink_led(s_led_state);
        /* Toggle the LED state */
     //   s_led_state = !s_led_state;
        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    }
}
