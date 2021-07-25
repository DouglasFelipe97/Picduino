#include <xc.h> // include processor files - each processor file is guarded.
#include "LCD4B.h"

	
	//Display LCD 20x4
//========================================================================================================================//

void LCD_Command(unsigned char cmd )
{
    
    short OUTS[8], i;
    
    for (i=0; i < 8; i++ ) { 
  
        // storing remainder in binary array 
        OUTS[i] = cmd % 2; 
        cmd = cmd / 2; 
      //  i++; 
    } 
    
	//dsipdata = (dsipdata & 0x0f) |(0xF0 & cmd);  /*Send higher nibble of command first to PORT*/ 
    D4 = OUTS[4];
    D5 = OUTS[5];
    D6 = OUTS[6];
    D7 = OUTS[7];
	RS = 0;  /*Command Register is selected i.e.RS=0*/ 
	EN = 1;  /*High-to-low pulse on Enable pin to latch data*/ 
	NOP();
	EN = 0;
	__delay_ms(1);
    //dsipdata = (dsipdata & 0x0f) | (cmd<<4);  /*Send lower nibble of command to PORT */
    D4 = OUTS[0];
    D5 = OUTS[1];
    D6 = OUTS[2];
    D7 = OUTS[3];    
	EN = 1;
	NOP();
	EN = 0;
	__delay_ms(3);
}

void LCD_Init()
{
	TRISB = 0x0;
    
    __delay_ms(40);        /*15ms,16x2 LCD Power on delay*/
    LCD_Command(0x02);  /*send for initialization of LCD 
                          for nibble (4-bit) mode */
    LCD_Command(0x28);  /*use 2 line and 
                          initialize 5*8 matrix in (4-bit mode)*/
	LCD_Command(0x01);  /*clear display screen*/
    LCD_Command(0x0c);  /*display on cursor off*/
	LCD_Command(0x06);  /*increment cursor (shift cursor to right)*/	   
}

void LCD_Char(unsigned char dat)
{
    short OUTS[8], i;
    
    for (i=0; i < 8; i++ ) { 
  
        // storing remainder in binary array 
        OUTS[i] = dat % 2; 
        dat = dat / 2; 
    }  
       
	//dsipdata = (dsipdata & 0x0f) | (0xF0 & dat);  /*Send higher nibble of data first to PORT*/
    D4 = OUTS[4];
    D5 = OUTS[5];
    D6 = OUTS[6];
    D7 = OUTS[7];
	RS = 1;  /*Data Register is selected*/
	EN = 1;  /*High-to-low pulse on Enable pin to latch data*/
	NOP();
	EN = 0;
	__delay_ms(1);
    //dsipdata = (dsipdata & 0x0f) | (dat<<4);  /*Send lower nibble of data to PORT*/
    D4 = OUTS[0];
    D5 = OUTS[1];
    D6 = OUTS[2];
    D7 = OUTS[3];
	EN = 1;  /*High-to-low pulse on Enable pin to latch data*/
	NOP();
	EN = 0;
	__delay_ms(3);
}


void LCD_Char_xy(char row,char pos,unsigned char dat)
{
    char location=0;
    switch (row){
        case 1:
           location=(0x80) | ((pos) & 0x0f);  /*Print message on 1st row and desired location*/
           LCD_Command(location);   
           break;
        case 2:
           location=(0xC0) | ((pos) & 0x0f);  /*Print message on 1st row and desired location*/
           LCD_Command(location);   
           break;
        case 3:
           location=(0x94) | ((pos) & 0x0f);  /*Print message on 1st row and desired location*/
           LCD_Command(location);   
           break;
        case 4:
           location=(0xD4) | ((pos) & 0x0f);  /*Print message on 1st row and desired location*/
           LCD_Command(location);   
           break;
           
    }

    

    LCD_Char(dat);
}

void LCD_String(const char *msg)
{
	while((*msg)!=0)
	{		
	  LCD_Char(*msg);
	  msg++;	
    }
}

void LCD_String_xy(char row,char pos,const char *msg)
{
    char location=0;
    switch (row){
        case 1:
           location=(0x80) | ((pos) & 0x0f);  
           LCD_Command(location);   
           break;
        case 2:
           location=(0xC0) | ((pos) & 0x0f);  
           LCD_Command(location);   
           break;
        case 3:
           location=(0x94) | ((pos) & 0x0f); 
           LCD_Command(location);   
           break;
        case 4:
           location=(0xD4) | ((pos) & 0x0f);  
           LCD_Command(location);   
           break;
           
    }

    LCD_String(msg);

}

void LCD_Clear()
{
   	LCD_Command(0x01);  /*clear display screen*/
    __delay_ms(3);
}
