/*>>>>>>>>>>>>>>>Wheels<<<<<<<<<<<<<<<*/
const int ENA = 7;
const int IN1 = 6;
const int IN2 = 5;

const int ENB = 2;
const int IN3 = 4;
const int IN4 = 3;

#define maximumSpeed 250
/*>>>>>>>>>>>>>>>Cooling Fan<<<<<<<<<<<<<<<*/
const int FAN = 36;

void setup() {
/*>>>>>>>>>>>>>>>Wheels<<<<<<<<<<<<<<<*/
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
/*>>>>>>>>>>>>>>>Cooling Fan<<<<<<<<<<<<<<<*/
  pinMode (FAN, OUTPUT);
}

void loop() {
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);               digitalWrite(FAN, HIGH);
    for(int motorSpeed = 0; motorSpeed < maximumSpeed; motorSpeed++){
       analogWrite(ENA, motorSpeed);
       analogWrite(ENB, motorSpeed);}
delay(4000);
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);               digitalWrite(FAN, LOW);
delay(1000);
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, HIGH);               digitalWrite(FAN, HIGH);
    for(int motorSpeed = 0; motorSpeed < maximumSpeed; motorSpeed++){
       analogWrite(ENA, motorSpeed);
       analogWrite(ENB, motorSpeed);}
delay(4000);
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);               digitalWrite(FAN, HIGH);
delay(1000);
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, HIGH);              digitalWrite(FAN, LOW);
    for(int motorSpeed = 0; motorSpeed < maximumSpeed; motorSpeed++){
       analogWrite(ENA, motorSpeed);
       analogWrite(ENB, motorSpeed);}
delay(4000);
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);               digitalWrite(FAN, HIGH);
delay(1000);
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);
    for(int motorSpeed = 0; motorSpeed < maximumSpeed; motorSpeed++){
       analogWrite(ENA, motorSpeed);
       analogWrite(ENB, motorSpeed);}
delay(4000);
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);               digitalWrite(FAN, LOW);
delay(1000);
}
