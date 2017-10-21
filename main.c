//Autor: FILIPEFLOP
 
//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>
#include <Servo.h>

const int botao = 8;

int estadoBotao = 0;


#define SERVO 6

 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

Servo s;
Servo d;// Variável Servo
int pos;


int num = 1 ;
 
void setup()
{
  pinMode(botao,INPUT);
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0);
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
}
 
void loop(){
  
    //Limpa a tela
    lcd.clear();
    //Posiciona o cursor na coluna 3, linha 0;
    lcd.setCursor(1, 0);
    //Envia o texto entre aspas para o LCD
    lcd.print("ESTACIONAMENTO");
    if(num == 0){
      lcd.setCursor(4, 1);
      lcd.print("SEM VAGAS");
      }
     else{
      lcd.setCursor(4, 1);
      lcd.print("VAGAS: ");
      lcd.print(num);
      
     }
    delay(500);
    if(num == 0){
      lcd.setCursor(4, 1);
      lcd.print("SEM VAGAS");
      
      }
  
    if(num > 0){
      estadoBotao = digitalRead(botao);
      if( estadoBotao == HIGH){  
        for(pos = 0; pos < 90; pos++)
        {
          s.write(pos);
        delay(10);
        }
        delay(3000);
        for(pos = 90; pos >= 0; pos--)
        {
          s.write(pos);
          delay(10);
        }
        num--;
      }
      Serial.println(estadoBotao);
  }

}
