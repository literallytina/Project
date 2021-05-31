#include <P18F4520.INC>

cblock 0x00
	Counter_01
	Counter_02
endc

ORG	0x0000 
goto	Main 

Main: 
	movlw	0xF0 
	movwf	TRISB 
 	movlw	0x10
 	movwf	TRISA

Loop: 
	btfss	PORTA, 4
	call	Blink  
	bcf	PORTB, 1 
	goto	Loop 
	
Blink
	bsf	PORTB, 1
	
	movlw	0xFF
	movwf	Counter_01
	movlw	0xFF
	movwf	Counter_02
	call	Delay
	
	bcf	PORTB, 1
	
	movlw	0xFF
	movwf	Counter_01
	movlw	0xFF
	movwf	Counter_02
	call	Delay
	
	return
	
Delay	
	decfsz	Counter_01
	goto	Delay
	decfsz	Counter_02
	goto	Delay
	return	
END
