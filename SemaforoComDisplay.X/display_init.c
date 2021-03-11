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
