/*	Author: dyee004
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab # 4 Exercise # 4
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
    /* Insert DDR and PORT initializations */

    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char upperA = 0;
    unsigned char lowerA = 0;
    unsigned char tmpB = 0;
    unsigned char tmpC = 0;
    /* Insert your solution below */
    while (1) {
        upperA = PINA & 0xF0;
        lowerA = PINA & 0x0F;
        tmpB = (upperA >> 4) & 0x0F;
        tmpC = (lowerA << 4) & 0xF0;
        PORTB = tmpB;
        PORTC = tmpC;
    }
    return 1;
}
