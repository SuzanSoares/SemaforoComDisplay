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
int state = 0;
int cont;


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
                t = 5000;
                    estado = 8;
                break;
            case 8:
                delay(1);
                --t;
                if ( t <= 0 )
                    estado = 2;
                break;
        }
        
        switch ( state )
        {
            case 0:
                    state = 1;
                break;
            case 1:
                init_display();
                    state = 2;
                break;
            case 2:
                PORTB = 0x00;
                if( botao() == 1 )
                    state = 3;
                break;
            case 3:
                cont = 3;
                t = 3000;
                state = 4;
                break;
            case 4:
                --t;
                delay(1);
                if ( t <= 0 )
                    state = 5;
                break;
            case 5:
                cont--;
                display7seg( cont );
                break;
            case 6:
                if (cont <= 0)
                    state = 7;
                break;
            case 7:
                t = 7000;
                state = 8;
                break;
            case 8:
                --t;
                delay(1);
                if ( t <= 0 )
                    state = 9;
            case 9:
                cont--;
                display7seg( cont );
                break;
            case 10:
                if (cont <= 0)
                    state = 2;
                break;
        }
    } 
}
