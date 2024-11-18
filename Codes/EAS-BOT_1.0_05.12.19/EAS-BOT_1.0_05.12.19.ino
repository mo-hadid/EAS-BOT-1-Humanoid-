/*By Mohammed Essam HADID - HADIDTECH*/        /*--for EAS-BOT 1.0--*/

#include <Servo.h>
Servo RshoY, RshoX, RarmY, RarmX,
      LshoY, LshoX, LarmY, LarmX,
      RTF, RIF, RMF, RRF, RPF,
      LTF, LIF, LMF, LRF, LPF,
      HEADX, HEADY;
/*>>>>>>>>>>>>>>>Sensors<<<<<<<<<<<<<<<*/
#define FLAMES A0
const int threshold = 200;
int flamevalue;

#define FRONTS_ECHO A1
#define FRONT_TRIG A2
int frontdistance = 100;

#define BACKS_TRIG A3
#define BACKS_ECHO A4
int backdistance = 100;

#define HEATS A5
int heatvalue;
/*>>>>>>>>>>>>>>>Wheels<<<<<<<<<<<<<<<*/
const int ENA = 7;
const int IN1 = 6;
const int IN2 = 5;

const int ENB = 2;
const int IN3 = 4;
const int IN4 = 3;

#define maximumSpeed 250
/*>>>>>>>>>>>>>>>LEDs<<<<<<<<<<<<<<<*/
const int WHITE  = 8;
const int EYESG  = 9;
const int EYESB  = 10;
const int LYEL   = 11;
const int RYEL   = 12;
const int REDLED = 13;
const int LED7 = 52;
const int RGB_RED   = 35;
const int RGB_GREEN = 27;
const int RGB_BLUE = 25;
/*>>>>>>>>>>>>>>>Cooling Fan<<<<<<<<<<<<<<<*/
const int FAN = 36;

void setup() {
/*>>>>>>>>>>>>>>>Sensors<<<<<<<<<<<<<<<*/
  pinMode (FLAMES, INPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
/*>>>>>>>>>>>>>>>Wheels<<<<<<<<<<<<<<<*/
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
/*>>>>>>>>>>>>>>>Cooling Fan<<<<<<<<<<<<<<<*/
  pinMode (FAN, OUTPUT);
/*>>>>>>>>>>>>>>>Head<<<<<<<<<<<<<<<*/
                  HEADX.attach(37); //servo1
  HEADY.attach(39); //servo2
/*>>>>>>>>>>>>>>>ARM Joints<<<<<<<<<<<<<<<*/
  LshoY.attach(14); //servo3
                  RshoY.attach(15); //servo4
  LshoX.attach(16); //servo5
                  RshoX.attach(17); //servo6
  LarmY.attach(18); //servo7
                  RarmY.attach(19); //servo8
  LarmX.attach(20); //servo9
                  RarmX.attach(21); //servo10
/*>>>>>>>>>>>>>>>Fingers<<<<<<<<<<<<<<<*/
                  RTF.attach(24); //servo11
  LTF.attach(42); //servo12
                  RIF.attach(26); //servo13
  LIF.attach(44); //servo14
                  RMF.attach(28); //servo15
  LMF.attach(46); //servo16
                  RRF.attach(30); //servo17
  LRF.attach(48); //servo18
                  RPF.attach(34); //servo19
  LPF.attach(50); //servo20
/*>>>>>>>>>>>>>>>LEDs<<<<<<<<<<<<<<<*/
  pinMode (WHITE, OUTPUT);
  pinMode (EYESG, OUTPUT);
  pinMode (EYESB, OUTPUT);
  pinMode (LYEL, OUTPUT);
  pinMode (RYEL, OUTPUT);
  pinMode (REDLED, OUTPUT);
  pinMode (LED7, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0){
    delay(50);
    unsigned int X = Serial.read();
    unsigned int X1 = Serial.read();
    unsigned int A = (X1 * 256) + X;
    Serial.println(A);
    unsigned int realservo = (X1 * 256) + X;
    Serial.println(realservo);
    
    digitalWrite(REDLED,HIGH);
    if(A == 50501){ //DRIVE FORWARD
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);
       digitalWrite(REDLED,LOW);
    for(int motorSpeed = 0; motorSpeed < maximumSpeed; motorSpeed++){
       analogWrite(ENA, motorSpeed);
       analogWrite(ENB, motorSpeed);
    }
}
    else if(A == 50502){ //DRIVE BACKWARD
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, HIGH);
       digitalWrite(REDLED,LOW);
       digitalWrite(LYEL,LOW);
       digitalWrite(RYEL,LOW);
    for(int motorSpeed = 0; motorSpeed < maximumSpeed; motorSpeed++){
       analogWrite(ENA, motorSpeed);
       analogWrite(ENB, motorSpeed);
    }
}
    else if(A == 50503){ //TURN RIGHT
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, HIGH);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);
       digitalWrite(REDLED,LOW);
       digitalWrite(RYEL,HIGH);
       digitalWrite(LYEL,LOW);
    for(int motorSpeed = 0; motorSpeed < maximumSpeed; motorSpeed++){
       analogWrite(ENA, motorSpeed);
       analogWrite(ENB, motorSpeed);
    }
}
    else if(A == 50504){ //TURN LEFT
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, HIGH);
       digitalWrite(REDLED,LOW);
       digitalWrite(LYEL,HIGH);
       digitalWrite(RYEL,LOW);
    for(int motorSpeed = 0; motorSpeed < maximumSpeed; motorSpeed++){
       analogWrite(ENA, motorSpeed);
       analogWrite(ENB, motorSpeed);
    }
}
    else{
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       digitalWrite(REDLED,HIGH);
       digitalWrite(RYEL,LOW);
       digitalWrite(LYEL,LOW);
    }
/*>>>>>>>>>>>>>>>EYES<<<<<<<<<<<<<<<*/
    if(A == 50513){
       digitalWrite(EYESB, HIGH);
       digitalWrite(EYESG, LOW);
    }
    else if(A == 50512){
       digitalWrite(EYESG, HIGH);
       digitalWrite(EYESB, LOW);
     }
/*>>>>>>>>>>>>>>>LIGHTS<<<<<<<<<<<<<<<*/
    else if(A == 50515){
       digitalWrite(LED7, HIGH);
     }
    else if(A == 50514){
       digitalWrite(LED7, LOW);
     }
/*>>>>>>>>>>>>>>>RGB LIGHTS<<<<<<<<<<<<<<<*/
    else if(A == 50516){ //RED LIGHTS
       digitalWrite(RGB_RED, HIGH);
       digitalWrite(RGB_GREEN, LOW);
       digitalWrite(RGB_BLUE, LOW);
     }
     else if(A == 50517){ //GREEN LIGHTS
       digitalWrite(RGB_RED, LOW);
       digitalWrite(RGB_GREEN, HIGH);
       digitalWrite(RGB_BLUE, LOW);
     }
     else if(A == 50518){ //BLUE LIGHTS
       digitalWrite(RGB_RED, LOW);
       digitalWrite(RGB_GREEN, LOW);
       digitalWrite(RGB_BLUE, HIGH);
     }
     else if(A == 50519){ //YELLOW LIGHTS
       digitalWrite(RGB_RED, HIGH);
       digitalWrite(RGB_GREEN, HIGH);
       digitalWrite(RGB_BLUE, LOW);
     }
     else if(A == 50520){ //CYAN LIGHTS
       digitalWrite(RGB_RED, LOW);
       digitalWrite(RGB_GREEN, HIGH);
       digitalWrite(RGB_BLUE, HIGH);
     }
     else if(A == 50521){ //VIOLET LIGHTS
       digitalWrite(RGB_RED, HIGH);
       digitalWrite(RGB_GREEN, LOW);
       digitalWrite(RGB_BLUE, HIGH);
     }
     else if(A == 50522){ //WHITE LIGHTS
       digitalWrite(RGB_RED, HIGH);
       digitalWrite(RGB_GREEN, HIGH);
       digitalWrite(RGB_BLUE, HIGH);
     }
     else if(A == 50523){ //TURN ALL RGB OFF
       digitalWrite(RGB_RED, LOW);
       digitalWrite(RGB_GREEN, LOW);
       digitalWrite(RGB_BLUE, LOW);
     }
/*>>>>>>>>>>>>>>>Cooling Fan<<<<<<<<<<<<<<<*/
     else if(A == 50524){ //TURN FAN OFF
       digitalWrite(FAN, LOW);
     }
     else if(A == 50525){ //TURN FAN ON
       digitalWrite(FAN, HIGH);
     }
 //  X = "";
/*>>>>>>>>>>>>>>>ARM Joints<<<<<<<<<<<<<<<*/
    if (realservo >= 1000 && realservo < 1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      HEADX.write(servo1);
      delay(10);
    }
    if (realservo >= 2000 && realservo < 2180) {
      int servo2 = realservo;
      servo2 = map(servo2, 2000, 2180, 0, 180);
      HEADY.write(servo2);
      delay(10);
    }
    if (realservo >= 3000 && realservo < 3180) {
      int servo3 = realservo;
      servo3 = map(servo3, 3000, 3180, 0, 180);
      LshoY.write(servo3);
      delay(10);
    }
    if (realservo >= 4000 && realservo < 4180) {
      int servo4 = realservo;
      servo4 = map(servo4, 4000, 4180, 0, 180);
      RshoY.write(servo4);
      delay(10);
    }
    if (realservo >= 5000 && realservo < 5180) {
      int servo5 = realservo;
      servo5 = map(servo5, 5000, 5180, 0, 180);
      LshoX.write(servo5);
      delay(10);
    }
    if (realservo >= 6000 && realservo < 6180) {
      int servo6 = realservo;
      servo6 = map(servo6, 6000, 6180, 0, 180);
      RshoX.write(servo6);
      delay(10);
    }
    if (realservo >= 7000 && realservo < 7180) {
      int servo7 = realservo;
      servo7 = map(servo7, 7000, 7180, 0, 180);
      LarmY.write(servo7);
      delay(10);
    }
    if (realservo >= 8000 && realservo < 8180) {
      int servo8 = realservo;
      servo8 = map(servo8, 8000, 8180, 0, 180);
      RarmY.write(servo8);
      delay(10);
    }
    if (realservo >= 9000 && realservo < 9180) {
      int servo9 = realservo;
      servo9 = map(servo9, 9000, 9180, 0, 180);
      LarmX.write(servo9);
      delay(10);
    }
    if (realservo >= 10000 && realservo < 10180) {
      int servo10 = realservo;
      servo10 = map(servo10, 10000, 10180, 0, 180);
      RarmX.write(servo10);
      delay(10);
    }
/*>>>>>>>>>>>>>>>Fingers<<<<<<<<<<<<<<<*/
    if (realservo >= 11000 && realservo < 11180) {
      int servo11 = realservo;
      servo11 = map(servo11, 11000, 11180, 0, 180);
      RTF.write(servo11);
      delay(10);
    }
    if (realservo >= 12000 && realservo < 12180) {
      int servo12 = realservo;
      servo12 = map(servo12, 12000, 12180, 0, 180);
      LTF.write(servo12);
      delay(10);
    }
    if (realservo >= 13000 && realservo < 13180) {
      int servo13 = realservo;
      servo13 = map(servo13, 13000, 13180, 0, 180);
      RIF.write(servo13);
      delay(10);
    }
    if (realservo >= 14000 && realservo < 14180) {
      int servo14 = realservo;
      servo14 = map(servo14, 14000, 14180, 0, 180);
      LIF.write(servo14);
      delay(10);
    }
    if (realservo >= 15000 && realservo < 15180) {
      int servo15 = realservo;
      servo15 = map(servo15, 15000, 15180, 0, 180);
      RMF.write(servo15);
      delay(10);
    }
    if (realservo >= 16000 && realservo < 16180) {
      int servo16 = realservo;
      servo16 = map(servo16, 16000, 16180, 0, 180);
      LMF.write(servo16);
      delay(10);
    }
    if (realservo >= 17000 && realservo < 17180) {
      int servo17 = realservo;
      servo17 = map(servo17, 17000, 17180, 0, 180);
      RRF.write(servo17);
      delay(10);
    }
    if (realservo >= 18000 && realservo < 18180) {
      int servo18 = realservo;
      servo18 = map(servo18, 18000, 18180, 0, 180);
      LRF.write(servo18);
      delay(10);
    }
    if (realservo >= 19000 && realservo < 19180) {
      int servo19 = realservo;
      servo19 = map(servo19, 19000, 19180, 0, 180);
      RPF.write(servo19);
      delay(10);
    }
    if (realservo >= 20000 && realservo < 20180) {
      int servo20 = realservo;
      servo20 = map(servo20, 20000, 20180, 0, 180);
      LPF.write(servo20);
      delay(10);
    }
   }
/*>>>>>>>>>>>>>>>Sensors<<<<<<<<<<<<<<<*/
/* flamevalue = analogRead(FLAMES);
 // String flamemessage = "                                                                    FLAME Value: ";
 // Serial.println(flamemessage + flamevalue);
  if (flamevalue<1020) {
 //   Serial.print(911);
  }
 heatvalue = analogRead(HEATS);
 // String heatmessage = "                                                   HEAT Value: ";
 // Serial.println(heatmessage + heatvalue);
  if (heatvalue<1000)  {
 //   Serial.print(999);
  digitalWrite(FAN, HIGH);
  }
  else {
  digitalWrite(FAN, LOW);
  }*/
 }
