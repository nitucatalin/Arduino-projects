//led rgb
int led_R = 11;
int led_G = 10;
int led_B = 9;

//senzori linie
int L = A4;
int R = A6;
int C = A5;

//ultrasonic
const int trig = 8;
const int echo = 7;

//L298N
int ENA = 6;
int IN1 = A0;
int IN2 = A1;
int ENB = 5;
int IN3 = A2;
int IN4 = A3;

void setup() {
  //declarare pini led
  pinMode(led_R,OUTPUT);
  pinMode(led_G,OUTPUT);
  pinMode(led_B,OUTPUT);

  //declarare pini senzor ultrasonic
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  //declarare pini senzori linie
  pinMode(L,INPUT);
  pinMode(R,INPUT);
  pinMode(C,INPUT);

  //declarare pini L298N
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  
  //extragem datele din senzorii de linie
  int SL = analogRead(L);
  int SR = analogRead(R);
  int SC = analogRead(C);

  //initializam ultrasonicul
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;  // Calcularea distanței 

  if((SL == HIGH && SR == HIGH) && !(distance >= 20 && distance < 50)) {
      inainte();
      analogWrite(led_R, 0);
      analogWrite(led_B, 0);
      analogWrite(led_G, 255);
      
  } else {
      stop();
      analogWrite(led_G, 0);
      analogWrite(led_R, 255);
      analogWrite(led_B, 0);
    }


  
}
void inainte() {
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite (ENA, 500);
  analogWrite (ENB, 500);
}
void stop() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}