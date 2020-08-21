#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// Test//

void LED(uint8_t nr, uint8_t status){
PORTD |= (status<<nr);
}


uint8_t state; TASTE(uint8_t nr){
	
	switch(nr){
		case 0: state = PINC |= (1<<nr);
		
		}
	
}

int main(void)
{ DDRD = 0xFF;
DDRC &= (1<<PC0)| (1<<PC1)| (1<<PC2);

while(1){
TASTE(0);
LED(state, 0);
}
		
		

	
	
		

}//end of main




