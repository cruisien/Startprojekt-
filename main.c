#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

// Test//



//Execute
void LCP(void);


//reset
void LCR(void);


//initialising
void LCC(void);

//Cursor home
void LCH(void);


int main(void)
{ DDRD = 255;
DDRC = 3;
PORTD = 0xFF;
PORTC = 0x3;
PORTC = 0;
LCC();
LCR();
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
	LCH();


return 0;
}





void LCP(void){
	_delay_ms(2);
	PORTC &= ~(1<<PD1);
	_delay_ms(2);
	PORTC |= (1<<PD1);
}

void LCR(void){
	PORTC &= ~(1<<0);
	PORTD = 0b00000001;
	LCP();
	LCC();
}

void LCH(void){
	PORTC &= ~(1<<0);
	PORTD = 0b00000010;
	LCP();
}

void LCC(void){
	PORTC |= (1<<PD1);
	PORTC &= ~(1<<PD0);
	PORTD = 0b00001111;
	LCP();
}
		
void LCA(void){
	
	
}
	
		

//end of main




