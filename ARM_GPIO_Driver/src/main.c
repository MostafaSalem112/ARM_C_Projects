#include "../include/STD_Types.h"
#include "../include/BIT_Math.h"
#include "../include/MRCC_interface.h"
#include "../include/MGPIO_interface.h"

int main(){

	MRCC_vInit();
	MRCC_vEnablePeripheralClock(RCC_GPIOA);
	MRCC_vEnablePeripheralClock(RCC_GPIOB);
	MRCC_vEnablePeripheralClock(RCC_GPIOC);

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN0,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutSpeed(GPIO_PORTA,GPIO_PIN0,GPIO_MEDIUM_SPEED);

	MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN10,GPIO_MODE_INPUT);
	MGPIO_vSetPinInPutPull(GPIO_PORTB,GPIO_PIN10,GPIO_PULL_UP);

	MGPIO_vSetPinMode(GPIO_PORTC,GPIO_PIN15,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(GPIO_PORTC,GPIO_PIN15,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutSpeed(GPIO_PORTC,GPIO_PIN15,GPIO_VERY_HIGH_SPEED);

	u32 counter;
	while(1){
		counter = 1000000;
		MGPIO_vSetPinValue_Fast(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
		while(counter--);
		counter = 1000000;
		MGPIO_vSetPinValue_Fast(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
		while(counter--);

		if(MGPIO_u8GetPinValue(GPIO_PORTB,GPIO_PIN10) == GPIO_LOW){
			MGPIO_vSetPinValue_Fast(GPIO_PORTC,GPIO_PIN15,GPIO_HIGH);
		}
		else{
			MGPIO_vSetPinValue_Fast(GPIO_PORTC,GPIO_PIN15,GPIO_LOW);
		}
	}

	return 0;
}
