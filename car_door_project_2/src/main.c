#include "LIB/STD_Types.h"
#include "LIB/BIT_Math.h"
#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MNVIC/MNVIC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MEXTI/MEXTI_interface.h"
#include "MCAL/MUART/MUART_interface.h"
#include "HAL/HDOORALARM/HDOORALARM_interface.h"
#include "HAL/HCARDOOR/HCARDOOR_interface.h"

u8 flag = 0;

void UART_ReceptionHandler(void){
	u8 ReceivedData = MUART_u8ReceiveData();
	if(ReceivedData == 'A'){
		flag = 1;
	}else if(ReceivedData == 'B'){
		flag = 0;
	}
}

int main(){

	MRCC_vInit();
	MRCC_vEnablePeripheralClock(RCC_GPIOA);
	MRCC_vEnablePeripheralClock(RCC_SYSCFG);
	MRCC_vEnablePeripheralClock(RCC_USART1);

	MNVIC_vSetPriorityGroups(GROUP_4_SUB_4);
	MNVIC_vSetInterruptPriority(USART1,GROUP_0,SUBGROUP_0);
	MNVIC_vEnableInterrupt(USART1);

	// Car Door Configurations
	HCARDOOR_vInit();

	// Door Alarm Configurations
	HDOORALARM_vInit();

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_MODE_ALTFUN);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN10,ALTFUN_7);

	MUART_vInit();
	MUART_vEnable();
	MUART_vEnableReceptionInterrupt();
	MUART_vCallBack(UART_ReceptionHandler);

	u8 CarDoorLock;

	while(1){

		// Get Car Door Status
		CarDoorLock = HCARDOOR_u8GetDoorStatus();

		if(flag && CarDoorLock){
			// Enable Door Alarm
			HDOORALARM_vEnable();
		}else{
			// Disable Door Alarm
			HDOORALARM_vDisable();
		}

	}

	return 0;
}
