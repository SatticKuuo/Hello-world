#include "stm8s.h"
#include <stdio.h>

void init_sys(void);

int temp;
static unsigned char ch = 0;

void __delay_us(int us)
{
	int i;
	
	for(i = 0; i < us; i++)
	{
/*		nop();
		nop();
		nop();
		nop();
		nop();
		nop();
		nop();
		nop();
		nop();
		nop();
		nop();
		nop();
*/	}
}

void __delay_ms(int ms)
{
	int i;
	
	for(i = 0; i < ms; i++)
	{
		__delay_us(990);
	}
}

int main(void)
{
	init_sys();
	
	for(;;)
	{
//		GPIOC->ODR ^= 0x08;
//		TIM1->CCR2H += 0x10;
		__delay_ms(1000);
	}
}

#pragma vector = 13
__interrupt void TIM1_Update_IRQHandler(void)
{
	TIM1->SR1 = 0;

	ch++;
	TIM1->CCR1H = ch;
	TIM1->CCR1L = 0x00;
	TIM1->CCR4H = 255 - ch;
	TIM1->CCR4L = 0x00;
//	TIM1->CCR1H += 0x10;
//	GPIOC->ODR ^= 0x1e;
}

#pragma vector = 24
__interrupt void ADC_IRQHandler(void)
{
	ADC1->CSR &= 0x7f;


}
