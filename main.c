#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
#include "lcd.h"
//Test
uint8_t FLANKE(void);


int main(void)
{
	
	DDRD = 0b0011111;
	PORTD = 0b0001111;
	
	DDRC = 0xFF;
	PORTC = 0x00;
	uint8_t pegel;
	uint8_t apegel;
	uint16_t timecounth;
	uint8_t timecountl;
	timecountl = 0;
	timecounth = 0;
	apegel = 0;
	pegel = 0;
	
	lcd_init(LCD_DISP_ON);  // initialisieren

    lcd_clrscr();
    

    while(1){
		
		
		
		if(PIND & (1<<PD5)){
			pegel = 1;
		}
		else{
			pegel = 0;
		}
		
	
		if(pegel > apegel){
			apegel = 1;
			/*if(timecountl > 200){
			lcd_puts("H");
		}*/
		}
		
		                     //output daten bei negativer flanke
		if(pegel < apegel){
			apegel = 0;
			/*lcd_clrscr();
			lcd_count(timecounth);
			timecounth = 0;*/
			if(timecounth < 23000){
			lcd_puts("0");
			timecounth = 0;
			}
		else{
			lcd_puts("1");
			timecounth = 0;
		}
		}
		
		
		
		
		
		if(apegel == 1){
			timecounth++;
		}						//counter
		/*if(apegel == 0){
			timecountl++;
		}*/
		
		if(timecounth == 65500){
			lcd_puts("overflow");
		}
		
		
		
		
		
		//end while
		}
	
}
	
	
			
			
			
	
	//end of main




