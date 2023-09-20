#include <Servo.h>
#define pinoServo 6
Servo servo1;
int value = 0;
int pass = -1;

void setup() 
{
  servo1.attach(pinoServo);
  Serial.begin(9600);
  while(!Serial);

  delay(1000);
  Serial.println("Digite o grau de movimento e tecle enter...");
  value = 0;
  pass = -1;
  
}

void loop() 
{
  if (value == 180) pass = -1;
  if (value == 0) pass = 1;

  servo1.write(value);
  Serial.println(value);

  value += pass;

  delay(500);

}
