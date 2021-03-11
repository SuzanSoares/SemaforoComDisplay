/*
 * File:   mainc.c
 * Author: 19267692
 *
 * Created on 11 de Março de 2021, 13:13
 */


#include <xc.h>
#include "config.h"
#include "delay.h"
#include "semaforo.h"
#include "Func_Semaforo.h"
#include "display7seg.h"

int estado = 0;
int t;

void main(void) 
{
    while ( 1 )
    {
        switch ( estado )
        {
            case 0:
                    estado = 1;
                break;
            case 1:
                semaforo_init();
                init_display();
                    estado = 2;
                break;
            case 2:
                verde(1);
                vermelho(0);
                amarelo(0);
                verdePed(0);
                vermelhoPed(1);
                PORTB = 0x00;
                    if( botao() == 1 )
                    estado = 3;
                break;
            case 3:
                t = 3000;
                    estado = 4;
                break;
            case 4:
                delay(1);
                --t;
                if ( t <= 0 )
                    estado = 5;
                break;
            case 5:
                verde(0);
                amarelo(1);
                t = 3000;
                contagem_amarelo();
                estado = 6;
                break;
            case 6:
                delay(1);
                --t;
                if ( t <= 0 )
                    estado = 7;
                break;
            case 7:
                vermelhoPed(0);
                amarelo(0);
                vermelho(1);
                verdePed(1);
                contagem_vermelho();
                t = 7250;
                    estado = 8;
                break;
            case 8:
                delay(1);
                --t;
                if ( t <= 0 )
                    estado = 2;
                break;
        }
    } 
}
