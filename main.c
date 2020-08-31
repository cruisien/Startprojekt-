#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <string.h>
#include "lcd.h"
//zeit definierung
uint8_t MIN(uint8_t SEK, uint8_t BIT);
uint8_t HOUR(uint8_t SEK, uint8_t BIT);
uint8_t DAY (uint8_t SEK, uint8_t BIT);
uint8_t MONTH(uint8_t SEK, uint8_t BIT);
uint8_t YEAR(uint8_t SEK, uint8_t BIT);
uint8_t WDAY(uint8_t SEK, uint8_t BIT);
void WDAYLCD(uint8_t DAY);

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
	
	//zeit variablenbuffer
	uint8_t sek;
	uint8_t bufminute;
	uint8_t bufhour;
	uint8_t bufday;
	uint8_t bufmonth;
	uint8_t bufyear;
	uint8_t bufwekday;
	bufwekday = 0;
	bufyear = 0;
	bufmonth = 0;
	sek = 0;
	bufminute = 0;
	bufhour = 0;
	bufday = 0;
	
	//zeit var rel
	uint8_t min;
	uint8_t hour;
	uint8_t day;
	uint8_t month;
	uint8_t year;
	uint8_t wekday;
	min = 0;
	hour = 0;
	day = 0;
	month = 0;
	year = 0;
	wekday = 0;
	
	
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
					
					
					

					
					
					//minuten
					
						bufminute = bufminute + MIN(sek, bit);
					if(sek == 1){
						min = bufminute;
						bufminute = 0;
					}	
						
					//Stunde
					
					bufhour = bufhour + HOUR(sek, bit);
					if(sek == 1){
						hour = bufhour;
						bufhour = 0;
					}

					
					//monthday
					
					bufday = bufday + DAY(sek, bit);
					if(sek == 1){
						day = bufday;
						bufday = 0;
					}

			
					//month
					
					bufmonth = bufmonth + MONTH(sek, bit);
					if(sek == 1){
						month = bufmonth;
						bufmonth = 0;
					}

					
					//year
					
					bufyear = bufyear + YEAR(sek, bit);
					if(sek == 1){
						year = bufyear;
						bufyear = 0;
					}
					
					//weekday
					
					bufwekday = bufwekday + WDAY(sek, bit);
					if(sek == 1){
						wekday = bufwekday;
						bufwekday = 0;
					}
					

			
		
		}//end 59triger
		if(sek == 59){
			triger = 0;
		}
		
		//Ausgabe LCD-------------------------------------------------------------------------------------
		lcd_clrscr();
		lcd_puts(" ");
		lcd_count(hour);
		lcd_puts(":");
		lcd_count(min);
		lcd_puts(":");
		lcd_count(sek);
		lcd_puts("\n ");
		WDAYLCD(wekday);
		lcd_puts(" ");
		lcd_count(day);
		lcd_puts(".");
		lcd_count(month);
		lcd_puts(".20");
		lcd_count(year);
	
		
		
		
		
		}//end negflank datasetin/timeset/count
		
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
		
		
		
		
		
		
	
}//end while
}//end main
	
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
			
//date day	
uint8_t DAY(uint8_t SEK, uint8_t BIT){
	uint8_t VAL;
	VAL = 0;
	if(BIT == 1){
	switch(SEK){
		case 37: VAL = 1; break;
		case 38: VAL = 2; break;
		case 39: VAL = 4; break;
		case 40: VAL = 8; break;
		case 41: VAL = 10; break;
		case 42: VAL = 20; break;
	}}

		return(VAL);
}	

// date month
uint8_t MONTH(uint8_t SEK, uint8_t BIT){
	uint8_t VAL;
	VAL = 0;
	if(BIT == 1){
	switch(SEK){
		case 46: VAL = 1; break;
		case 47: VAL = 2; break;
		case 48: VAL = 4; break;
		case 49: VAL = 8; break;
		case 50: VAL = 10; break;
	}}

		return(VAL);
}	

//date year
uint8_t YEAR(uint8_t SEK, uint8_t BIT){
	uint8_t VAL;
	VAL = 0;
	if(BIT == 1){
	switch(SEK){
		case 51: VAL = 1; break;
		case 52: VAL = 2; break;
		case 53: VAL = 4; break;
		case 54: VAL = 8; break;
		case 55: VAL = 10; break;
		case 56: VAL = 20; break;
		case 57: VAL = 40; break;
		case 58: VAL = 80; break;
	}}

		return(VAL);
}

//weekday
uint8_t WDAY(uint8_t SEK, uint8_t BIT){
	uint8_t VAL;
	VAL = 0;
	if(BIT == 1){
	switch(SEK){
		case 43: VAL = 1; break;
		case 44: VAL = 2; break;
		case 45: VAL = 4; break;
	}}

		return(VAL);
	}

//weekdaylcd
void WDAYLCD(uint8_t DAY){
	switch(DAY){
	case 1: lcd_puts("Mo"); break;
	case 2: lcd_puts("Di"); break;
	case 3: lcd_puts("Mi"); break;
	case 4: lcd_puts("Do"); break;
	case 5: lcd_puts("Fr"); break;
	case 6: lcd_puts("Sa"); break;
	case 7: lcd_puts("So"); break;
}

}

