#define dirFrente 6
#define dirTras   5
#define esqFrente 10
#define esqTras   11

#define DIRSPEED 80
#define ESQSPEED 95

#define FRENTE  1
#define PARADO  0
#define TRAS   -1

#define TRIG_PIN 8
#define ECHO_PIN 9

#define MIN_DISTANCE 20

float duration, distance;

float read_distance(){

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  return (duration*.0343)/2;
}

void configMotor() {
  pinMode(dirFrente,  OUTPUT);
  pinMode(dirTras,    OUTPUT);
  pinMode(esqFrente,  OUTPUT);
  pinMode(esqTras,    OUTPUT);

  digitalWrite(dirFrente,  LOW);
  digitalWrite(dirTras,    LOW);
  digitalWrite(esqFrente,  LOW);
  digitalWrite(esqTras,    LOW);
}

void motorEsq(int direcao, byte velocidade = 85) {
  switch (direcao) {
    case -1: {
        //        Serial.println("Esq Trás");
        digitalWrite(esqFrente,  LOW);
        analogWrite (esqTras,    velocidade);
        break;
      }
    case 0: {
        //        Serial.println("Esq PARADOdo");
        digitalWrite(esqFrente,  HIGH);
        digitalWrite(esqTras,    HIGH);
        break;
      }
    case 1: {
        //        Serial.println("Esq Frente");
        analogWrite (esqFrente,  velocidade);
        digitalWrite(esqTras,    LOW);
        break;
      }
  }
}

void motorDir(int direcao, byte velocidade = 90) {
  switch (direcao) {
    case -1: {
        //        Serial.println("Dir Trás");
        digitalWrite(dirFrente,  LOW);
        analogWrite (dirTras,    velocidade);
        break;
      }
    case 0: {
        //        Serial.println("Dir PARADOdo");
        digitalWrite(dirFrente,  HIGH);
        digitalWrite(dirTras,    HIGH);
        break;
      }
    case 1: {
        //        Serial.println("Dir Frente");
        analogWrite (dirFrente,  velocidade);
        digitalWrite(dirTras,    LOW);
        break;
      }
  }
}

void direcaoTras(){
  motorEsq(TRAS);
   motorDir(TRAS);
}

void direcaoFrente(){
  motorEsq(FRENTE);
  motorDir(FRENTE);
}

void direcaoDireita(){
  motorEsq(FRENTE);
  motorDir(TRAS);
}

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  distance = read_distance();
  if(distance<=MIN_DISTANCE) { //distancia menor que 40 cm
  direcaoTras();
  delay(700);
  direcaoDireita();
  delay(200);
  } else {
    direcaoFrente();
  }

  delay(100);

}

