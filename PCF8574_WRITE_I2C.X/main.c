#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <plib/i2c.h>
#include "config.h"

int main(int argc, char** argv) {

    /*ADRESY USTALONE DLA WEJSC A0, A1, A2 PODLACZONYCH DO MASY*/

    unsigned char Aout_addr = 0x70; //adres dla PCF8574A 0b01110000
  //unsigned char out_addr = 0x40; //adres dla PCF8574 0b01000000
    
    OpenI2C(MASTER, SLEW_OFF);
    //SSPADD = ((Fosc/predkosc magistrali)/4)-1
    SSPADD = 49; //dla zegara 20 MHz i predkosci 100kHz: ((20 000 000/100 000)/4)-1 = 49
     while(1) {

        IdleI2C(); //sprawdzanie, czy magistrala jest w stanie bezczynnosci
        StartI2C();
        IdleI2C();
        WriteI2C(Aout_addr);
        IdleI2C();
        WriteI2C(0b00000001);
        IdleI2C(); 
        StopI2C();
        for (unsigned char i=0; i<40; i++) { //czekaj 40 * 10ms = 400 ms
            __delay_ms(10);
        }

        IdleI2C();
        StartI2C();
        IdleI2C();
        WriteI2C(Aout_addr);
        IdleI2C();
        WriteI2C(0b00000010);
        IdleI2C();
        StopI2C();
        for (unsigned char i=0; i<40; i++) {
            __delay_ms(10);
        }

        IdleI2C();
        StartI2C();
        IdleI2C();
        WriteI2C(Aout_addr);
        IdleI2C();
        WriteI2C(0b00000100);
        IdleI2C();
        StopI2C();
        for (unsigned char i=0; i<40; i++) {
            __delay_ms(10);
        }

        IdleI2C();
        StartI2C();
        IdleI2C();
        WriteI2C(Aout_addr);
        IdleI2C();
        WriteI2C(0b00001000);
        IdleI2C();
        StopI2C();
        for (unsigned char i=0; i<40; i++) {
            __delay_ms(10);
        }

        IdleI2C();
        StartI2C();
        IdleI2C();
        WriteI2C(Aout_addr);
        IdleI2C();
        WriteI2C(0b00010000);
        IdleI2C();
        StopI2C();
        for (unsigned char i=0; i<40; i++) {
            __delay_ms(10);
        }

        IdleI2C();
        StartI2C();
        IdleI2C();
        WriteI2C(Aout_addr);
        IdleI2C();
        WriteI2C(0b00100000);
        IdleI2C();
        StopI2C();
        for (unsigned char i=0; i<40; i++) {
            __delay_ms(10);
        }

        IdleI2C();
        StartI2C();
        IdleI2C();
        WriteI2C(Aout_addr);
        IdleI2C();
        WriteI2C(0b01000000);
        IdleI2C();
        StopI2C();
        for (unsigned char i=0; i<40; i++) {
            __delay_ms(10);
        }

        IdleI2C();
        StartI2C();
        IdleI2C();
        WriteI2C(Aout_addr);
        IdleI2C();
        WriteI2C(0b10000000);
        IdleI2C();
        StopI2C();
        for (unsigned char i=0; i<40; i++) {
            __delay_ms(10);
        }
    }


    return (EXIT_SUCCESS);
}

