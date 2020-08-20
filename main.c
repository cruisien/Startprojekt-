#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// Test//

int main(void)
{ DDRD = 0xFF;
uint8_t test;
test = 1;
while (1){
do{
	test++;
	PORTD = test;
	_delay_ms(200);
}while (test < 255);

do{
	test--;
	PORTD = test;
	_delay_ms(200);
}while ( test > 1);	




}

	
	
	
	
		

}//end of main




