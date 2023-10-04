#include "../include/STD_Types.h"
#include "../include/BIT_MATH.h"
#include "../include/MGPIO_prv.h"
#include "../include/MGPIO_cfg.h"
#include "../include/MGPIO_int.h"

void MGPIO_SetMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode)
{
	if(Copy_u8Port==PORTA && (Copy_u8Pin==PIN13 || Copy_u8Pin==14 || Copy_u8Pin==15))
	{
		/* Do Nothing */
	}
	else if(Copy_u8Port==PORTB && (Copy_u8Pin==PIN3 || Copy_u8Pin==4 || Copy_u8Pin==5))
	{
		/* Do Nothing */
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOA->MODER |= Copy_u8Mode<<(Copy_u8Pin*2);
			break;
		case PORTB:
			GPIOB->MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOB->MODER |= Copy_u8Mode<<(Copy_u8Pin*2);
			break;
		case PORTC:
			GPIOC->MODER &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOC->MODER |= Copy_u8Mode<<(Copy_u8Pin*2);
			break;
		default: break;
		}
	}
}

void MGPIO_SetOutputPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8OutMode,u8 Copy_u8Speed)
{
	if(Copy_u8Port==PORTA && (Copy_u8Pin==PIN13 || Copy_u8Pin==14 || Copy_u8Pin==15))
	{
		/* Do Nothing */
	}
	else if(Copy_u8Port==PORTB && (Copy_u8Pin==PIN3 || Copy_u8Pin==4 || Copy_u8Pin==5))
	{
		/* Do Nothing */
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->OTYPER &= ~(1<<(Copy_u8Pin));
			GPIOA->OTYPER |= Copy_u8OutMode<<(Copy_u8Pin);
			GPIOA->OSPEEDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOA->OSPEEDR |= Copy_u8Speed<<(Copy_u8Pin*2);
			break;
		case PORTB:
			GPIOB->OTYPER &= ~(1<<(Copy_u8Pin));
			GPIOB->OTYPER |= Copy_u8OutMode<<(Copy_u8Pin);
			GPIOB->OSPEEDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOB->OSPEEDR |= Copy_u8Speed<<(Copy_u8Pin*2);
			break;
		case PORTC:
			GPIOC->OTYPER &= ~(1<<(Copy_u8Pin));
			GPIOC->OTYPER |= Copy_u8OutMode<<(Copy_u8Pin);
			GPIOC->OSPEEDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOC->OSPEEDR |= Copy_u8Speed<<(Copy_u8Pin*2);
			break;
		default: break;
		}
	}
}

void MGPIO_SetInputPin(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8InputMode)
{
	if(Copy_u8Port==PORTA && (Copy_u8Pin==PIN13 || Copy_u8Pin==14 || Copy_u8Pin==15))
	{
		/* Do Nothing */
	}
	else if(Copy_u8Port==PORTB && (Copy_u8Pin==PIN3 || Copy_u8Pin==4 || Copy_u8Pin==5))
	{
		/* Do Nothing */
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			GPIOA->PUPDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOA->PUPDR |= Copy_u8InputMode<<(Copy_u8Pin*2);
			break;
		case PORTB:
			GPIOB->PUPDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOB->PUPDR |= Copy_u8InputMode<<(Copy_u8Pin*2);
			break;
		case PORTC:
			GPIOC->PUPDR &= ~(GPIO_MODE_MASK<<(Copy_u8Pin*2));
			GPIOC->PUPDR |= Copy_u8InputMode<<(Copy_u8Pin*2);
			break;
		default: break;
		}
	}
}

void MGPIO_GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 * Copy_pu8Data)
{
	switch(Copy_u8Port)
	{
	case PORTA:
		*Copy_pu8Data=GET_BIT(GPIOA->IDR,Copy_u8Pin) ;
		break;
	case PORTB:
		*Copy_pu8Data=GET_BIT(GPIOB->IDR,Copy_u8Pin) ;
		break;
	case PORTC:
		*Copy_pu8Data=GET_BIT(GPIOC->IDR,Copy_u8Pin) ;
		break;
	default: break;
	}
}

void MGPIO_SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8  Copy_u8Data)
{
	if(Copy_u8Port==PORTA && (Copy_u8Pin==PIN13 || Copy_u8Pin==14 || Copy_u8Pin==15))
	{
		/* Do Nothing */
	}
	else if(Copy_u8Port==PORTB && (Copy_u8Pin==PIN3 || Copy_u8Pin==4 || Copy_u8Pin==5))
	{
		/* Do Nothing */
	}
	else
	{
		switch(Copy_u8Port)
		{
		case PORTA:
			if (Copy_u8Data==STD_HIGH)
			{
				GPIOA->ODR |= 1<<(Copy_u8Pin);
			}
			else if (Copy_u8Data==STD_LOW)
			{
				GPIOA->ODR &= ~(1<<(Copy_u8Pin));
			}
			break;
		case PORTB:
			if (Copy_u8Data==STD_HIGH)
			{
				GPIOB->ODR |= 1<<(Copy_u8Pin);
			}
			else if (Copy_u8Data==STD_LOW)
			{
				GPIOB->ODR &= ~(1<<(Copy_u8Pin));
			}
			break;
		case PORTC:
			if (Copy_u8Data==STD_HIGH)
			{
				GPIOC->ODR |= 1<<(Copy_u8Pin);
			}
			else if (Copy_u8Data==STD_LOW)
			{
				GPIOC->ODR &= ~(1<<(Copy_u8Pin));
			}
			break;
		default: break;
		}
	}
}
void MGPIO_SetResetvalue(u8 Copy_u8Port,u8 Copy_u8Pin,u8  Copy_u8SetOrReset){
	if(Copy_u8Port==PORTA && (Copy_u8Pin==PIN13 || Copy_u8Pin==14 || Copy_u8Pin==15))
	{
		/* Do Nothing */
	}
	else if(Copy_u8Port==PORTB && (Copy_u8Pin==PIN3 || Copy_u8Pin==4 || Copy_u8Pin==5))
	{
		/* Do Nothing */
	}
	else
	{
		if(Copy_u8SetOrReset==OUTPUT_RESET){
			switch(Copy_u8Port)
			{
			case PORTA:
				GPIOA->BSRR &= ~(1<<(Copy_u8Pin+16));
				GPIOA->BSRR |= 1<<(Copy_u8Pin+16);
				break;
			case PORTB:
				GPIOB->BSRR &= ~(1<<(Copy_u8Pin+16));
				GPIOB->BSRR |= 1<<(Copy_u8Pin+16);
				break;
			case PORTC:
				GPIOC->BSRR &= ~(1<<(Copy_u8Pin+16));
				GPIOC->BSRR |= 1<<(Copy_u8Pin+16);
				break;
			default: break;
			}

		}
		else if(Copy_u8SetOrReset==OUTPUT_SET){
			switch(Copy_u8Port)
			{
			case PORTA:
				GPIOA->BSRR &= ~(1<<(Copy_u8Pin));
				GPIOA->BSRR |= 1<<(Copy_u8Pin);
				break;
			case PORTB:
				GPIOB->BSRR &= ~(1<<(Copy_u8Pin));
				GPIOB->BSRR |= 1<<(Copy_u8Pin);
				break;
			case PORTC:
				GPIOC->BSRR &= ~(1<<(Copy_u8Pin));
				GPIOC->BSRR |= 1<<(Copy_u8Pin);
				break;
			default: break;
			}
		}
		else
		{
			/*do nothing*/
		}

	}
}



