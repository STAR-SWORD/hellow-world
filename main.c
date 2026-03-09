#include "stm32f10x.h"

void delay(uint32_t cnt) {
    while(cnt--);
}

int main(void) {
    GPIO_InitTypeDef gpio;

    // 使能 GPIOC 时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // PC0 = A0 推挽输出
    gpio.GPIO_Pin = GPIO_Pin_0;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &gpio);

    while(1) {
        GPIO_SetBits(GPIOC, GPIO_Pin_0);  // 亮
        delay(1000000);
        GPIO_ResetBits(GPIOC, GPIO_Pin_0);// 灭
        delay(1000000);
    }
}