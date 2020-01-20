#include<Stepper.h>
#define STEPS 32
int val = 0;
Stepper stepper(STEPS, 8, 10, 9, 11);
void setup() {
  // put your setup code here, to run once:
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
  stepper.setSpeed(500);
}

void loop() {
  // put your main code here, to run repeatedly:
//    stepper.step(10000);
//    delay(20);
}


//
//
//#define STEPPER_PIN_1 9
//#define STEPPER_PIN_2 10
//#define STEPPER_PIN_3 11
//#define STEPPER_PIN_4 12
//int step_number = 0;
//void setup() {
//  pinMode(STEPPER_PIN_1, OUTPUT);
//  pinMode(STEPPER_PIN_2, OUTPUT);
//  pinMode(STEPPER_PIN_3, OUTPUT);
//  pinMode(STEPPER_PIN_4, OUTPUT);
//
//}
//
//void loop() {
//  for (int a = 0; a < 1000; a++)
//  {
//    OneStep(false);
//    delay(10);
//  }
//
//  for (int a = 0; a < 1000; a++)
//  {
//    OneStep(true);
//    delay(10);
//  }
//
//}
//
//
//void OneStep(bool dir) {
//  if (dir) {
//    switch (step_number) {
//      case 0:
//        digitalWrite(STEPPER_PIN_1, HIGH);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, LOW);
//        break;
//      case 1:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, HIGH);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, LOW);
//        break;
//      case 2:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, HIGH);
//        digitalWrite(STEPPER_PIN_4, LOW);
//        break;
//      case 3:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, HIGH);
//        break;
//    }
//  } else {
//    switch (step_number) {
//      case 0:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, HIGH);
//        break;
//      case 1:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, HIGH);
//        digitalWrite(STEPPER_PIN_4, LOW);
//        break;
//      case 2:
//        digitalWrite(STEPPER_PIN_1, LOW);
//        digitalWrite(STEPPER_PIN_2, HIGH);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, LOW);
//        break;
//      case 3:
//        digitalWrite(STEPPER_PIN_1, HIGH);
//        digitalWrite(STEPPER_PIN_2, LOW);
//        digitalWrite(STEPPER_PIN_3, LOW);
//        digitalWrite(STEPPER_PIN_4, LOW);
//
//
//    }
//  }
//  step_number++;
//  if (step_number > 3) {
//    step_number = 0;
//  }
//}
