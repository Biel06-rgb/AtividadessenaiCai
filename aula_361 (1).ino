
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int estadoAnterior = 0;
int estadopinLed = 0;
int estadoAtualBotao = 0;
#define pinBotao 2
#define pinLed 13


void setup()
{

  
 pinMode(pinLed, OUTPUT);
  pinMode(pinBotao, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop()
{

  bool estadoAtual = digitalRead(estadoAtualBotao);
  if (estadoAtual == 1 && estadoAnterior == 0)
  {
  estadopinLed = !estadopinLed;
  }
  digitalWrite(pinLed, estadopinLed);
  if(estadopinLed)
  {
  lcd.setCursor(0,0);
  lcd.print("ligado  ");    
  }    
 else
 {
   lcd.setCursor(0,0);
   lcd.print("desligado");
 }
  estadoAnterior = estadoAtual;
  
}