#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// Test



//Execute
void LCP(void);

//reset
void LCR(void);

//initialising
void LCC(void);

//Cursor home
void LCH(void);

//Simon
void LCSIMON(void);

//output port D
void OUTD(uint8_t BIN);


int main(void){
//ports enable/set high
DDRD = 255;
DDRC = 3;
PORTD = 0xFF;
PORTC = 0x3;
//


PORTC = 0;
LCC();
LCR();

PORTD = 0b01000000;
LCP();
PORTD = 0b00001110;
LCP();
PORTD = 0b00010001;
LCP();
PORTD = 0b00001110;
LCP();
PORTD = 0b00000100;
LCP();
PORTD = 0b00011111;
LCP();
PORTD = 0b00000100;
LCP();
PORTD = 0b00001010;
LCP();
PORTD = 0b00010001;
LCP();
	
	
	

return 0;
}




//execute LCD input
void LCP(void){
	PORTC |= (1<<PD1);
	_delay_ms(2);
	PORTC &= ~(1<<PD1);
	_delay_ms(2);
	PORTC |= (1<<PD1);
}

//clear LCD and reset cursor
void LCR(void){
	PORTC &= ~(1<<0);
	PORTD = 0b00000001;
	LCP();
	LCC();
}

//reset cursor
void LCH(void){
	PORTC &= ~(1<<0);
	PORTD = 0b00000010;
	LCP();
}

//initialising LCD
void LCC(void){
	PORTC |= (1<<PD1);
	PORTC &= ~(1<<PD0);
	PORTD = 0b00001111;
	LCP();
}

//Simon		
void LCSIMON(void){
	PORTC = 0b11;
	PORTD = 0b01010011;
	LCP();
	PORTD = 0b01101001;
	LCP();
	PORTD = 0b01101101;
	LCP();
	PORTD = 0b01101111;
	LCP();
	PORTD = 0b01101110;
	LCP();
	
}

//output port D
void OUTD(uint8_t BIN){
	PORTD = BIN;
	LCP();
}
	
		

//end of main




