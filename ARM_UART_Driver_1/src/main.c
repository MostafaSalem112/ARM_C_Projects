#include "../include/STD_Types.h"
#include "../include/BIT_Math.h"
#include "../include/MRCC_interface.h"
#include "../include/MGPIO_interface.h"
#include "../include/MUART_interface.h"

int main(){

	MRCC_vInit();
	MRCC_vEnablePeripheralClock(RCC_GPIOA);
	MRCC_vEnablePeripheralClock(RCC_USART1);

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_INPUT);
	MGPIO_vSetPinInPutPull(GPIO_PORTA,GPIO_PIN0,GPIO_PULL_UP);

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_MODE_ALTFUN);
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_MODE_ALTFUN);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN9,ALTFUN_7);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN10,ALTFUN_7);

	MUART_vInit();
	MUART_vEnable();

	while(1){
		if(MGPIO_u8GetPinValue(GPIO_PORTA,GPIO_PIN0) == 0){
			MUART_vSendData('A');
		}
		else if(MGPIO_u8GetPinValue(GPIO_PORTA,GPIO_PIN0) == 1){
			MUART_vSendData('B');
		}
	}

	return 0;
}
