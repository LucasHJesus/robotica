#include <Servo.h>
#define pinoServo 6
Servo servo;
int value;

void writeValue(int value)
{
      Serial.print(" | ");
      Serial.println(value);
      Serial.print("Servo posicionado em ");
      Serial.print(value);
      Serial.println(" graus");

}

void setup() 
{
  servo.attach(pinoServo);
  Serial.begin(9600);
  while(!Serial);

  delay(1000);
  Serial.println("Digite o grau de movimento e tecle enter...");
}

void loop() 
{
  if (Serial.available())
  {
    value = Serial.parseInt();
    if( value >= 0 && value <= 180)
    {
      writeValue(value);
      servo.write(value);
      delay(5000);
    }
    else Serial.println("Insira um angulo valido");
  }
}
