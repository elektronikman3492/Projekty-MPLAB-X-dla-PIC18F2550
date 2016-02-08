#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xc.h>
#include <plib/i2c.h>
#include <math.h>
#include "config.h"
#include "adxl345_i2c.h"
#include "hd44780.h"

int main(int argc, char** argv) {
    /**************INICJALICACJA*****************/
    for (int i=0; i>10; i++) {
        __delay_ms(30);
    }
    OpenI2C(MASTER, SLEW_OFF);
    //SSPADD = ((Fosc/predkosc magistrali)/4)-1
    SSPADD = 49; //dla zegara 20 MHz i predkosci 100kHz: ((20 000 000/100 000)/4)-1 = 49
    
    Init_lcd();
    LcdCmd(DISP_ON_CURSOR_OFF_BLINK_OFF);
    LcdCmd(_4_BIT_2_LINES_FONT_5X8);

    Init_adxl345(-5, -3, 1, _16G, Hz_100); //x offset, y offset, z offset, zakres 16 G, pr?dko?? przesy?u danych 100 Hz
/********************************************/

    


    while(1) {
        LcdText(3, 1, "       "); //czyszczenie danych na wy?wietlaczu
        LcdText(12, 0, "    ");
        LcdText(3, 2, "             ");

        LcdText(0, 1, "X= ");
        LcdText(3, 1, getX());

        LcdText(9, 0, "Y= ");
        LcdText(11, 0, getY());

        LcdText(0, 2, "Z= ");
        LcdText(3, 2, getZ());

        for (unsigned char i=0; i<100; i++) { //czekaj 1 s
            __delay_ms(10);
        }
    }


    return (EXIT_SUCCESS);
}

