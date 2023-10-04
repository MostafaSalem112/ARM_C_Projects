#ifndef MSYSTICK_PRV_H
#define MSYSTICK_PRV_H

#define SYSTICK_BASE_ADRESS   (0xE000E010)
#define TickInt 1
#define CountFlag 16
#define ClockSource 2

#define AHB_DIVIDEBY8 0
#define AHB 1

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;

}MSYSTICK_t;


#define SYSTICK       ((volatile MSYSTICK_t*)SYSTICK_BASE_ADRESS)














#endif
