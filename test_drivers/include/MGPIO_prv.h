#ifndef MGPIO_PRV_H
#define MGPIO_PRV_H

#define GPIOA_BASE_ADRESS   (0x40020000)
#define GPIOB_BASE_ADRESS   (0x40020400)
#define GPIOC_BASE_ADRESS   (0x40020800)

typedef struct
{
	u32  MODER ;
	u32  OTYPER ;
	u32  OSPEEDR;
	u32  PUPDR;
	u32  IDR;
	u32  ODR;
	u32  BSRR;
	u32  LCKR;
	u32  AFRL;
	u32  AFRH;
}GPIOX_t;

#define  GPIO_MODE_MASK     3  

#define GPIOA       ((volatile GPIOX_t*)GPIOA_BASE_ADRESS)
#define GPIOB       ((volatile GPIOX_t*)GPIOB_BASE_ADRESS)
#define GPIOC       ((volatile GPIOX_t*)GPIOC_BASE_ADRESS)



#endif
