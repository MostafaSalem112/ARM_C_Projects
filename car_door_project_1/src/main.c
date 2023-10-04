#include "LIB/STD_Types.h"
#include "LIB/BIT_Math.h"
#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MNVIC/MNVIC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MEXTI/MEXTI_interface.h"
#include "MCAL/MUART/MUART_interface.h"
#include "HAL/HCARKEY/HCARKEY_interface.h"
#include "HAL/HCARMOTOR/HCARMOTOR_interface.h"

void EXTI1_Handler(void){
	static u8 flag = 0;
	if(!flag){
		// Enable Car Motor
		HCARMOTOR_vEnable();
		MUART_vSendData('A');
		flag = 1;
	}else{
		// Disable Car Motor
		HCARMOTOR_vDisable();
		MUART_vSendData('B');
		flag = 0;
	}
}

int main(){

	MRCC_vInit();
	MRCC_vEnablePeripheralClock(RCC_GPIOA);
	MRCC_vEnablePeripheralClock(RCC_SYSCFG);
	MRCC_vEnablePeripheralClock(RCC_USART1);

	MNVIC_vSetPriorityGroups(GROUP_4_SUB_4);
	MNVIC_vSetInterruptPriority(EXTI0,GROUP_0,SUBGROUP_0);
	MNVIC_vEnableInterrupt(EXTI0);

	// Car Key Configurations
	HCARKEY_vInit();

	// Car Motor Configurations
	HCARMOTOR_vInit();

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_MODE_ALTFUN);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN9,ALTFUN_7);

	MEXTI_vSetExternalInterruptConfig(EXTI_line_0, EXTI_PORTA);
	MEXTI_vSetExternalInterruptTriggerType(EXTI_line_0,FALLING_TRIGGER);
	MEXTI_SetCallBack(EXTI_line_0,EXTI1_Handler);
	MEXTI_vEnableExternalInterrupt(EXTI_line_0);

	MUART_vInit();
	MUART_vEnable();

	while(1);

	return 0;
}
