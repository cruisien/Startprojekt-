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
	
	//funktions variablen
	uint8_t pegel;
	uint8_t apegel;
	uint16_t timecounth;
	uint16_t timecountl;
	uint16_t repcount;
	uint8_t triger;
	uint8_t bin;
	bin = 0;
	triger = 0;
	timecountl = 0;
	timecounth = 0;
	repcount = 0;
	apegel = 0;
	pegel = 0;
	
	//zeit variablen
	uint8_t sek;
	uint8_t min;
	uint8_t hour;
	uint16_t year;
	sek = 0;
	min = 0;
	hour = 0;
	year = 0;
	
	
	
	lcd_init(LCD_DISP_ON);  // initialisieren

    lcd_clrscr();
    

    while(1){
		
		
		
		if(PIND & (1<<PD5)){
			pegel = 1;
			
			if(pegel > apegel){
			apegel = 1;
			/*lcd_clrscr();
			lcd_count(timecountl);*/
			timecountl = 0;
		}
		}
		
		
		
		
		else{
			pegel = 0;
			
			                     //output daten bei negativer flanke
		if(pegel < apegel){
			apegel = 0;
			/*lcd_clrscr();
			lcd_count(timecounth);
			timecounth = 0;*/
			
			if(triger == 1){
				sek++;
				if(timecounth < 23000){
				bin = 0;
				timecounth = 0;
				}
				else{
				bin = 1;
				timecounth = 0;
				}
				
			}
		}
		}
		
	
		
		
		
		
		
		
		if(apegel == 1){
			timecounth++;
		}						//counter
		else{
			repcount++;
			if(repcount == 8){
			timecountl++;
			repcount = 0;
			if(timecountl > 20000){
				triger = 1;
			}
		}
		}
		
		if(timecountl == 65500){
			lcd_puts("over");
		}
		
		
		
		//end while
		}
	
}
	
	
			
			
			
	
	//end of main
