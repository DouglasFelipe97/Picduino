/* Start_Signal (): esta função envia o sinal de partida para o sensor, 
envia uma lógica baixa por 25 ms e uma lógica alta por 30 us.

Check_Response (): esta função verifica se existe uma resposta do sensor 
(após enviar o sinal de início utilizando a função anterior), retorna 1 (verdadeiro) se ok e 0 (falso)
 se houver erro (por exemplo um problema de conexão).

Read_Data (* dht_data): esta função lê os dados de temperatura e umidade do sensor (4 bytes),
 ela também lê um outro byte (5º byte) que é usado como checksum. Esta função retorna 0 (falso)
 se os dados lidos estiverem ok e 1 (verdadeiro) se houver um problema de tempo limite.

Neste projeto será usado o módulo Timerpara medir larguras de sinais (larguras lógicas 1 e lógicas 0),
 ele está configurado para incrementar a cada 1 us.

*/
#include <xc.h>
#include "DHT11.h"

 

void StartSignal(void) { //envia o sinal de partida para que o sensor comece a enviar os dados.

  DHT11_PIN_DIR = 0;     // configura DHT11_PIN como saída
  DHT11_PIN = 0;         // limpa a saida DHT11_PIN(envia o sinal baixo para o sensor)
 
  __delay_ms(10);        // aguarda resposta em 18 ms
  DHT11_PIN = 1;         // seta o pino DHT11_PIN como nivel alto(logic 1)
 
  __delay_us(30);        // aguarda resposta em 30 us
  DHT11_PIN_DIR = 1;     // configura o pino DHT11_PIN como entrada para ler os dados iniciais.
}

unsigned short ReadByte(){
char data, for_count;
    for(for_count = 0; for_count < 8; for_count++){
        while(!DHT11_PIN);
            __delay_us(30);
        if(DHT11_PIN == 0){
            data&= ~(1<<(7 - for_count)); //Clear bit (7-b)
        }
        else{
            data|= (1 << (7 - for_count)); //Set bit (7-b)
            while(DHT11_PIN);
        }
     }
    return data;
}
 
// Check sensor response
unsigned short CheckResponse(){
    __delay_us(40);
    if (DHT11_PIN == 0){
        __delay_us(80);
    if (DHT11_PIN == 1){
   		__delay_us(80);
		return 1;}
    }
 }