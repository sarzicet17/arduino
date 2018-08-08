#include <TimerOne.h>
const int BZ = 3;

void buzar(){
  static boolean output = HIGH;
  digitalWrite(BZ,output);
  output = !output;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(BZ,OUTPUT);
  Timer1.initialize(1140);
  Timer1.attachInterrupt(buzar);
}

void loop() {
  // put your main code here, to run repeatedly:
}
