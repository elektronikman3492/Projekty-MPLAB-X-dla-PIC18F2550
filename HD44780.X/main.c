/*DB7 - RB7
  DB6 - RB6
  DB5 - RB5
  DB4 - RB4
  ENABLE - RB3
  RS - RB2*/
  
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "config.h"
#include "hd44780.h"


int main(int argc, char** argv) {
/**************INICJALICACJA*****************/
    for (int i=0; i>10; i++) {
        __delay_ms(30);
    }
    Init_lcd();
    LcdCmd(DISP_ON_CURSOR_OFF_BLINK_OFF);
    LcdCmd(_4_BIT_2_LINES_FONT_5X8);
/********************************************/

    znaki_pl_i_stopien();

while(1) {
    LcdClr();
    for (unsigned char i=0; i<8; i++) { //wyswietlenie znakow specjalnych
        SetCursor(i,1);
        LcdData(i);
    }
    
    for (int i=0; i<200; i++) { //czekaj 2 s
        __delay_ms(10);
    }

    LcdClr;
    LcdText(0, 1, "Pierwsza linia"); //wyswietl tekst x=0 miejsc pustych, y=1 linia
    LcdText(0, 2, "Druga linia");

    for (int i=0; i<200; i++) { //czekaj 2 s
        __delay_ms(10);
    }

    for (unsigned char j=0; j<16; j++) {
        LcdCmd(SHIFT_LCD_LEFT); //przesun o jedno pole w lewo
        for (int i=0; i<30; i++) { //czekaj 300 ms
        __delay_ms(10);
        }
    }

    for (unsigned char k=0; k<16; k++) {
        LcdCmd(SHIFT_LCD_RIGHT); //przesun o jedno pole w prawo
        for (int i=0; i<30; i++) { //czekaj 300 ms
        __delay_ms(10);
        }
    }

    for (int i=0; i<200; i++) { //czekaj 2 s
        __delay_ms(10);
    }
}
 return (EXIT_SUCCESS);
 }
