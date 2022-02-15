/* 
 * File:   main.c
 * Author: Douglas
 *
 * Created on 2 de Fevereiro de 2022, 22:40
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>
#include <xc.h>
#include "LCD4B20X4.h"
/*
 * 
 */ 

    #define _XTAL_FREQ 8000000      //define para utilizar funções de tempo 

// CONFIG
    #pragma config FOSC = INTOSC_HS         //internal ocsillator              
    #pragma config WDT = OFF              //turn off WDT              
    #pragma config LVP = OFF              //turn off LVP              
    #pragma config BOR = ON               //enable brownout reset              
    #pragma config MCLRE = OFF            //tie MCLR to Vdd, free up 
// CONFIG1L
    #pragma config PLLDIV = 2       // PLL Prescaler Selection bits (Divide by 5 (20 MHz oscillator input))
    #pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
    #pragma config USBDIV = 2       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes from the 96 MHz PLL divided by 2)
    
    

#define AD_dir          TRISAbits.TRISA0
#define LED_dir         TRISBbits.TRISB6
#define LED             LATBbits.LB6
#define LED1_dir        TRISBbits.TRISB7
#define LED1            LATBbits.LB7

/*VARIAVEIS*/
unsigned int temp = 0, temp1 = 0;
unsigned int aux1=0, aux2=0;
char vec[]  = "S1: 00%";
char vec1[] = "S2: 00%";

/*PROTOTIPOS*/

    void ADC_Initialize(unsigned short channel);
    unsigned int ADC_Read(unsigned short channel);
    void formatar_valord(char buff[],unsigned int d);
    

void main(void) {
    
    OSCCON = 0b01110111;                //CONFIGD DO OSCILADOR
    CMCON = 0x00;                       //COMPARADORES DIGITAIS DESLIGADOS
    
    //INICIANDO VARIASVEIS E SUAS DIREÇOES(I/O)
    LED1_dir = 0;
    LED_dir = 0;
    AD_dir = 1;
    LED1 = 0;
    LED = 0;
    
    ADC_Initialize(1);
    LCD_Init();
    LCD_Clear();
    
    while(1){
        //------------------------------// CASO NAO USE LCD IGNORAR
        LCD_String_xy(1,3,"MEDTENS");
        LCD_String_xy(3,3,"V1.0");
        __delay_ms(20);
        //------------------------------//
        ADC_Initialize(1);              //Inicializa o conversor utilizando dois canais analogico AN0 E AN1
        temp  = ADC_Read(0);            //CONV AN0: Junta parte alta com parte baixa em um valor de 16 bits e armazena na variavel
        temp /=10.23;                   //Divisão para obter a porcentagem, caso queira o valor bruto ignorar essa linha
        __delay_ms(50);
        temp1 = ADC_Read(1);            //CONV AN1: Junta parte alta com parte baixa em um valor de 16 bits e armazena na variavel
        temp1 /=10,23;                  //Divisão para obter a porcentagem, caso queira o valor bruto ignorar essa linha
        __delay_ms(50);
       //-------------------------------// CASO NAO USE LCD IGNORAR
        formatar_valord(vec,temp);      //a string utilizada no display é informada e a variavel a ser convertida
        formatar_valord(vec1,temp1);    //                             ~~    
        LCD_String_xy(2,3,vec);
        LCD_String_xy(2,11,vec1);
        __delay_ms(20);
        //------------------------------//
        if(temp >= 30 && temp <= 80){   //LED PARA SINALIZAR SE O CONVERSOR ESTA ATIVO
            LED = 1;                    //CASO UTILIZE OS VALORES BRUTOS DO SENSOR UTILIZAR MAIS UM ZERO (300~800)  
            LED1 = 0;
        }
        else {
            LED = 0; 
            LED1 = !LED1;
            __delay_ms(100);
        }
    } 
            
}

void ADC_Initialize(unsigned short channel)
{
    //ADCON1/2 - PG 261-262 Configuração bit a bit
    ADCON1bits.VCFG0=0;                  //Configura referência de tensão positiva
    ADCON1bits.VCFG1=0;                  //Configura referência de tensão negativa
    ADCON1bits.PCFG= (0b1111-(channel+1));    //Configura quais canais devem ser habilitados
                                //  channel+1 convertido a binario - 0b1111 resulta nas portas analogicas //
                                //  que desejamos habilitar conforme a tabela do registrador adcon1       //               
    ADCON2bits.ADFM=1;                   //Configura justiicação do resultado a direita
    ADCON2bits.ACQT=0b111;               //Configura velocidade de aquisição (maior, menor precisão)
    ADCON2bits.ADCS=0b000;               //Configura clock de entrada do ADC
    
    /*ADCON1/2 - PG 261-262 Configuração do registrador de forma completa
    ADCON0 = 0b00000001;    //00|0000|001 LEITURA NO CANAL AN0 SELECIONADO// 000000|0|1 CONVERSÃO DESLIGADA
                            //0000000|1| MODOCULO DE CONVERSÃO HABILITADO
    ADCON1 = 0b00001110;    //00|00|1110 VREF = VSS & VDD// 0000|1110| CANAL AN0 = ANALOGICO
    ADCON2 = 0b10100001;    //|1|0100001 JUSTIFICADO A DIREITA// 10|100|001 8xTAD
                            //10100|001| CLK DO CONVERSOR = FOSC/8
    ADCON0bits.GO = 1;
    */
}

unsigned int ADC_Read(unsigned short channel)
{
    unsigned long int temp;
    //ADCON0 - PG 265 Configuração do registrador bit a bit
    ADCON0bits.CHS = channel;       //seu valor convertido a binario Informa qual canal deverá ser aquisitado
    ADCON0bits.ADON = 1;            //Ativa conversão AD
    ADCON0bits.GODONE = 1;          //Sinaliza inicialização da conversão AD
    
    /*ADCON0 - PG 265 Configuração do registrador por completo
    ADCON0 = 0b00000001;            //00|0000|001 LEITURA NO CANAL AN0 SELECIONADO// 000000|0|1 CONVERSÃO DESLIGADA
                                    //0000000|1| MODOCULO DE CONVERSÃO HABILITADO 
    ADCON0bits.GO = 1; */  
    
    //Conversão dos valores obtidos
    while(ADCON0bits.GODONE);       //Verifica se a conversão AD foi concluida
    temp = ADRESH;                  // Parte alta do valor lido
    temp = ((temp << 8)| ADRESL );  // Junta parte alta com parte baixa em um valor de 16 bits
    return (temp);                  //Retorna o valor discretizador
}

void formatar_valord(char buff[],unsigned int d){
    //Formatando os valores decimais das variaveis em padrão ASC p/display LCD
	unsigned char dezena,unidade,centena,milhar;
	unsigned int aux;
    milhar  = 0;
	centena = 0;
	dezena  = 0;
	unidade = 0;
    
    //---------------------------------//
	aux = d;
    for(;aux>=1000;aux -=1000){milhar++;}
	for(;aux>=100;aux -=100){centena++;}
	for(;aux>=10;aux -=10){dezena++;}
	for(;aux>=1;aux -=1){unidade++;}
        //------///
    milhar  = milhar  + 48;
	centena = centena + 48;
	dezena  = dezena  + 48;
	unidade = unidade + 48;
          //----//
    //buff[0] = milhar;
    //buff[1] = centena;
    buff[4] = dezena;
    buff[5] = unidade;
}