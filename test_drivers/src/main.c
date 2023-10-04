#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/MRCC_int.h"
#include "../include/MNVIC_int.h"
#include "../include/MGPIO_int.h"
#include "../include/MEXTI_int.h"
#include "../include/MSYSTICK_int.h"


int main(){

	MRCC_init();
	MRCC_Enable_peripheral(RCC_APB1,AHB1_GPIOA);
	MSYSYTICK_voidInit();

	MGPIO_SetMode(PORTA,PIN0,OUTPUT);
	MGPIO_SetOutputPinMode(PORTA,PIN0,OUTPUT_PUSH_PULL,OUTPUT_MEDIUM);
	MGPIO_SetResetvalue(PORTA,PIN0,OUTPUT_SET);

	while(1){
		MGPIO_SetResetvalue(PORTA,PIN0,OUTPUT_SET);
		MSYSYTICK_voidDelayms(1000);
		MGPIO_SetResetvalue(PORTA,PIN0,OUTPUT_RESET);
		MSYSYTICK_voidDelayms(1000);
	}

	return 0;
}
