#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

const int BTN_PIN_R = 28;
const int BTN_PIN_G = 26;


int main() {
  int led_state_r = 0;
  int led_state_g = 0;

  stdio_init_all();


  // LEDS
  gpio_init(LED_PIN_G);
  gpio_init(LED_PIN_R);

  gpio_set_dir(LED_PIN_G, GPIO_OUT);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  // BOTOES
  gpio_init(BTN_PIN_R);
  gpio_init(BTN_PIN_G);

  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);

  gpio_pull_up(BTN_PIN_R);
  gpio_pull_up(BTN_PIN_G);


  while (true) {
    if(!gpio_get(BTN_PIN_R)){
      led_state_r = !led_state_r;
      gpio_put(LED_PIN_R, led_state_r);
      while (!gpio_get(BTN_PIN_R));

    }
    if(!gpio_get(BTN_PIN_G)){
      led_state_g = !led_state_g;
      gpio_put(LED_PIN_G, led_state_g);
      while (!gpio_get(BTN_PIN_G));
 
    }

  }
}
