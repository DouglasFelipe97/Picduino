#include <xc.h>

    #ifndef XTAL_FREQ
        #define _XTAL_FREQ 20000000
    #endif


	#define DHT11_PIN      PORTCbits.RC0 //PINO DE DADOS DHT11
	#define DHT11_PIN_DIR  TRISC0 //DIREÇÃO DO PINO DE DADOS DHT11
	



		void StartSignal(void);
		unsigned short ReadByte();
		unsigned short CheckResponse(void);
		
