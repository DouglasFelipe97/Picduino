

#include <pic16f877a.h>
#include <xc.h>
#include <stdio.h>
#include "LCD4B.h"
#include "DHT11.h"

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

    char message1[] = "Temp = 00.0 C";
    char message2[] = "Humi = 00.0 %";
    unsigned short check, CheckSum;
    unsigned short T_Byte1, T_Byte2, RH_Byte1, RH_Byte2;
    unsigned int Temp, RH;      

void main(void){
    
    void delay_1s(void);

    LCD_Init();
    while (1){ 
      delay_1s();
      StartSignal();
      check = CheckResponse();
      if(!check){ 
         LCD_Clear();
         LCD_Char_xy(1, 1, "No response");
         LCD_Char_xy(2, 1, "from the sensor");
       }
      else{ 
         RH_Byte1 = ReadByte();
         RH_Byte2 = ReadByte();
         T_Byte1  = ReadByte();
         T_Byte2  = ReadByte();
         CheckSum = ReadByte();
         
         // From RHT03 (DHT22 equivalent) datasheet:
         // Example: MCU has received 40 bits data from RHT03 as
         // 0000 0010 1000 1100   0000 0001 0101 1111   1110 1110
         // 16 bits RH data       16 bits T data        check sum
         // Check sum=0000 0010+1000 1100+0000 0001+0101 1111=1110 1110
         // RH= (0000 0010 1000 1100)/10=65.2%RH
         // T=(0000 0001 0101 1111)/10=35.1 DEG
         // When highest bit of temperature is 1, it means the temperature is below 0 degree Celsius.
         // Example: 1000 0000 0110 0101, T= minus 10.1 DEG
         //             16 bits T data
        if(CheckSum == ((RH_Byte1+RH_Byte2+T_Byte1+T_Byte2) & 0XFF)){
            RH = RH_Byte1;
            RH = (RH << 8) | RH_Byte2;
            Temp = T_Byte1;
            Temp = (Temp << 8) | T_Byte2;
            if (Temp > 0X8000){
                message1[6] = '-';
                Temp = Temp & 0X7FFF; }
            else
                message1[6] = ' ';
                message1[7]  = (Temp / 100) % 10  + 48;
                message1[8]  = (Temp / 10) % 10  + 48;
                message1[10] = Temp % 10  + 48;
                message2[7]  = (RH / 100) % 10 + 48;
                message2[8]  = (RH / 10) % 10 + 48;
                message2[10] = RH % 10 + 48;
                message1[11] = 223;                   // Degree symbol
                LCD_Clear();
                LCD_String_xy(1, 1, message1);
                LCD_String_xy(2, 1, message2);
          
                __delay_ms(2000);
        } 
        else{
          LCD_Char_xy(1, 2, "Check sum error");
        }
      }
    }
}

void delay_1s(void)
{ for (short i=0; i<20; i++)
    __delay_ms(100);   
 }
