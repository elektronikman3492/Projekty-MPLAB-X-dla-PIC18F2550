#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <plib/i2c.h>
#include "config.h"



int main(int argc, char** argv) {

OpenI2C(MASTER, SLEW_OFF);
SSPADD = 49;

//unsigned char in_addr = 0x41; //adres PCF8574 dla uzycia jako wejscie 0b01000001
unsigned char Ain_addr = 0x71; //adres PCF8574A dla uzycia jako wejscie 0b01110001

unsigned char data;

TRISAbits.RA0 = 0;

while(1) {
    IdleI2C();
    StartI2C();
    IdleI2C();
    WriteI2C(Ain_addr);
    IdleI2C();
    data = ReadI2C();
    //AckI2C();
    //data= ReadI2C();
    NotAckI2C();
    StopI2C();

    if (data == 0b01111111) { //domyslny stan wejscia to 1
        LATA0 = 1;
    }
    else {
        LATA0 = 0;
    }
}

    return (EXIT_SUCCESS);
}

