#include<SoftwareSerial.h>
SoftwareSerial bt(10, 11);

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  pinMode(12,OUTPUT);
  digitalWrite(12,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
//  if (Serial.available() > 0)
//  {
//    bt.write(Serial.read());
//  }
  if (bt.available() > 0)
  {
    Serial.write(bt.read());
  }
}


//AT+name for name
//AT+pswd for password
//AT+uart for cheeking baud rate
