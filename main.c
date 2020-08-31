#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
#include "lcd.h"
//Test
uint8_t MIN(uint8_t SEK, uint8_t BIT);
uint8_t HOUR(uint8_t SEK, uint8_t BIT);

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
	uint8_t bit;
	bit = 0;
	triger = 0;
	timecountl = 0;
	timecounth = 0;
	repcount = 0;
	apegel = 0;
	pegel = 0;
	
	//zeit variablen
	uint8_t sek;
	uint8_t minute;
	uint8_t hour;
	uint16_t year;
	sek = 0;
	minute = 0;
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
		}
			                     //output daten bei negativer flanke
		if(pegel < apegel){
			
			apegel = 0;
			if(timecounth < 23000){
					bit = 0;
					timecounth = 0;
					}
					else{
					bit = 1;
					timecounth = 0;
					}
					
				
			/*lcd_clrscr();
			lcd_count(timecounth);
			timecounth = 0;*/
			
			if(triger == 1){
				if(sek == 59){
					sek = 0;
					}
					
				sek++;
					
					
					//Sekunden
					lcd_clrscr();
					lcd_count(sek);
					lcd_puts("Sek ");
					
					
					//minuten
					if(sek == 22){
						minute = 0;
					}
						minute = minute + MIN(sek, bit);
						lcd_count(minute);
						lcd_puts("Min\n");
						
					//Stunde
					if(sek == 30){
						hour = 0;
					}
					hour = hour + HOUR(sek, bit);
					lcd_count(hour);
					lcd_puts("H");	
			
				
			
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
		
		
		
		
		//end while
		}
	
}

	
//time min
uint8_t MIN(uint8_t SEK, uint8_t BIT){
	uint8_t VAL;
	VAL = 0;
	if(BIT == 1){
	switch(SEK){
		case 22: VAL = 1; break;
		case 23: VAL = 2; break;
		case 24: VAL = 4; break;
		case 25: VAL = 8; break;
		case 26: VAL = 10; break;
		case 27: VAL = 20; break;
		case 28: VAL = 40; break;
	}}

		return(VAL);
}

//time hour
uint8_t HOUR(uint8_t SEK, uint8_t BIT){
	uint8_t VAL;
	VAL = 0;
	if(BIT == 1){
	switch(SEK){
		case 30: VAL = 1; break;
		case 31: VAL = 2; break;
		case 32: VAL = 4; break;
		case 33: VAL = 8; break;
		case 34: VAL = 10; break;
		case 35: VAL = 20; break;
	}}

		return(VAL);
}	
			
			
	

