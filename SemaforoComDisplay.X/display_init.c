/*
 * File:   display_init.c
 * Author: 19267692
 *
 * Created on 11 de Março de 2021, 14:11
 */


#include <xc.h>
#include "config.h"

void init_display(void)
{
    ANSELH = 0;
    TRISB = 0X00;
    PORTB = 0X00;
    TRISDbits.TRISD1 = 1;
}

char vetor[16] = { 0x3F, 0x06, 0x5B, 0x4F,
                   0x66, 0x6D, 0x7D, 0x07,
                   0x7F, 0x6F, 0x77, 0x7C,
                   0x39, 0x5E, 0x79, 0x71 };

void display7seg( char c )
{
    if ( c >=0 && c <= 15 )
        PORTB = vetor[c];
    else
        PORTB = 0x00;
}
