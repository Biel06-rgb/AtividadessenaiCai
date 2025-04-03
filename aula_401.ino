//Autor:Gabriel Araujo de Sousa
//Data:17/3/2025
//Ativideda: Aula- 40


#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

#define Botao1 0 
#define Botao2 145
#define Botao3 329
#define Botao4 505
#define Botao5 741



void setup()
{
  
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  int Botao = analogRead(A0);
  
  if (Botao == Botao1){
  lcd.setCursor(0, 0);
  lcd.print(">");
  lcd.setCursor(0, 1);
   lcd.print("   "); 
  
  
  }

 
  if(Botao >= Botao2 * 0.9 && Botao <= Botao2 * 1.1){
  lcd.setCursor(0, 1);
  lcd.print(">");
  lcd.setCursor(0, 0);
  lcd.print("   ");
  
  }
  
  
}