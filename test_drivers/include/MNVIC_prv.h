#ifndef MNVIC_PRV_H
#define MNVIC_PRV_H

#define MNVIC_BASE_ADRESS   (0xE000E100)


typedef struct
{
 u32 ISER[8];
 u32 reserved0[24];
 u32 ICER[8];
 u32 reserved1[24];
 u32 ISPR[8];
 u32 reserved2[24];
 u32 ICPR[8];
 u32 reserved3[24];
 u32 IABR[8];
 u32 resreved4[56];
 u8 IPR[240];
 u32 reserved5[580];
 u32 STIR;

}NVIC_t;


#define NVIC              ((volatile NVIC_t*)MNVIC_BASE_ADRESS)
#define SCB_AIRCR         (*(volatile u32*)0xE000ED0C)
#define MNVIC_VECTKEY     0X05FA0000

















#endif
