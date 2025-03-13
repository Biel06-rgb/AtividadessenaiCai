//Autor:Gabriel Araujo de Sousa
//Data:7/3/2025
//Nome do programa:Piscar um led sem delay

unsigned long tempoInicial = 0;
bool estadoLed = 0;


#define pinLedVermelho 13

void setup()
{
 
 pinMode(pinLedVermelho, OUTPUT);
  
 

}

void loop()
{
 
unsigned long tempoAtual = millis();
  
  if (tempoAtual-tempoInicial >=1000){
    
    if (estadoLed){
  digitalWrite(pinLedVermelho, LOW);
    estadoLed=0;
    
  }else {
  digitalWrite(pinLedVermelho, HIGH);
    estadoLed=1;
  }
 tempoInicial = tempoAtual; 
  } 
}