/*
 * HCARMOTOR_program.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "HCARMOTOR_config.h"
#include "HCARMOTOR_interface.h"

void HCARMOTOR_vInit(void){
	MGPIO_vSetPinMode(CARMOTOR_PORT,CARMOTOR_PIN,GPIO_MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(CARMOTOR_PORT,CARMOTOR_PIN,GPIO_PUSHPULL);
	MGPIO_vSetPinOutPutSpeed(CARMOTOR_PORT,CARMOTOR_PIN,GPIO_LOW_SPEED);
	MGPIO_vSetPinValue(CARMOTOR_PORT,CARMOTOR_PIN,GPIO_LOW);
}

void HCARMOTOR_vEnable(void){
	MGPIO_vSetPinValue(CARMOTOR_PORT,CARMOTOR_PIN,GPIO_HIGH);
}

void HCARMOTOR_vDisable(void){
	MGPIO_vSetPinValue(CARMOTOR_PORT,CARMOTOR_PIN,GPIO_LOW);
}
