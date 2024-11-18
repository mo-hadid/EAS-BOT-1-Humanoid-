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

void setup() {
  Serial.begin(9600);
}

void loop() {

 String space = " ";
 flamevalue = analogRead(FLAMES);
  String flamemessage = "                                                                    FLAME Value: ";
  Serial.println(flamemessage + flamevalue);
  if (flamevalue<1020) {
    Serial.print(FLAMES);
/*}  digitalWrite(REDLED, HIGH);
  else {
  digitalWrite(REDLED, LOW);*/
  }
 heatvalue = analogRead(HEATS);
  String heatmessage = "                                                   HEAT Value: ";
  Serial.println(heatmessage + heatvalue);
  if (heatvalue<1000)  {
    Serial.print(FLAMES);
/*}  digitalWrite(FAN, HIGH);
  else {
  digitalWrite(FAN, LOW);*/
 }
}
