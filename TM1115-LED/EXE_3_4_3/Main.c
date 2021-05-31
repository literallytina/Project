#include<p18f4520.h>

void main(void)
{
	int count = 0;
	int DoSomething = 0;
	
	TRISA = 0x10;
	TRISB = 0xF0;
	
	while(1)
	{
		if(PORTAbits.RA4 == 0)
		{
			PORTBbits.RB1 = 1;
			for(count = 0; count<10000; count++)
			{
				DoSomething = 999;
			}
			
			PORTBbits.RB1 = 0;
			for(count = 0; count<10000; count++)
			{
				DoSomething = 999;
			}
		}
		else if(PORTAbits.RA4 == 1)
		{
			PORTBbits.RB1 = 0;
		}
	}
}