#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/MRCC_prv.h"
#include "../include/MRCC_cfg.h"
#include "../include/MRCC_int.h"


void MRCC_init(void){
    
#if (SYS_CLK== RCC_HSE)

//choose CLK between crystal and RC 
    #if (HSE_OSC==HSE_CRYSTAL)
    RCC->CR &= ~(1<<CR_HSEBYP);
    #elif (HSE_OSC==HSE_RC)
    RCC->CR |= 1<<CR_HSEBYP;
    #endif


// make HSE ready 
RCC->CR |= 1<<CR_HSI_EN;
while(!GET_BIT(RCC->CR,(CR_HSI_EN+1)));
// switch to HSE 
RCC->CFGR &= SWITCH_MUSK;
RCC->CFGR |=SWITCH_HSE;


#elif (SYS_CLK== RCC_HSI)


// make HSI ready
RCC->CR |= 1<<CR_HSI_EN;
while(!GET_BIT(RCC->CR,(CR_HSI_EN+1)));
// switch to HSI
RCC->CFGR &= SWITCH_MUSK;
RCC->CFGR |=SWITCH_HSI;



#elif (SYS_CLK==RCC_PLL)


// make PLL ready
RCC->CR |= 1<<CR_PLL_EN;
while(!GET_BIT(RCC->CR,(CR_PLL_EN+1)));
// switch to HSI 
RCC->CFGR &= SWITCH_MUSK;
RCC->CFGR |=SWITCH_PLL;



#endif
    
}

void MRCC_Enable_peripheral(u32 Copy_u32Adress_Bus, u32 Copy_u32peripheral){
    switch (Copy_u32Adress_Bus){
        case RCC_APB1:
        RCC->APB1ENR |=1<<Copy_u32peripheral;
        break;
        case RCC_APB2:
        RCC->APB2ENR |=1<<Copy_u32peripheral;
        break;
        case RCC_AHB1:
        RCC->AHB1ENR |=1<<Copy_u32peripheral;
        break;
        case RCC_AHB2:
        RCC->AHB2ENR |=1<<Copy_u32peripheral;
        break;
        default:
        break;
    }
}

void MRCC_disable_peripheral(u32 Copy_u32Adress_Bus, u32 Copy_u32peripheral ){
 switch (Copy_u32Adress_Bus){
        case RCC_APB1:
        RCC->APB1ENR &=~(1<<Copy_u32peripheral);
        break;
        case RCC_APB2:
        RCC->APB2ENR &=~(1<<Copy_u32peripheral);
        break;
        case RCC_AHB1:
        RCC->AHB1ENR &=~(1<<Copy_u32peripheral);
        break;
        case RCC_AHB2:
        RCC->AHB2ENR &=~(1<<Copy_u32peripheral);
        break;
        default:
        break;
    }
}
