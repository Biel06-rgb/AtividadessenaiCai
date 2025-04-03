//Autor:Gabriel Araujo de Sousa
//Data:17/3/2025
//Ativideda: Aula- 39


#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

#define valorBotao 0 
#define valorBotao 145
#define valorBotao 329
#define valorBotao 505
#define valorBotao 741



void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  
  
  int leitura = analogRead(A0);
  Serial.println(leitura);
  
  
  lcd.setCursor(0,0);
 
    if(leitura == 1023)      
  lcd.print("Botao desativado");
  
  else if (leitura == 0)
  lcd.print("Botao 1 ativado");
    
 else if(leitura == 145)
  lcd.print("Botao 2 ativado");  
  
  else if(leitura == 329)
   lcd.print("Botao 3 ativado");
    
  else if(leitura == 505)
   lcd.print("Botao 4 ativado"); 
    
  else if(leitura == 741)
   lcd.print("Botao 5 ativado"); 
}