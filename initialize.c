#include "stm8s.h"

static void init_clk(void)
{
//	CFG->GCR = 0x02;
	CLK->CKDIVR = 0x00;		//CPU 16MHz
	CLK->PCKENR1 = 0xB0;	//TIM1 TIM2 TIM4 enable
	CLK->PCKENR2 = 0x08;
}

static void init_io(void)
{
/*	GPIOB->ODR = 0x00;
	GPIOB->DDR = 0x00;
	GPIOB->CR1 = 0x00;
	GPIOB->CR2 = 0x00;

	GPIOB->ODR = 0xff;
	GPIOB->DDR = 0xff;
	GPIOB->CR1 = 0x00;
	GPIOB->CR2 = 0xff;
*/
	GPIOB->DDR = 0x00;
	GPIOB->CR1 = 0x00;
	GPIOB->CR2 = 0x00;

	GPIOC->ODR = 0x00;
	GPIOC->DDR = 0x1e;
	GPIOC->CR1 = 0x1e;
	GPIOC->CR2 = 0x1e;
}

static void init_tmr(void)
{
	TIM1->ARRH = 0xff;
	TIM1->ARRL = 0xff;
	TIM1->PSCRH = 0x00;
	TIM1->PSCRL = 0x04;
	TIM1->CCR1H = 0x00;
	TIM1->CCR1L = 0x02;
	TIM1->CCR2H = 0x40;
	TIM1->CCR2L = 0x00;
	TIM1->CCR3H = 0x80;
	TIM1->CCR3L = 0x00;
	TIM1->CCR4H = 0xC0;
	TIM1->CCR4L = 0x00;
	TIM1->CCMR1 = 0x68;
	TIM1->CCMR2 = 0x68;
	TIM1->CCMR3 = 0x68;
	TIM1->CCMR4 = 0x68;
	TIM1->CCER1 = 0x33;
	TIM1->CCER2 = 0x33;
	TIM1->OISR = 0x55;
	TIM1->BKR = 0x80;
	TIM1->EGR = 0x01;
	TIM1->SR1 = 0x00;
	TIM1->IER = 0x01;
	TIM1->CR1 = 0x05;
}

static void init_adc(void)
{
	ADC1->CR2 = 0x48;
	ADC1->CSR = 0x20;
	ADC1->CR1 = 0x41;
}

void init_sys(void)
{
	init_clk();
	init_io();
	init_adc();
	init_tmr();

	__enable_interrupt();
}
