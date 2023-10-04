#include "../include/STD_Types.h"
#include "../include/BIT_Math.h"
#include "../include/MRCC_interface.h"
#include "../include/MGPIO_interface.h"
#include "../include/MSYSTICK_interface.h"
#include "../include/song.h"

void R2R_DAC(void){
	static u32 index = 0;

	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN0,GET_BIT(Song_Array[index],0));
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN1,GET_BIT(Song_Array[index],1));
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN2,GET_BIT(Song_Array[index],2));
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN3,GET_BIT(Song_Array[index],3));
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN4,GET_BIT(Song_Array[index],4));
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN5,GET_BIT(Song_Array[index],5));
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN6,GET_BIT(Song_Array[index],6));
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN7,GET_BIT(Song_Array[index],7));

	index++;
	if(index >= 24242){
		index=0;
	}
}


int main(){
	MRCC_vInit();
	MRCC_vEnablePeripheralClock(RCC_GPIOA);

	MSYSTICK_vInit();


	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN4,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN7,GPIO_MODE_OUTPUT);

	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN0,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN0,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN0,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN0,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN0,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN0,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN0,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN0,GPIO_PUSHPULL);

	MSYSTICK_SetInterval_Periodic(125,R2R_DAC);

	return 0;
}
