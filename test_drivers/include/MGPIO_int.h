#ifndef MGPIO_INT_H
#define MGPIO_INT_H
/*          Port Macros                    */
 #define PORTA   0
 #define PORTB   1
 #define PORTC   2

/*          Port Macros                    */

  #define PIN0    0
  #define PIN1    1
  #define PIN2    2
  #define PIN3    3
  #define PIN4    4
  #define PIN5    5
  #define PIN6    6
  #define PIN7    7
  #define PIN8    8
  #define PIN9    9
  #define PIN10   10
  #define PIN11   11
  #define PIN12   12
  #define PIN13   13
  #define PIN14   14
  #define PIN15   15

/*           Mode Macros                    */
  #define  INPUT        0
  #define  OUTPUT       1
  #define  ALT_FUNC     2
  #define  ANALOG       3

/*           OUTPUT Mode Macros                    */
 #define OUTPUT_PUSH_PULL           0
 #define OUTPUT_OPEN_DRAIN          1

/*           OUTPUT speed Macros                    */

  #define OUTPUT_LOW        0
  #define OUTPUT_MEDIUM     1
  #define OUTPUT_HIGH       2
  #define OUTPUT_VHIGH      3

/*           INPUT  Macros                    */
  #define INPUT_Float        0
  #define INPUT_Pulldown     1
  #define INPUT_VHigh        2

/*           Set/reset speed Macros                    */
#define  OUTPUT_SET          0
#define  OUTPUT_RESET        1

#define STD_LOW		0
#define STD_HIGH	1


void MGPIO_SetMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);

void MGPIO_SetOutputPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8OutMode,u8 Copy_u8Speed);

void MGPIO_SetInputPin(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8InputMode);

void MGPIO_GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 * Copy_pu8Data);

void MGPIO_SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8  Copy_u8Data);

void MGPIO_SetResetvalue(u8 Copy_u8Port,u8 Copy_u8Pin,u8  Copy_u8SetOrReset);












#endif
