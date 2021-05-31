#include<p18f4520.h>

void main(void)
{
	int count = 0;
	int DoSomething = 0;
	
	TRISB = 0xF0;
	
	while(1)
	{
		PORTBbits.RB3 = 1;
		for(count=0; count<10000; count++)
		{
			DoSomething = 999;
		}
		PORTBbits.RB3 = 0;
		
		PORTBbits.RB2 = 1;
		for(count = 0; count<10000; count++)
		{
			DoSomething = 999;
		}
		PORTBbits.RB2 = 0;
		
		PORTBbits.RB1 = 1;
		for(count = 0; count<10000; count++)
		{
			DoSomething = 999;
		}
		PORTBbits.RB1 = 0;
		
		PORTBbits.RB0 = 1;
		for(count = 0; count<10000; count++)
		{
			DoSomething = 999;
		}
		PORTBbits.RB0 = 0;
		for(count = 0; count<10000; count++)
		{
			DoSomething = 999;
		}

	}
}
		
	

