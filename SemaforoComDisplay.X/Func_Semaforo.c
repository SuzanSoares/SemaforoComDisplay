/*
 * File:   Func_Semaforo.S
 * Author: 19267692
 *
 * Created on 11 de Março de 2021, 13:16
 */


#include <xc.h>
#include "config.h"
#include "delay.h"

void contagem_amarelo ( void )
{
    PORTB = 0x4F;
    delay (1000);
    PORTB = 0x5B;
    delay (1000);
    PORTB = 0x06;
    delay (1000);
    PORTB = 0X3F;
    delay (300);
}

void contagem_vermelho ( void )
{
    PORTB = 0x7F;
    delay (1000);
    PORTB = 0x07;
    delay (1000);
    PORTB = 0x7D;
    delay (1000);
    PORTB = 0x6D;
    delay (1000);
    PORTB = 0x66;
    delay (1000);
    PORTB = 0x4F;
    delay (1000);
    PORTB = 0x5B;
    delay (1000);
    PORTB = 0x06;
    delay (1000);
    PORTB = 0X3F;
    delay (300);
}
