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
const int LED3 = 52;
/*>>>>>>>>>>>>>>>Cooling Fan<<<<<<<<<<<<<<<*/
const int FAN = 53;

String readString;

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
                  HEADX.attach(37);
  HEADY.attach(39);
/*>>>>>>>>>>>>>>>ARM Joints<<<<<<<<<<<<<<<*/
  LshoY.attach(14);
                  RshoY.attach(15);
  LshoX.attach(16);
                  RshoX.attach(17);
  LarmY.attach(18);
                  RarmY.attach(19);
  LarmX.attach(20);
                  RarmX.attach(21);
/*>>>>>>>>>>>>>>>Fingers<<<<<<<<<<<<<<<*/
                  RTF.attach(24);
  LTF.attach(42);
                  RIF.attach(26);
  LIF.attach(44);
                  RMF.attach(28);
  LMF.attach(46);
                  RRF.attach(30);
  LRF.attach(48);
                  RPF.attach(34);
  LPF.attach(50);
/*>>>>>>>>>>>>>>>LEDs<<<<<<<<<<<<<<<*/
  pinMode (WHITE, OUTPUT);
  pinMode (EYESG, OUTPUT);
  pinMode (EYESB, OUTPUT);
  pinMode (LYEL, OUTPUT);
  pinMode (RYEL, OUTPUT);
  pinMode (REDLED, OUTPUT);
  pinMode (LED3, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(EYESG,LOW);
  digitalWrite(EYESB,HIGH);
  delay(1000);
  digitalWrite(EYESB,LOW);
  digitalWrite(EYESG,HIGH);
  delay(1000);

  
  while(Serial.available()){
    delay(50);
    char c = Serial.read();
    long int s = Serial.read();
    readString+=c;
  }
  if(readString.length() > 0) {
    Serial.println(readString);
       digitalWrite(REDLED,HIGH);
    if(readString == "FRAD"){
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
    else if(readString == "BCWR"){
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
    else if(readString == "LF"){
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

    else if(readString == "RGT"){
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
    else{
       digitalWrite(IN1, LOW);
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       digitalWrite(REDLED,HIGH);
       digitalWrite(RYEL,LOW);
       digitalWrite(LYEL,LOW);
    }
    readString = "";


 while (Serial.available() >= 1000 ){
    unsigned int servopos = Serial.read();
    unsigned int servopos1 = Serial.read();
    unsigned int realservo = (servopos1 * 256) + servopos;
    Serial.println(realservo);

    if (realservo >= 1000 && realservo < 1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      HEADX.write(servo1);
      Serial.println("HEADX ON");
      delay(10);
    }
/*/////////////////////////////////////////////////
    if (readString >= 1000 && readString < 1180) {
      int servo1 = servodata;
      servo1 = map(servo1, 1000, 1180, 0, 180);
      HEADX.write(servo1);
      delay(10);
    }

    if (realservo >= 2000 && realservo < 1180) {
      int servo1 = realservo;
      servo1 = map(servo1, 2000, 2180, 0, 180);
      HEADX.write(servo1);
      delay(10);
    }
    if (realservo >= 3000 && realservo < 3180) {
      int servo1 = realservo;
      servo1 = map(servo1, 3000, 3180, 0, 180);
      HEADY.write(servo1);
      delay(10);
    }
    if (realservo >= 4000 && realservo < 4180) {
      int servo1 = realservo;
      servo1 = map(servo1, 4000, 4180, 0, 180);
      LshoY.write(servo1);
      delay(10);
    }
    if (realservo >= 5000 && realservo < 5180) {
      int servo1 = realservo;
      servo1 = map(servo1, 5000, 5180, 0, 180);
      RshoY.write(servo1);
      delay(10);
    }
    if (realservo >= 6000 && realservo < 6180) {
      int servo1 = realservo;
      servo1 = map(servo1, 6000, 6180, 0, 180);
      LshoX.write(servo1);
      delay(10);
    }
    if (realservo >= 7000 && realservo < 7180) {
      int servo1 = realservo;
      servo1 = map(servo1, 7000, 7180, 0, 180);
      RshoX.write(servo1);
      delay(10);
    }
    if (realservo >= 8000 && realservo < 8180) {
      int servo1 = realservo;
      servo1 = map(servo1, 8000, 8180, 0, 180);
      LarmY.write(servo1);
      delay(10);
    }
    if (realservo >= 9000 && realservo < 9180) {
      int servo1 = realservo;
      servo1 = map(servo1, 9000, 9180, 0, 180);
      RarmY.write(servo1);
      delay(10);
    }
    if (realservo >= 10000 && realservo < 10180) {
      int servo1 = realservo;
      servo1 = map(servo1, 10000, 10180, 0, 180);
      LarmX.write(servo1);
      delay(10);
    }
    if (realservo >= 11000 && realservo < 11180) {
      int servo1 = realservo;
      servo1 = map(servo1, 11000, 11180, 0, 180);
      RarmX.write(servo1);
      delay(10);
    }
    if (realservo >= 12000 && realservo < 12180) {
      int servo1 = realservo;
      servo1 = map(servo1, 12000, 12180, 0, 180);
      RTF.write(servo1);
      delay(10);
    }
    if (realservo >= 13000 && realservo < 13180) {
      int servo1 = realservo;
      servo1 = map(servo1, 13000, 13180, 0, 180);
      LTF.write(servo1);
      delay(10);
    }
    if (realservo >= 14000 && realservo < 14180) {
      int servo1 = realservo;
      servo1 = map(servo1, 14000, 14180, 0, 180);
      RIF.write(servo1);
      delay(10);
    }
    if (realservo >= 15000 && realservo < 15180) {
      int servo1 = realservo;
      servo1 = map(servo1, 15000, 15180, 0, 180);
      LIF.write(servo1);
      delay(10);
    }
    if (realservo >= 16000 && realservo < 16180) {
      int servo1 = realservo;
      servo1 = map(servo1, 16000, 16180, 0, 180);
      RMF.write(servo1);
      delay(10);
    }
    if (realservo >= 17000 && realservo < 17180) {
      int servo1 = realservo;
      servo1 = map(servo1, 17000, 17180, 0, 180);
      LMF.write(servo1);
      delay(10);
    }
    if (realservo >= 18000 && realservo < 18180) {
      int servo1 = realservo;
      servo1 = map(servo1, 18000, 18180, 0, 180);
      RRF.write(servo1);
      delay(10);
    }
    if (realservo >= 19000 && realservo < 19180) {
      int servo1 = realservo;
      servo1 = map(servo1, 19000, 19180, 0, 180);
      LRF.write(servo1);
      delay(10);
    }
    if (realservo >= 20000 && realservo < 20180) {
      int servo1 = realservo;
      servo1 = map(servo1, 20000, 20180, 0, 180);
      RPF.write(servo1);
      delay(10);
    }
    if (realservo >= 21000 && realservo < 21180) {
      int servo1 = realservo;
      servo1 = map(servo1, 21000, 21180, 0, 180);
      LPF.write(servo1);
      delay(10);
    }*/
/////////////////////////////////////////////////*/

/*>>>>>>>>>>>>>>>Sensors<<<<<<<<<<<<<<<*/
 String space = " ";
 flamevalue = analogRead(FLAMES);
  String flamemessage = "                                                                    FLAME Value: ";
  Serial.println(flamemessage + flamevalue);
  if (flamevalue<1017) {
    Serial.print(FLAMES);
  digitalWrite(REDLED, HIGH);
  }
  else {
  digitalWrite(REDLED, LOW);
  }
 heatvalue = analogRead(HEATS);
  String heatmessage = "                                                   HEAT Value: ";
  Serial.println(heatmessage + heatvalue);
  if (heatvalue<1000)  {
    Serial.print(FLAMES);
  digitalWrite(FAN, HIGH);
  }
  else {
  digitalWrite(FAN, LOW);
  }
 }
  }}
