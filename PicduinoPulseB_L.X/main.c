/*
          BUZZER&LED PULSE.
          PICDUÍNO 16F877A V2.0.
          AUTOR: DOUGLAS FELIPE.
          DATA: 20/06/2021.
 */               
// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <pic16f877a.h>
#include <xc.h>
// Oscilador
void osc20(){
#ifndef _XTAL_FREQ

#define _XTAL_FREQ 20000000

#define __delay_us(x) _delay((unsigned long)((x)*(_XTAL_FREQ/20000000.0)))

#define __delay_ms(x) _delay((unsigned long)((x)*(_XTAL_FREQ/20000.0)))

#endif
}
void config(){
// Padrão de configurações
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = ON // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)
    // Flash Program Memory Code Protection bit (Code protection off) 
}
void main(){
   void osc20();
   void config();
   TRISB = 0b00000000;    //define todos os pinos do portb como saida.  
   TRISA = 0b00000000;    //define todos os pinos do porta como saida. 
   PORTB = 0b00000000;    //zera todos os pinos do portb.
   PORTA = 0b00000000;    //zera todos os pinos do porta.
   

          while(1){              //loop infinito, vai ate o fim do parenteses e volta executar no inicio do parenteses.
         PORTBbits.RB7 = 1;      //pulsa LIGANDO o buzzer MANDA 5V RB7.
         PORTAbits.RA0 = 0;      //apaga o led MANDA 5V RA0.
         __delay_ms(1000);       //espera um tempo de 1000ms = 1s.
         PORTBbits.RB7 = 0;      //pulsa DESLIGANDO o buzzer MANDA 5V RB7.
         PORTAbits.RA0 = 1;      //ascende led manda 0v RA0.
         __delay_ms(5000);       //espera um tempo de 5000ms = 5s.
     }
    
}
