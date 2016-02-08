#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif


#define _XTAL_FREQ 20000000

#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config USBDIV = 2
#pragma config FOSC = HSPLL_HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config BOR = OFF
#pragma config MCLRE = ON
#pragma config PWRT  = ON
#pragma config PBADEN = OFF
#pragma config VREGEN	= ON


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

