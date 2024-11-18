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

void setup() {
  pinMode(WHITE, OUTPUT);
  pinMode(EYESG, OUTPUT);
  pinMode(EYESB, OUTPUT);
  pinMode(LYEL, OUTPUT);
  pinMode(RYEL, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(RGB_RED, OUTPUT);
  pinMode(RGB_GREEN, OUTPUT);
  pinMode(RGB_BLUE, OUTPUT);
}

void loop() {
/////////////////////////RED LED + RGB BLUE LIGHTS
  digitalWrite(REDLED, HIGH);
  digitalWrite(RGB_RED, LOW);
  digitalWrite(RGB_GREEN, LOW);
  digitalWrite(RGB_BLUE, HIGH);
  delay(500);
  digitalWrite(REDLED, LOW);
  digitalWrite(RGB_RED, LOW);
  digitalWrite(RGB_GREEN, LOW);
  digitalWrite(RGB_BLUE, LOW);
  delay(500);
/////////////////////////RIGHT YELLOW LED + RGB RED LIGHTS
  digitalWrite(RYEL, HIGH);
  digitalWrite(RGB_RED, HIGH);
  digitalWrite(RGB_GREEN, LOW);
  digitalWrite(RGB_BLUE, LOW);
  delay(500);
  digitalWrite(RYEL, LOW);
  digitalWrite(RGB_RED, LOW);
  digitalWrite(RGB_GREEN, LOW);
  digitalWrite(RGB_BLUE, LOW);
  delay(500);
/////////////////////////LEFT YELLOW LED + RGB GREEN LIGHTS
  digitalWrite(LYEL, HIGH);
  digitalWrite(RGB_RED, LOW);
  digitalWrite(RGB_GREEN, HIGH);
  digitalWrite(RGB_BLUE, LOW);
  delay(500);
  digitalWrite(LYEL, LOW);
  digitalWrite(RGB_RED, LOW);
  digitalWrite(RGB_GREEN, LOW);
  digitalWrite(RGB_BLUE, LOW);
  delay(500);
/////////////////////////EYES BLUE LED + RGB CYAN LIGHTS
  digitalWrite(EYESB, HIGH);
  digitalWrite(RGB_RED, LOW);
  digitalWrite(RGB_GREEN, HIGH);
  digitalWrite(RGB_BLUE, HIGH);
  delay(500);
  digitalWrite(EYESB, LOW);
  digitalWrite(RGB_RED, LOW);
  digitalWrite(RGB_GREEN, LOW);
  digitalWrite(RGB_BLUE, LOW);
  delay(500);
/////////////////////////EYES GREEN LED + RGB VIOLET LIGHTS
  digitalWrite(EYESG, HIGH);
  digitalWrite(RGB_RED, HIGH);
  digitalWrite(RGB_GREEN, LOW);
  digitalWrite(RGB_BLUE, HIGH);
  delay(500);
  digitalWrite(EYESG, LOW);
  digitalWrite(RGB_RED, LOW);
  digitalWrite(RGB_GREEN, LOW);
  digitalWrite(RGB_BLUE, LOW);
  delay(500);
/////////////////////////WHITE LED + RGB YELLOW LIGHTS
  digitalWrite(WHITE, HIGH);
  digitalWrite(RGB_RED, HIGH);
  digitalWrite(RGB_GREEN, HIGH);
  digitalWrite(RGB_BLUE, LOW);
  delay(500);
  digitalWrite(WHITE, LOW);
  digitalWrite(RGB_RED,LOW);
  digitalWrite(RGB_GREEN, LOW);
  digitalWrite(RGB_BLUE, LOW);
  delay(500);
  
  digitalWrite(LED7, HIGH);
  digitalWrite(RGB_RED, HIGH);
  digitalWrite(RGB_GREEN, HIGH);
  digitalWrite(RGB_BLUE, HIGH);
  delay(500);
  digitalWrite(LED7, LOW);
  digitalWrite(RGB_RED, LOW);
  digitalWrite(RGB_GREEN, LOW);
  digitalWrite(RGB_BLUE, LOW);
  delay(500);
}
