#include <P18F4520.INC>

ORG		0X0000
goto	Main

Main:
	movlw	0x00
	movwf	TRISB
	
Loop:
	movlw	0x01
	movwf	PORTB
	movlw	0x00
	movwf	PORTB
	goto	Loop
	
END