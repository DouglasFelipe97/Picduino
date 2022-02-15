#include <xc.h> // include processor files - each processor file is guarded.

  
    // ========================================================================================//
    //Definição de configurações
    // ========================================================================================//

    //Cristal Oscilador - Frequencia
    #ifndef XTAL_FREQ
        #define _XTAL_FREQ 8000000
    #endif
    //Pinos para Display LCD
        #define RS LATBbits.LB0  
        #define EN LATBbits.LB1  
        #define D4 LATBbits.LB2
        #define D5 LATBbits.LB3
        #define D6 LATBbits.LB4
        #define D7 LATBbits.LB5
        #define RSTRIS TRISBbits.TRISB0 
        #define ENTRIS TRISBbits.TRISB1   
        #define D4TRIS TRISBbits.TRISB2  
        #define D5TRIS TRISBbits.TRISB3   
        #define D6TRIS TRISBbits.TRISB4   
        #define D7TRIS TRISBbits.TRISB5  

	//Prototipos de função

            extern void LCD_Init();                   /*Initialize LCD*/
            extern void LCD_Command(unsigned char );  /*Send command to LCD*/
            extern void LCD_Char(unsigned char x);    /*Send data to LCD*/
            extern void LCD_String(const char *);     /*Display data string on LCD*/
            extern void LCD_String_xy(char, char , const char *);
            extern void LCD_Char_xy(char row,char pos,unsigned char dat);
            extern void LCD_Clear();                  /*Clear LCD Screen*/

	
