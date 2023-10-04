#include "../include/STD_Types.h"
#include "../include/BIT_Math.h"
#include "../include/MRCC_interface.h"
#include "../include/MNVIC_interface.h"
#include "../include/MGPIO_interface.h"
#include "../include/MEXTI_interface.h"
#include "../include/MSYSTICK_interface.h"


void func(void){
	MEXTI_vDisableExternalInterrupt(EXTI_line_0);
	MSYSTICK_vDelay_ms(5000);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN0,GPIO_HIGH);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
	MSYSTICK_vDelay_ms(5000);

	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN0,GPIO_LOW);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
	MSYSTICK_vDelay_ms(5000);

	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN0,GPIO_LOW);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);
	MSYSTICK_vDelay_ms(5000);

	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN0,GPIO_LOW);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);
	MEXTI_vEnableExternalInterrupt(EXTI_line_0);
}

int main(){

	MRCC_vInit();
	MRCC_vEnablePeripheralClock(RCC_GPIOA);
	MRCC_vEnablePeripheralClock(RCC_GPIOB);
	MRCC_vEnablePeripheralClock(RCC_SYSCFG);

	MNVIC_vSetPriorityGroups(GROUP_4_SUB_4);
	MNVIC_vSetInterruptPriority(EXTI0,GROUP_0,SUBGROUP_1);
	MNVIC_vEnableInterrupt(EXTI0);

	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_INPUT);
	MGPIO_vSetPinInPutPull(GPIO_PORTA,GPIO_PIN0,GPIO_PULL_UP);

	MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN0,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN1,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinMode(GPIO_PORTB,GPIO_PIN2,GPIO_MODE_OUTPUT);

	MGPIO_vSetPinOutPutType(GPIO_PORTB,GPIO_PIN0,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutType(GPIO_PORTB,GPIO_PIN1,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutType(GPIO_PORTB,GPIO_PIN2,GPIO_PUSHPULL);

	MGPIO_vSetPinOutPutSpeed(GPIO_PORTB,GPIO_PIN0,GPIO_LOW_SPEED);
	MGPIO_vSetPinOutPutSpeed(GPIO_PORTB,GPIO_PIN1,GPIO_LOW_SPEED);
	MGPIO_vSetPinOutPutSpeed(GPIO_PORTB,GPIO_PIN2,GPIO_LOW_SPEED);

	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN0,GPIO_LOW);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);
	MGPIO_vSetPinValue_Fast(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);

	MEXTI_vSetExternalInterruptTriggerType(EXTI_line_0,FALLING_TRIGGER);
	MEXTI_vSetExternalInterruptConfig(EXTI_line_0,EXTI_PORTA);
	MEXTI_SetCallBack(EXTI_line_0,func);
	MEXTI_vEnableExternalInterrupt(EXTI_line_0);

	MSYSTICK_vInit();

	while(1);

	return 0;
}
