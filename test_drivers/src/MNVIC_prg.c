#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/MNVIC_prv.h"
#include "../include/MNVIC_int.h"
#include "../include/MNVIC_cfg.h"

static u8 Global_u8IPR=0;

void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntPos) {
    NVIC->ISER[Copy_u8IntPos/Reg_div] |=1<<(Copy_u8IntPos%Reg_div);
}
void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntPos) {
	NVIC->ICER[Copy_u8IntPos/Reg_div] |=1<<(Copy_u8IntPos%Reg_div);
}
void MNVIC_VoidEnableInterruptPending(u8 Copy_u8IntPos) {
	NVIC->ISPR[Copy_u8IntPos/Reg_div] |=1<<(Copy_u8IntPos%Reg_div);
}
void MNVIC_VoidDisableInterruptPending(u8 Copy_u8IntPos) {
	NVIC->ICPR[Copy_u8IntPos/Reg_div] |=1<<(Copy_u8IntPos%Reg_div);
}

void MNVIC_u8IsInterruptActive(u8 Copy_u8IntPos,u8 *Copy_Read) {
	*Copy_Read=GET_BIT((NVIC->IABR[Copy_u8IntPos/Reg_div]),(Copy_u8IntPos%Reg_div));
}
void MNVIC_VoidSetInterruptPriority(u8 Copy_u8IntPos,u8 Copy_u8GroupNum,u8 Copy_u8SubGroupNum) {
  switch(Global_u8IPR){
  case Group16Sub0 :  NVIC->IPR[Copy_u8IntPos] = Copy_u8GroupNum<<4  ;                                break;
  case Group8Sub2  :  NVIC->IPR[Copy_u8IntPos] = Copy_u8GroupNum<<5 | Copy_u8SubGroupNum<<4;          break;
  case Group4Sub4  :  NVIC->IPR[Copy_u8IntPos] = Copy_u8GroupNum<<6 | Copy_u8SubGroupNum<<4;          break;
  case Group2Sub8  :  NVIC->IPR[Copy_u8IntPos] = Copy_u8GroupNum<<7 | Copy_u8SubGroupNum<<4;          break;
  case Group0Sub16 :  NVIC->IPR[Copy_u8IntPos] = Copy_u8SubGroupNum<<4 ;                              break;
  default: break;
  }
}
void MNVIC_VoidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode) {
	Global_u8IPR=Copy_uddtGroupMode;
	SCB_AIRCR =MNVIC_VECTKEY;
	u32 Copy_u32Local =   MNVIC_VECTKEY | (Copy_uddtGroupMode<<8)      ;
    SCB_AIRCR = Copy_u32Local ;
}
































