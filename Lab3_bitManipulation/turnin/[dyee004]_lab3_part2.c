/*	Author: dyee004
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
  	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmpA = 0;
	unsigned char tmpB = 0;
	unsigned char incrementor = 0;
	unsigned char i = 0;
   
    while (1) 
    {
      tmpA = PINA;
      tmpB = PINB;
      incrementor = 0;
      for(i = 0; i < 8; i++){
        if((tmpA&0x01) == 0x01){
	  incrementor = incrementor + 1;
	}
        if((tmpB&0x01) == 0x01){
	  incrementor = incrementor + 1;
	}
	tmpA = (tmpA >> 1);
	tmpB = (tmpB >> 1);
      }
      PORTC = incrementor;
    }
	return 1;
}
