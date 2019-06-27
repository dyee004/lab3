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
unsigned char GetBit(unsigned char x, unsigned char y) {
	return ((x & (0x01 << y)) != 0);
}

int main(void) {
  	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	unsigned char tmpA = PINA;
	unsigned char tmpB = PINB;
	unsigned char incrementor = 0;
    while (1) 
    {
	incrementor = 0;
	for (unsigned char i = 0; i < 8; i ++ ){
		if(GetBit(tmpA,i)){
			incrementor = incrementor + 1;
		}
	}
	for (unsigned char j = 0; j < 8; j ++ ){
		if(GetBit(tmpB,j)){
			incrementor = incrementor + 1;
		}
	}
	PORTC = incrementor;
    }
	return 1;
}
