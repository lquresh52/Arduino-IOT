#include<Servo.h>
Servo obj;
int ir=4;

void setup() {
  // put your setup code here, to run once:
obj.attach(7);
pinMode(ir,INPUT);
pinMode(5,OUTPUT);
digitalWrite(5,HIGH);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//obj.write(90);
int a=digitalRead(ir);
if(a==1){
  obj.write(60);
  Serial.println("60");
  }
  else{
    obj.write(180);
    Serial.println("180");
    }

}
