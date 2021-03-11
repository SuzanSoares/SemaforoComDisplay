/*
 * File:   delay.c
 * Author: 19267692
 *
 * Created on 5 de Fevereiro de 2021, 17:06
 */


#include <xc.h>
#include "config.h"


void delay (int t)
{
    while(t)
    {
        __delay_ms(1);
        --t;
    }
}
