#define ZEROSHIFT   0
#define ONESHIFT    1
#define TWOSHIFT    2 

#define SENSORONE   5
#define SENSORTWO   6
#define SENSORTHREE 7


void setup() {
  
  Serial.begin(9600);
  pinMode(SENSORONE, INPUT);
  pinMode(SENSORTWO, INPUT);
  pinMode(SENSORTHREE, INPUT);

}

void loop() {

  int inputOne    = digitalRead(SENSORONE);
  int inputTwo    = digitalRead(SENSORTWO);
  int inputThree  = digitalRead(SENSORTHREE);

  int result      = (inputThree<<TWOSHIFT) | (inputTwo<<ONESHIFT) | (inputOne<<ZEROSHIFT); 

  
  Serial.print("O angulo está entre ");
  Serial.print(result * 45);
  Serial.print("° e ");
  Serial.print((result + 1) * 45);
  Serial.println("°"); 

}
