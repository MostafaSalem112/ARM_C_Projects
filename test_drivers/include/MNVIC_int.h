#ifndef MNVIC_INT_H
#define MNVIC_INT_H


#define Reg_div 32

typedef enum{
 Group16Sub0=3,
 Group8Sub2,
 Group4Sub4,
 Group2Sub8,
 Group0Sub16

}MNVIC_Group_t;


void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntPos) ;
void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntPos) ;
void MNVIC_VoidEnableInterruptPending(u8 Copy_u8IntPos) ;
void MNVIC_VoidDisableInterruptPending(u8 Copy_u8IntPos) ;
void MNVIC_u8IsInterruptActive(u8 Copy_u8IntPos,u8 *Copy_Read) ;
void MNVIC_VoidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode) ;
















void MNVIC_VoidSetInterruptPriority(u8 Copy_u8IntPos,u8 Copy_u8GroupNum,u8 Copy_u8SubGroupNum) ;






#endif
