/*
 * HCARKEY_program.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Mostafa_Salem
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/MGPIO/MGPIO_interface.h"
#include "HCARKEY_config.h"
#include "HCARKEY_interface.h"

void HCARKEY_vInit(void){
	MGPIO_vSetPinMode(CARKEY_PORT,CARKEY_PIN,GPIO_MODE_INPUT);
	MGPIO_vSetPinInPutPull(CARKEY_PORT,CARKEY_PIN,GPIO_PULL_UP);
}
