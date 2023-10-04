#include "LIB/STD_Types.h"
#include "LIB/BIT_Math.h"
#include "MCAL/MRCC/MRCC_interface.h"
#include "MCAL/MGPIO/MGPIO_interface.h"
#include "MCAL/MFMI/MFMI_interface.h"
#include "MCAL/MSYSTIKC/MSYSTICK_interface.h"
#include "MCAL/MUART/MUART_interface.h"
#include "HAL/HWIFI/HWIFI_interface.h"
#include "APP/AHexParser/AHexParser_interface.h"


u8 u8RecBuffer[100] = {0}   ;
u8 u8RecCounter     =  0    ;
u8 TimeOutFlag      =  0    ;
u8 u8BLWriteReq     =  1    ;
u8 HexFileData[50000];
u32 HexCounter=0;
u8 DataStatus=0;

typedef void (*Function_t)(void) ;

Function_t  Addr_To_Call = 0;  // void (*Addr_To_Call)(void)
void Func_CallBack(void){

	/*Some Code*/

	TimeOutFlag = 1 ;

#define SCB_VTOR  *((volatile u32 *)0xE000ED08)

	/*Move Vector table*/
	SCB_VTOR     = 0x08004000 ; //starting of Sector 1

	/*set Address to call with RESET_ISR(Startup code of Application)*/
	Addr_To_Call = *(Function_t *)0x08004004 ;

	Addr_To_Call();

}

int main(){

	/*************************************************************************************************************************/
	/********************************Step 1: initialize System Clock is 16MHz from HSI****************************************/
	/*************************************************************************************************************************/

	/*System Clock is 16MHz from HSI*/
	MRCC_vInit();

	/*************************************************************************************************************************/
	/********************************************Step 2: Enable peripherals clock*********************************************/
	/*************************************************************************************************************************/

	/*Enable GPIO Peripheral clock*/
	MRCC_vEnablePeripheralClock(RCC_GPIOA);

	/*Enable RCC For USART1*/
	MRCC_vEnablePeripheralClock(RCC_USART1); //Enable CLK Of UART1   At APB2

	/*Enable FPEC*/
	//MRCC_vEnablePeripheralClock(AHB1,_PERIPHERAL_EN_FPEC ) ;

	/*************************************************************************************************************************/
	/********************************************Step 3: Configure UART1 ,UART2 Pins******************************************/
	/*************************************************************************************************************************/

	MGPIO_vSetPinMode(GPIO_PORTA, GPIO_PIN9, GPIO_MODE_ALTFUN);     //TX-->UART1
	MGPIO_vSetPinMode(GPIO_PORTA, GPIO_PIN10, GPIO_MODE_ALTFUN);    //RX-->UART1
	MGPIO_vSetAlternativeFunction(GPIO_PORTA, GPIO_PIN9, ALTFUN_7);      //TX-->UART1
	MGPIO_vSetAlternativeFunction(GPIO_PORTA, GPIO_PIN10, ALTFUN_7);     //RX-->UART1

	/*************************************************************************************************************************/
	/********************************************Step 4: initialize indicators Pins in System ********************************/
	/*************************************************************************************************************************/

	for(u8 PIN = GPIO_PIN0; PIN < GPIO_PIN3; PIN++ )
	{
		/*Set Pin Mode --> Output*/
		MGPIO_vSetPinMode(GPIO_PORTA, PIN, GPIO_MODE_OUTPUT) ;
		/*Out put Push Pull*/
		MGPIO_vSetPinOutPutType(GPIO_PORTA,PIN,GPIO_PUSHPULL);
		/*Pin Speed*/
		MGPIO_vSetPinOutPutSpeed(GPIO_PORTA, PIN, GPIO_MEDIUM_SPEED);
	}
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN1, GPIO_HIGH) ; //indicate to I am in BootLoader Code
	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN2, GPIO_HIGH) ;

	/*************************************************************************************************************************/
	/********************************************Step 5: Initialize USART1 ***************************************************/
	/*************************************************************************************************************************/

	MUART_vInit();
	MUART_vEnable();

	/*************************************************************************************************************************/
	/********************************************Step 6: Initialize ESP8266 **************************************************/
	/*************************************************************************************************************************/

	HWIFI_voidInit();
	HWIFI_voidConnectToNetwork();
	HWIFI_voidConnectToServer();

	/*************************************************************************************************************************/
	/********************************************Step 7: Initialize SysTick **************************************************/
	/*************************************************************************************************************************/

	MSYSTICK_vInit();
	MSYSTICK_SetInterval_Single(15000,Func_CallBack);

	/*************************************************************************************************************************/
	/********************************************Step 8: Get The HEX File From Web *******************************************/
	/*************************************************************************************************************************/

	while(TimeOutFlag == 0){
		if(DataStatus == 0){
			DataStatus = HWIFI_u8GetData (HexFileData);
		}else{
			u8RecBuffer[u8RecCounter]=HexFileData[HexCounter++];

            /*Stop timer Application code in processing*/
			MSYSTICK_vStopTimer();

			/*Indicate The end of the Record*/
			if(HexFileData[HexCounter] == '\n'){
				if( u8BLWriteReq == 1 ){
                    /*Erase The Application Area*/
					MFMI_vEraseAppArea();
					/*Set WriteReq Flag = 0 */
					u8BLWriteReq = 0 ;
				}
                /*Parse The record and wait it to flash*/
				AHexParser_vParseData( u8RecBuffer );
				u8RecCounter=0;
			}else{
				u8RecCounter++;
			}

			/*End of hex file */
			if( u8RecBuffer[8] == '1' ){
                /*wait a second then jump to application code*/
				MSYSTICK_SetInterval_Single( 1000000 , Func_CallBack );
				MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN0, GPIO_HIGH) ; //indicate to successful flashing
			}
		}
	}
	return 0;
}
