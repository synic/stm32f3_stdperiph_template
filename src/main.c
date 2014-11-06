#include "stm32f30x.h"

void delay(volatile long delay) {
    delay *= 1000;
    while(delay--) {}
}

void setup_gpio(void)
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOE, &GPIO_InitStructure);
}

int main(void)
{
  SystemInit();

  while (1)
  {
    GPIO_SetBits(GPIOE, GPIO_Pin_9);
    delay(1000);
    GPIO_ResetBits(GPIOE, GPIO_Pin_9);
    delay(1000);
  }

  return 0;
}

