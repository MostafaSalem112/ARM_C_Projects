/*
 * HCARMOTOR_interface.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Mostafa_Salem
 */

#ifndef HAL_HCARMOTOR_HCARMOTOR_INTERFACE_H_
#define HAL_HCARMOTOR_HCARMOTOR_INTERFACE_H_

#define PORTA	0
#define PORTB	1
#define PORTC	2

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15


void HCARMOTOR_vInit(void);
void HCARMOTOR_vEnable(void);
void HCARMOTOR_vDisable(void);

#endif /* HAL_HCARMOTOR_HCARMOTOR_INTERFACE_H_ */
