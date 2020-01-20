#include<Stepper.h>
#include<SoftwareSerial.h>
SoftwareSerial bt(6, 12); //rx,tx
#define STEPS 32
int val = 0;
int trig = 2, echo = 4;
float d, t;
int flag=0;
Stepper stepper(STEPS, 8, 9, 10, 11);
void setup() {
  
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);//7- pin vcc
  digitalWrite(3, HIGH); //3 - pin vcc
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);//5- pin gnd
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  stepper.setSpeed(500);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trig, LOW);
  delayMicroseconds(100);
  digitalWrite(trig, HIGH);
  delayMicroseconds(50);
  digitalWrite(trig, LOW);
  delay(5000);
  t = pulseIn(echo, HIGH);
  t = t / 2;
  d = 0.0343 * t;
  Serial.println(d);
// if(flag==0)
// {
//  if (d<30)
//  {
    stepper.step(9000);
    delay(200000);
    flag=1;
//  }
//  }
  

}
