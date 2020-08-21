#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// Test//

int main(void)
{ DDRD = 0xFF;
DDRC &= (1<<PC0)| (1<<PC1)| (1<<PC2);
uint8_t direction;
uint8_t speed;
uint8_t light;
uint8_t pin0;
uint8_t upin0;
uint8_t pin1;
uint8_t upin1;
uint8_t pin2;
uint8_t upin2;
uint8_t wile;
wile = 1;
upin0 = 0;
pin0 = 0;
upin1 = 0;
pin1 = 0;
upin2 = 0;
pin2 = 0;
direction = 0;
speed = 4;
light = 1;
while(wile == 1) {
	
	//speed
	
	_delay_ms(100 * speed);
	
	//lauflicht
	
	
	
	if(direction == 0){
		if(light == 0){
			light = 1;
		}
		PORTD = light;
		if(light == 128){
		light = 0;
		} 
		if(light != 0){
		light = light * 2;
	}
		
	
		
	}
	
	if(direction == 1){
		if(light == 200){
			light = 128;
		}
		PORTD = light;
		if(light == 1){
			light = 200;
		}
		if(light < 199){
		light = light / 2;
		}	
		
			//richtungsänderung
	}
	
	if(PINC |= (1<<PC1)){
	pin1 = 1;
	}
	if(PINC & (1<<PC1)){
		pin1 = 0;
	}
	if(pin1 > upin1){
		upin1 = 1;
		if(direction == 0){
			direction = 1;
		}
		else{
			direction = 0;
		}
	}
	if(pin1 < upin1){
		upin1 = 0;
	}
	
	//speed minus
	
	if(PINC |= (1<<PC0)){
		pin0 = 1;
	}
	if(PINC & (1<<PC0)){
		pin0 = 0;
	}
	
	if(pin0 > upin0){
		upin0 = 1;
		if(speed == 0){
			speed = 10;
		}
		speed = speed - 1;
	}
	
	if(pin0 < upin0){
		upin0 = 0;
	}
		
	//speed plus
	
	if(PINC |= (1<<PC2)){
		pin2 = 1;
	}
	
	if(PINC & (1<<PC2)){
		pin2 = 0;
	}
	
	if(pin2 > upin2){
		upin2 = 1;
		if(speed == 10){
			speed = 0;
		}
		speed = speed + 1;
	}
	
	if(pin2 < upin2){
		upin2 = 0;
	}
		
		
}//end of while	
	
	
		

}//end of main




