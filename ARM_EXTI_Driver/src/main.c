#include "../include/STD_Types.h"
#include "../include/BIT_Math.h"

#include "../include/MRCC_interface.h"
#include "../include/MNVIC_interface.h"
#include "../include/MGPIO_interface.h"
#include "../include/MEXTI_interface.h"

void func(){
	static u8 flag = 1;
	if(flag){
		MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
		flag = 0;
	}
	else{
		MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
		flag = 1;
	}

}

int main(){
	MRCC_vInit();
	MRCC_vEnablePeripheralClock(RCC_GPIOA);
	MRCC_vEnablePeripheralClock(RCC_SYSCFG);

	MNVIC_vSetPriorityGroups(GROUP_16_SUB_0);
	MNVIC_vSetInterruptPriority(EXTI0,GROUP_0,SUBGROUP_0);
	MNVIC_vEnableInterrupt(EXTI0);

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(GPIO_PORTA,GPIO_PIN1,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutSpeed(GPIO_PORTA,GPIO_PIN1,GPIO_LOW_SPEED);
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_INPUT);
	MGPIO_vSetPinInPutPull(GPIO_PORTA,GPIO_PIN0,GPIO_PULL_UP);

	MEXTI_vSetExternalInterruptTriggerType(EXTI_line_0,FALLING_TRIGGER);
	MEXTI_vEnableExternalInterrupt(EXTI_line_0);
	MEXTI_vSetExternalInterruptConfig(EXTI_line_0,EXTI_PORTA);
	MEXTI_SetCallBack(EXTI_line_0,func);

	while(1);

	return 0;
}
