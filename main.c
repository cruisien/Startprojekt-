#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// Test//

int main(void)
{ DDRD = 0xFF;
uint8_t test;
uint8_t zaler1;
test = 1;
zaler1 = 0;
do{
	PORTD = test;
	test = test * 2;
	zaler1++;
	_delay_ms(1000);
}while (zaler1 < 8);
	
test = 1;
zaler1 = 1;
test = test * test + 1;
_delay_ms(1000);

do{
	zaler1++;
	test = test * 2;
	
	
	







	
	
	
	
		

}//end of main




