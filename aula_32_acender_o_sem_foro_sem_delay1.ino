//Autor:Gabriel Araujo de Sousa
//Data:10/3/2025
//Descricao:Tentar acender o semafaro sem delay

#define pinLedVermelho 13
#define pinLedAmarelo 12
#define pinLedVerde 11

unsigned long tempoInicial = 0;
int faseSemaforo = 0;


#define tempoVermelho 3000;
#define tempoAmarelo 2000;
#define tempoVerde 5000;


void setup()
{
 pinMode (pinLedVermelho, OUTPUT);
 pinMode (pinLedAmarelo, OUTPUT);
 pinMode (pinLedVerde, OUTPUT); 
  
  Serial.begin (9600);
}

void loop()
{
 
  unsigned long tempoAtual = millis();
  
  if (tempoAtual - tempoInicial >= 1000)
  {
    faseSemaforo++;
    tempoInicial = tempoAtual;
    if(faseSemaforo == 10) faseSemaforo = 0;
    Serial.println(faseSemaforo);
  }
  
  switch (faseSemaforo)
  {

case 0: 

 digitalWrite(pinLedVermelho, HIGH);
 digitalWrite(pinLedAmarelo, LOW);
 digitalWrite(pinLedVerde, LOW);
break;

case 5:

digitalWrite(pinLedVermelho, LOW);
digitalWrite(pinLedAmarelo, LOW);
digitalWrite(pinLedVerde, HIGH);
break;
  

  case 8:

digitalWrite(pinLedVermelho, LOW);
digitalWrite(pinLedAmarelo, HIGH);
digitalWrite(pinLedVerde, LOW);
break;
  }

} 
 

  
  
  
