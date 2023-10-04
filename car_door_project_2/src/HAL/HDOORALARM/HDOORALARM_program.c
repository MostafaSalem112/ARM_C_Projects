/*
 * HDOORALARM_program.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "HDOORALARM_config.h"
#include "HDOORALARM_interface.h"

void HDOORALARM_vInit(void){
	MGPIO_vSetPinMode(DOORALARM_PORT,DOORALARM_PIN,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(DOORALARM_PORT,DOORALARM_PIN,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutSpeed(DOORALARM_PORT,DOORALARM_PIN,GPIO_LOW_SPEED);
	MGPIO_vSetPinValue(DOORALARM_PORT,DOORALARM_PIN,GPIO_LOW);
}

void HDOORALARM_vEnable(void){
	MGPIO_vSetPinValue(DOORALARM_PORT,DOORALARM_PIN,GPIO_HIGH);
}

void HDOORALARM_vDisable(void){
	MGPIO_vSetPinValue(DOORALARM_PORT,DOORALARM_PIN,GPIO_LOW);
}
