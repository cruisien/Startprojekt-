#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// Test//

int main(void)
{ DDRD = 0xFF;
DDRC &= (1<<PC0)| (1<<PC1)| (1<<PC2)| (1<<PC3);
uint8_t an;
an = 1;
while(an = 1) {
	
	
	if(PINC & (1<<PC0)) {
		PORTD |= (1<<PD0);
	}
	else {
		PORTD &= (1<<PD0);
	}


	if(PINC & (1<<PC1)) {
		PORTD |= (1<<PD1);
	}
	else {
		PORTD &= (1<<PD1);
	}

	if(PINC & (1<<PC2)) {
		PORTD |= (1<<PD2);
	}
	else {
		PORTD &= (1<<PD2);
	}
	
	if(PINC & (1<<PC3)) {
		PORTD |= (1<<PD3);
	}
	else {
		PORTD &= (1<<PD3);
	}
	
}//end of while	
	
	
		

}//end of main




