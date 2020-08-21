#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// Test//

int main(void)
{ DDRD = 0xFF;
PORTD = 0x00;
uint8_t count;
count = 9;

do{
	if ((count == 1) || (count == 9) || (count == 10) || (count == 17) || (count == 18) || (count == 19) || (count == 25) || (count == 28) ||(count == 26) || (count == 27) || (count == 33) || (count == 34) || (count == 35) || (count == 36) || (count == 37) || (count == 41) || (count == 42) || (count == 43) || (count == 44) || (count == 45) || (count == 46) || (count == 49) || (count == 50) || (count == 51) || (count == 52) || (count == 53) || (count == 54) || (count == 55) || (count > 56)) {
		PORTD |= (1<<PD0); }
		else { 
			PORTD &= (1<<PD0); }
	
	if ((count == 2) || (count == 10) || (count == 11) || (count == 18) || (count == 19) || (count == 20) || (count == 26) || (count == 27) || (count == 28) || (count == 29		







	
	
	
	
		

}//end of main




