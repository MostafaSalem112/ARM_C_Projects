#ifndef MSYSTICK_INT_H
#define MSYSTICK_INT_H

typedef enum
{
	SYSTICKEnable,
	SYSTICKDisable
}SYSTICKState;

void MSYSYTICK_voidInit(void);

void MSYSYTICK_voidStart(u32 Copy_u32Loadvalue);

void MSYSYTICK_voidDelayMs(u32 Copy_u32Delayvalue);

void MSYSYTICK_voidDelayms(u32 Copy_u32Delayvalue);

u8   MSYSYTICK_voidReadFlag(void);

void MSYSYTICK_voidCtrlIntState(SYSTICKState Copy_State );

u32  MSTK_u32GetElapsedTime(void);

u32  MSTK_u32GetRemainingTime(void);
















#endif
