#include "../include/ARM_RCC.h"


#define LED_PIN 	GPIO_PIN_13
#define LED_PORT 	GPIOC

void delay(volatile uint32_t count){
	while(count--);
}

int main(){

	/*Initialize RCC*/
	RCC_Init();

	/*Enable GPIO clock*/
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

	/*Set LED PIN as output*/
	LED_PORT->MODER |= GPIO_MODER_MODER13_0;

	while(1){

		/*toggle LED*/
		LED_PORT->ODR ^= LED_PIN;

		/*Delay*/
		delay(1000000);
	}

	return 0;
}
