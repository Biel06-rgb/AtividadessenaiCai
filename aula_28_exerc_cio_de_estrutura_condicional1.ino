//Autor:Gabriel Araujo de Sousa
//Data:26/02/2025
//Descricao:Exerciocio de estrutura condicional




void setup()
{
 Serial.begin(9600);
  
  int peso = 64;
  int altura = 1.77;
  float resultado = 0;
  

  resultado = peso / sq(altura);
  Serial.print("A divisao desses valores eh: ");
  Serial.println(resultado);
  
  
  
  if(resultado < 18.5){
  Serial.println("Abaixo do peso normal");
  }else if(resultado >= 18.5 && resultado <= 24.9){
  Serial.print("Peso normal");
  }else if(resultado >= 25.0 && resultado <= 29.9){
  Serial.print("Excesso de peso");
  }else if(resultado >= 30.0 && resultado <= 34.9){
  Serial.print("Obsidade classe 1");
  }else if(resultado >=35.5 && resultado <= 39.9){
   Serial.print("Obsidade classe 2"); 
  }else{
  Serial.println("Obsidade classe 3")
  }
    
  
  
}

void loop()
{

}