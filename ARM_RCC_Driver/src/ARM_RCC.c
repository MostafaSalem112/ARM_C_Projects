/*
 * ARM_RCC.c
 *
 *  Created on: Aug 8, 2023
 *      Author: Mostafa_Salem
 */
#include "../include/ARM_RCC.h"

void RCC_Init(void){

	/*Enable HSI (High  Speed Internal clock)*/
	RCC->CR |= RCC_CR_HSION;

	/*wait till HSI is ready*/
	while(!(RCC->CR & RCC_CR_HSIRDY));

	/*select HSI as the system clock source*/
	RCC->CFGR &= ~(RCC_CFGR_SW);
	RCC->CFGR |= RCC_CFGR_SW_HSI;

	/*wait till HSI is used as the system clock source*/
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);
}
