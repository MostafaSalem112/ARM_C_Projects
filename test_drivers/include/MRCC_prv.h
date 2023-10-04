#ifndef MRCC_PRV_H
#define MRCC_PRV_H

#define RCC_BASE_ADRESS   (0x40023800)

typedef struct 
{
u32 CR;
u32 PLLCFGR;
u32 CFGR;
u32 CIR;
u32 AHB1RSTR;
u32 AHB2RSTR;
u32 reserved0;
u32 reserved1;
u32 APB1RSTR;
u32 APB2RSTR;
u32 reserved2;
u32 reserved3;
u32 AHB1ENR;
u32 AHB2ENR;
u32 reserved4;
u32 reserved5;
u32 APB1ENR;
u32 APB2ENR;
u32 reserved6;
u32 reserved7;
u32 AHB1LPENR;
u32 AHB2LPENR;
u32 reserved8;
u32 reserved9;
u32 APB1LPENR;
u32 APB2LPENR;
u32 reserved10;
u32 reserved11;
u32 BDCR;
u32 CSR;
u32 reserved12;
u32 reserved13;
u32 SSCGR;
u32 PLLI2SCFGR;
u32 reserved14;
u32 DCKCFGR;

}RCC_t;

#define     RCC                  ((volatile RCC_t*)RCC_BASE_ADRESS)


#define RCC_HSI        0
#define RCC_HSE        1
#define RCC_PLL        2

#define HSE_RC   0
#define HSE_CRYSTAL   1


#define CR_HSE_EN   16
#define CR_HSI_EN   0
#define CR_PLL_EN   24

#define CR_HSEBYP    18



#define SWITCH_MUSK  0xFFFFFFFC
#define SWITCH_HSI    0
#define SWITCH_HSE    1
#define SWITCH_PLL    2







#endif
