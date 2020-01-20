#include<Servo.h>
Servo obj;
void setup() {
  // put your setup code here, to run once:
  obj.attach(7);
//  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for (int i = 0; i < 180; i++)
//  {
//    obj.write(i);
//    delay(i);
//  }
obj.write(0);

}
