#include "../include/STD_Types.h"
#include "../include/BIT_Math.h"
#include "../include/MRCC_interface.h"
#include "../include/MGPIO_interface.h"
#include "../include/MUART_interface.h"


int main(){

	MRCC_vInit();
	MRCC_vEnablePeripheralClock(RCC_GPIOA);
	MRCC_vEnablePeripheralClock(RCC_USART1);

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN0,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutSpeed(GPIO_PORTA,GPIO_PIN0,GPIO_MEDIUM_SPEED);
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_MODE_ALTFUN);
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_MODE_ALTFUN);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN9,ALTFUN_7);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN10,ALTFUN_7);

	MUART_vInit();
	MUART_vEnable();

	u8 L_u8UART_ReceivedData;

	while(1){
		L_u8UART_ReceivedData = MUART_u8ReceiveData();
		if(L_u8UART_ReceivedData == 'A'){
			MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
		}
		else if(L_u8UART_ReceivedData == 'B'){
			MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
		}
	}

	return 0;
}
