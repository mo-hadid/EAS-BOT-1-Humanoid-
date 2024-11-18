#include <Servo.h>

Servo RshoY, RshoX, RarmY, RarmX,
      LshoY, LshoX, LarmY, LarmX,
      RTF, RIF, RMF, RRF, RPF,
      LTF, LIF, LMF, LRF, LPF,
      HEADX, HEADY;

int pos1 = 0;
int pos2 = 90;
int pos3 = 0;
int pos4 = 90;
int pos5 = 0;
int pos6 = 90;
int pos7 = 0;
int pos8 = 90;
int pos9 = 0;
int pos10 = 90;
int pos11 = 0;
int pos12 = 90;
int pos13 = 0;
int pos14 = 90;
int pos15 = 0;
int pos16 = 90;
int pos17 = 0;
int pos18 = 90;
int pos19 = 0;
int pos20 = 90;

void setup() {
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
}

void loop() {
  for (pos1 = 0; pos1 <= 180; pos1 += 1) {
    HEADX.write(pos1);
  }
//------------------------------------------
  for (pos2 = 0; pos2 <= 180; pos2 += 1) {
    HEADY.write(pos2);
  }
//------------------------------------------
  for (pos3 = 0; pos3 <= 180; pos3 += 1) {
    LshoY.write(pos3);
  }
//------------------------------------------
  for (pos4 = 0; pos4 <= 180; pos4 += 1) {
    RshoY.write(pos4);
  }
//------------------------------------------
  for (pos5 = 0; pos5 <= 180; pos5 += 1) {
    LshoX.write(pos5);
  }
//------------------------------------------
  for (pos6 = 0; pos6 <= 180; pos6 += 1) {
    RshoX.write(pos6);
  }
//------------------------------------------
  for (pos7 = 0; pos7 <= 180; pos7 += 1) {
    LarmY.write(pos7);
  }
//------------------------------------------
  for (pos8 = 0; pos8 <= 180; pos8 += 1) {
    RarmY.write(pos8);
  }
//------------------------------------------
  for (pos9 = 0; pos9 <= 180; pos9 += 1) {
    LarmX.write(pos9);
  }
//------------------------------------------
  for (pos10 = 0; pos10 <= 180; pos10 += 1) {
    RarmX.write(pos10);
  }
//------------------------------------------
  for (pos11 = 0; pos11 <= 180; pos11 += 1) {
    RTF.write(pos2);
  }
//------------------------------------------
  for (pos12 = 0; pos12 <= 180; pos12 += 1) {
    LTF.write(pos12);
  }
//------------------------------------------
  for (pos13 = 0; pos13 <= 180; pos13 += 1) {
    RIF.write(pos13);
  }
//------------------------------------------
  for (pos14 = 0; pos14 <= 180; pos14 += 1) {
    LIF.write(pos14);
  }
//------------------------------------------
  for (pos15 = 0; pos15 <= 180; pos15 += 1) {
    RMF.write(pos15);
  }
//------------------------------------------
  for (pos16 = 0; pos16 <= 180; pos16 += 1) {
    LMF.write(pos16);
  }
//------------------------------------------
  for (pos17 = 0; pos17 <= 180; pos17 += 1) {
    RRF.write(pos17);
  }
//------------------------------------------
  for (pos18 = 0; pos18 <= 180; pos18 += 1) {
    LRF.write(pos18);
  }
//------------------------------------------
  for (pos19 = 0; pos19 <= 180; pos19 += 1) {
    RPF.write(pos19);
  }
//------------------------------------------
  for (pos20 = 0; pos20 <= 180; pos20 += 1) {
    LPF.write(pos20);
  }
 delay(1000);

//------------------------------------------
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) {
    HEADX.write(pos1);
  }
//------------------------------------------
  for (pos2 = 180; pos2 >= 0; pos2 -= 1) {
    HEADY.write(pos2);
  }
//------------------------------------------
  for (pos3 = 180; pos3 >= 0; pos3 -= 1) {
    LshoY.write(pos3);
  }
//------------------------------------------
  for (pos4 = 180; pos4 >= 0; pos4 -= 1) {
    RshoY.write(pos4);
  }
//------------------------------------------
  for (pos5 = 180; pos5 >= 0; pos5 -= 1) {
    LshoX.write(pos5);
  }
//------------------------------------------
  for (pos6 = 180; pos6 >= 0; pos6 -= 1) {
    RshoX.write(pos6);
  }
//------------------------------------------
  for (pos7 = 180; pos7 >= 0; pos7 -= 1) {
    LarmY.write(pos7);;
  }
//------------------------------------------
  for (pos8 = 180; pos8 >= 0; pos8 -= 1) {
    RarmY.write(pos8);
  }
//------------------------------------------
  for (pos9 = 180; pos9 >= 0; pos9 -= 1) {
    LarmX.write(pos2);
  }
//------------------------------------------
  for (pos10 = 180; pos10 >= 0; pos10 -= 1) {
    RarmX.write(pos10);
  }
//------------------------------------------
  for (pos11 = 180; pos11 >= 0; pos11 -= 1) {
    RTF.write(pos11);
  }
//------------------------------------------
  for (pos12 = 180; pos12 >= 0; pos12 -= 1) {
    LTF.write(pos12);
  }
//------------------------------------------
  for (pos13 = 180; pos13 >= 0; pos13 -= 1) {
    RIF.write(pos13);
  }
//------------------------------------------
  for (pos14 = 180; pos14 >= 0; pos14 -= 1) {
    LIF.write(pos14);
  }
//------------------------------------------
  for (pos15 = 180; pos15 >= 0; pos15 -= 1) {
    RMF.write(pos15);
  }
//------------------------------------------
  for (pos16 = 180; pos16 >= 0; pos16 -= 1) {
    LMF.write(pos16);
  }
//------------------------------------------
  for (pos17 = 180; pos17 >= 0; pos17 -= 1) {
    RRF.write(pos17);
  }
//------------------------------------------
  for (pos18 = 180; pos18 >= 0; pos18 -= 1) {
    LRF.write(pos18);
  }
//------------------------------------------
  for (pos19 = 180; pos19 >= 0; pos19 -= 1) {
    RPF.write(pos19);
  }
//------------------------------------------
  for (pos20 = 180; pos20 >= 0; pos20 -= 1) {
    LPF.write(pos20);
  }
 }
