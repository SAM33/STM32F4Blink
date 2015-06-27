#include "main.h"

int main() {
    init();

    do {
        loop();
    } while (1);
}


void init() {
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef gpio;
    GPIO_StructInit(&gpio);
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Pin = LEDS;
    GPIO_Init(GPIOD, &gpio);
    GPIO_SetBits(GPIOD, LEDS);
}

void loop() {
    static uint32_t counter = 0;

    ++counter;

    GPIO_ResetBits(GPIOD, LEDS);
    GPIO_SetBits(GPIOD, LED[counter % 4]);

    delay(1000);
}

void delay(uint32_t ms) {
    uint32_t c;
    /*
	while loop = 4 , 
        1000us clocks needed = 168010(STM32F407 MAX = 168MHz) ,
 	1000us clocks needed = 42010(STM32F407 Default = 42MHz) , 
        compute 'c' clocks = 10
    */

    c = ms*42010/4-10;
    while(c--){;};
}
