// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <pic16f877a.h>
#include <xc.h>
// Oscilador
void osc20(){
#ifndef _XTAL_FREQ

#define _XTAL_FREQ 20000000

#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000000.0)))

#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/4000.0)))

#endif
}
void config(){
// Padrão de configurações
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
    // Flash Program Memory Code Protection bit (Code protection off) 
}
int cont, cont1;

void interrupt int1(){
    if(TMR0IF == 1){
        cont++;
        if(cont ==100){ //CONTADOR 100MS
            cont1++;
            cont=0;
        }
        if(cont1 == 5){ //CONTADOR 500MS
            PORTBbits.RB7 = ~PORTBbits.RB7;
        }
        if(cont1 == 10){ //CONTADOR 1S
            PORTAbits.RA0 = 1;
        }
        if(cont1 == 20){ //CONTADOR 2S
            PORTAbits.RA0 = 0;
            cont1 = 0;
        }
                        //FORMULA DO TEMPO ESTOURO TIMER RegValue = 256-(Delay * Fosc)/(Prescalar*4))
        TMR0 = 101;     //O valor do tempo é 101 instaurado em 100, pois o TImer0 
                        //precisa de dois ciclos de instrução para começar a incrementar TMR0
        TMR0IF =0;      //ZERA A FLAG PARA UMA NOVA INTERRUPÇÃO.
    }
}

void main(){
   void osc20();
   void config();
   TRISB = 0b00000000;    //define todos os pinos do portb como saida.  
   TRISA = 0b00000000;    //define todos os pinos do porta como saida. 
   PORTB = 0b00000000;    //zera todos os pinos do portb.
   PORTA = 0b00000000;    //zera todos os pinos do porta.
        
   OPTION_REG = 0b10000100;;   //RESISTORES DE PULL UP DESLIGADOS/ PRE SCALE 1:32 ASSOCIADO AO TIMER 0
   INTCONbits.GIE= 0x01;       //HABILITA AS INTERRUPCOES GLOBAIS
   INTCONbits.PEIE = 0x01;     //INTERRUPCAO POR PERIFERICOS (TIMER0) HABILITADAS
   INTCONbits.TMR0IE = 0x01;   //HABILITA A INTERRUPCAO POR ESTOURO DA CONTAGEM DO TIMER0
                               //VALOR TMR0 = 256-((1ms * 20Mhz)/(32*4)) = 256-156=100
   TMR0 = 100;                 //INICIA A CONTAGEM EM 100 */
    
    while(1){}
}
   
