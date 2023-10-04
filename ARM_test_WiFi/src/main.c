#include "LIB/STD_Types.h"
#include "LIB/BIT_Math.h"
#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MUART/MUART_interface.h"
#include "HAL/HWIFI/HWIFI_interface.h"


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

	HWIFI_voidInit();
	HWIFI_voidConnectToNetwork();
	HWIFI_voidConnectToServer();

	u8 WIFI_data[1] = {0};
	u8 wifi_status=0;

	while(1){
		wifi_status = HWIFI_u8GetData(WIFI_data);
		if(wifi_status && WIFI_data[0] == 1){
			MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
		}
		else if(wifi_status && WIFI_data[0] == 0){
			MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
		}
	}

	return 0;
}
