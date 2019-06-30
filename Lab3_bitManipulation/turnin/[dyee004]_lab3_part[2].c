/*	Author: dyee004
 *  Partner(s) Name: Azat Melkonyan
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #1
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
  DDRC = 0xFF; PORTC = 0x00;
  unsigned char sensor =0;
  unsigned char level = 0; 
    /* Insert your solution below */
    while (1) {
      sensor = PINA & 0x0F;
      if(sensor == 0){
	level = 0x40;
      }
      else if((sensor == 1) || (sensor == 2)) {
	level = 0x60;
      }
      else if((sensor == 3) || (sensor == 4)){
	level = 0x70;
      }
      else if((sensor == 5) || (sensor == 6)){
	level = 0x38;
      }
      else if((sensor == 7) || (sensor == 8) || (sensor == 9)){
	level = 0x3C;
      }
      else if((sensor == 10) || (sensor == 11) || (sensor == 12)){
	level = 0x3E;
      }
      else if((sensor == 13) || (sensor == 14) || (sensor ==15)){
	level = 0x3F;
      }
      PORTC = level;
    }
    return 1;
}
