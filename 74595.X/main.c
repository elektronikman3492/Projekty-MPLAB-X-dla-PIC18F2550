/*DATA (DS) - RB7
  CLK (SH_CP) - RA0
  LATCH (ST_CP) - RB6*/
  
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "config.h"
#include "_74595.h"

int main(int argc, char** argv) {

    //ustawienie pinow jako wyjscia
    DTtris = 0;
    CLKtris = 0;
    LATCHtris = 0;

    while(1) {
        shift_data(0b10000000);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b11000000);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b11100000);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b11110000);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b11111000);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b11111100);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b11111110);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b11111111);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b01111111);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b00111111);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b00011111);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b00001111);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b00000111);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b00000011);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b00000001);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
        shift_data(0b00000000);
        for (unsigned char i=0; i<10; i++) {
                __delay_ms(10);
            }
    }

    return (EXIT_SUCCESS);
}

