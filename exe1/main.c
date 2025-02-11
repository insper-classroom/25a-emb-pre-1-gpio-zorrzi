#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 5;
const int LED_PIN_G = 28;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN_R);
  gpio_init(LED_PIN_G);

  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  while (true) {
    gpio_put(LED_PIN_R, 1);
    gpio_put(LED_PIN_G, 1);
    sleep_ms(250);

    gpio_put(LED_PIN_R, 0);
    gpio_put(LED_PIN_G, 0);
    sleep_ms(250);
  }
}
