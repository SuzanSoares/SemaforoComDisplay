/*
 * File:   semaforo.c
 * Author: 19267692
 *
 * Created on 19 de Fevereiro de 2021, 15:16
 */


#include <xc.h>
#include "config.h"
#include "delay.h"

#define VERMELHO PORTDbits.RD7
#define AMARELO PORTDbits.RD6
#define VERDE PORTDbits.RD5
#define VERMELHOPED PORTDbits.RD3
#define VERDEPED PORTDbits.RD2
#define BOTAO PORTDbits.RD1


void semaforo_init(void) 
{
    TRISDbits.TRISD1 = 1;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    
    PORTDbits.RD2 = 0;
    PORTDbits.RD3 = 0;
    PORTDbits.RD5 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD7 = 0;
}

void vermelho ( int x )
{
    VERMELHO = x;
}

void amarelo ( int x )
{
    AMARELO = x;
}

void verde ( int x )
{
    VERDE = x;
}

void vermelhoPed ( int x )
{
    VERMELHOPED = x;
}

void verdePed ( int x )
{
    VERDEPED = x;
}

int botao ( void )
{
    return ( BOTAO );
}

int estado = 0;
int t;

