#include <xc.h> // include processor files - each processor file is guarded.



  
    // ========================================================================================//
    //Definição de configurações
    // ========================================================================================//

    //Cristal Oscilador - Frequencia
    #ifndef XTAL_FREQ
        #define _XTAL_FREQ 20000000
    #endif
    //Pinos para Display LCD
    
        #define RS PORTBbits.RB0  
        #define EN PORTBbits.RB1  
        #define D4 PORTBbits.RB2
        #define D5 PORTBbits.RB3
        #define D6 PORTBbits.RB4
        #define D7 PORTBbits.RB5
 
    
	
	//Prototipos de função
	
	
            void LCD_Init();                   /*Initialize LCD*/
            void LCD_Command(unsigned char );  /*Send command to LCD*/
            void LCD_Char(unsigned char x);    /*Send data to LCD*/
            void LCD_String(const char *);     /*Display data string on LCD*/
            void LCD_String_xy(char, char , const char *);
            void LCD_Char_xy(char row,char pos,unsigned char dat);
            void LCD_Clear();                  /*Clear LCD Screen*/

	
