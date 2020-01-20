#include<SoftwareSerial.h>
SoftwareSerial bt(10, 11); //rx,tx
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
bt.begin(38400);
pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0)
  {
    bt.write(Serial.read());
  }
if (bt.available() > 0)
  {
    Serial.write(bt.read());
  }
}


//addr of slave 2016:10:84012
