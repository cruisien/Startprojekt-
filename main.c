#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// Test//

//MODE
void LCE(uint8_t nr){
 PORTC |= (nr<<0);
}

//Execute
void LCP (void){
	PORTC |= (1<<1);
	PORTC |= (0<<1);
}

//cursor
void LCC (Void) {
	PORTC |= (1<<0);
	PORTD = 00001111;
	PORTC |= (1<<1);
	_delay_ms(100);
	PORTC |= (0<<1);
}
	
	


int main(void)
{ DDRD = 0xFF;
DDRC |= (1<<PC0)| (1<<PC1);
LCC;


}
		
		

	
	
		

//end of main




