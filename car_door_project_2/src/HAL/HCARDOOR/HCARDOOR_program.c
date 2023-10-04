/*
 * HCARDOOR_program.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "HCARDOOR_config.h"
#include "HCARDOOR_interface.h"


void HCARDOOR_vInit(void){
	MGPIO_vSetPinMode(CARDOOR_PORT,CARDOOR_PIN,GPIO_MODE_INPUT);
	MGPIO_vSetPinInPutPull(CARDOOR_PORT,CARDOOR_PIN,GPIO_PULL_UP);
}

u8	 HCARDOOR_u8GetDoorStatus(void){
	return MGPIO_u8GetPinValue(CARDOOR_PORT,CARDOOR_PIN);
}
