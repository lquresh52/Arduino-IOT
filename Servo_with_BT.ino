#include<SoftwareSerial.h>
#include<Servo.h>
SoftwareSerial bt(10, 11); //rx,tx
Servo obj;
char a;
void setup() {
  // put your setup code here, to run once:
  bt.begin(9600);
  obj.attach(7);
  Serial.begin(9600);
pinMode(8,OUTPUT);
digitalWrite(8,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = 'e';
  if (bt.available())
  {
    a = bt.read();
    if (a == 'O')
    {
      obj.write(0);
    }
    else if (a == 'C') {
    obj.write(90);
    }
//    else
//    {
//      a=' ';
//      }
      a=' ';
  }
}
