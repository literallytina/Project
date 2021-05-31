#include <p18f4520.h>

int count =0;
int DoSomething = 0;
int ADC_Result = 0;

#pragma interrupt high_isr
void high_isr(void)
{
	if(PIR1bits.TMR1IF)
	{
		PIR1bits.TMR1IF = 0;
		PORTBbits.RB2 = !PORTBbits.RB2;
		TMR1H = 0xF0;
		TMR1L = 0x00;
	}
}
#pragma interrupt low_isr
void low_isr(void)
{
}
#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
	_asm goto high_isr _endasm
}
#pragma code low_vector=0x18
void interrupt_at_low_vector(void)
{
	_asm goto low_isr _endasm
}
#pragma code
void main(void)
{
	TRISA = 0x10;
	TRISB = 0xF0;
	
	PORTBbits.RB0 = 0;
	PORTBbits.RB1 = 0;
	PORTBbits.RB2 = 0;
	PORTBbits.RB3 = 0;
		
	ADCON0 = 0x01;
	ADCON1 = 0x0E;
	ADCON2 = 0x29;

	while(1)
	{
		PORTBbits.RB0 = 1;
		for(count=0; count<10000; count++)
		{
			DoSomething = 999;
		}
		PORTBbits.RB0 = 0;
		for (count=0;count<10000;count++)
		{
			DoSomething = 999;
		}
		
		if(PORTAbits.RA4 == 0)
		{
			PORTBbits.RB1 = 1;
		}
		else if(PORTAbits.RA4 == 1)
		{
			PORTBbits.RB1 = 0;
		}
		
		ADCON0bits.GO = 1;
		while(ADCON0bits.GO);
		ADC_Result = ADRESH;
		if(ADC_Result<100)
		{
			PORTBbits.RB3 = 0;
		}
		else if(100<=ADC_Result)
		{
			PORTBbits.RB3 = 1;
		}
	}
	
	INTCONbits.PEIE = 1;
	INTCONbits.GIE = 1;
	PIE1bits.TMR1IE = 1;
	PIR1bits.TMR1IF = 0;
	T1CON = 0x0B;
	TMR1H = 0xF0;
	TMR1L = 0x00;
	while(1)
	{
		DoSomething = 999;
	}
}