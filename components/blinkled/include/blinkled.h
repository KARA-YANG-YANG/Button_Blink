#ifndef BLINKLED_H_
#define BLINKLED_H_


#ifdef __cplusplus
extern "C" {
#endif

void blink_led(uint8_t s_led_state);
void configure_led(void);

#ifdef __cplusplus
}
#endif

#endif /* BLINKLED_H_ */