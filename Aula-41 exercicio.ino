//Autor:Gabriel Araujo de Sousa
//Data:17/3/2025
//Atividade: Aula- 42


#include <LiquidCrystal_I2C.h>

//***** INSTANCIAS DE OBJETOS ****
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define valorBotao1 0 
#define valorBotao2 145
#define valorBotao3 329
#define valorBotao4 505
#define valorBotao5 741
#define valorSolto 1023
#define pinLedA 11
#define pinLedB 10 

//**VARIAVEIS GLOBAIS***

void setup()
{
  lcd.init(); // inicia o lcd
  lcd.backlight(); // liga a luz de fundo do lcd
  lcd.setCursor(0,0);
  lcd.print(">LED A OFF");
  lcd.setCursor(1,1);
  lcd.print(" LED B ON");
  pinMode(pinLedA, OUTPUT);
  pinMode(pinLedB, OUTPUT);
  
  
}

void loop()
{

  int valorLeituraAnalogica = analogRead(A0);
  static int valorAnterior = 1023;
  static bool posicao = 0;
  static bool estadoLedA = 0;
  static bool estadoLedB = 0;
  static bool atualizacao = 0;
 
   //***** TRATAMENTO DOS BOTOES *******
  // NENHUM BOTAO
  if (valorLeituraAnalogica == valorSolto)
    
  {
  
  
  
  }
  
  
   //BOTAO 1 APERTADO
     else if(valorLeituraAnalogica == valorBotao1 &&
             valorAnterior == valorSolto)
     {
     
     posicao = 0;
     atualizacao = 1;  
     
     }
  
  
     //BOTAO 2 PRESSIONADO
      else if(valorLeituraAnalogica >= valorBotao2 * 0.9  &&
      valorLeituraAnalogica <= valorBotao2 * 1.1 &&
       valorAnterior == valorSolto)
        
      {
      
      posicao = 1;
      atualizacao = 1;
        
      }   

  //BOTAO 3 PRESSIONADO
  else if (valorLeituraAnalogica >= valorBotao3 * 0.9 &&
           valorLeituraAnalogica <= valorBotao3 * 1.1 &&
           valorAnterior == valorSolto)
    
  {
    posicao = 2;
  
  }
  
  
  //BOTAO 4 PRESSIONADO 
  
  else if (valorLeituraAnalogica >= valorBotao4 * 0.9 &&
           valorLeituraAnalogica <= valorBotao4 * 1.1 &&
           valorAnterior == valorSolto)
    
  {
 
    
  }
  
  //BOTAO 5 PRESSIONADO 
  else if (valorLeituraAnalogica >= valorBotao5 * 0.9 &&
           valorLeituraAnalogica <= valorBotao5 * 1.1 &&
           valorAnterior == valorSolto)
  {
 
   atualizacao = 0;
   if (posicao == 0)  
  
  estadoLedA = !estadoLedA;
    
  else
  
  estadoLedB = !estadoLedB;
  
    
  }
 
  
 valorAnterior = valorLeituraAnalogica;
  
  //****** FIM DO TRATAMENTO DOS BOTOES ******
  
  if(atualizacao == 1)       
  {
  // ***** ATUALIZA DISPLAY ******
  if(posicao == 0) //setinha na linha de cima  
  {
  lcd.setCursor(0,0);
  lcd.print(">");
  lcd.setCursor(0,1);
  lcd.print(" ");  
  } 
    
  else
      
 {  
 lcd.setCursor(0,1);
 lcd.print(">");
 lcd.setCursor(0,0);
 lcd.print(" ");
 }
    
 // MUDA O TEXTO DO LED A
  lcd.setCursor(7,0);
    
  if (estadoLedA == 0)
  lcd.print(" OFF ");
    
  else
  lcd.print(" ON ");
    
  //MUDA O TEXTO DO LED B
  lcd.setCursor(7,1); 
    
  if(estadoLedB == 0)
   lcd.print(" OFF "); 
    
  else
      
 lcd.print(" ON ");
    
  //***** ATUALIZACAO DOS LED ******
  digitalWrite(pinLedA, estadoLedA);
  digitalWrite(pinLedB, estadoLedB); 
    
   atualizacao = 0;
     
  }      
      
    
}