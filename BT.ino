#include<SoftwareSerial.h>
SoftwareSerial bt(10, 11); //rx,tx
char a;

int MR_L1 = 3, MR_L2 = 5, MR_R1 = 6, MR_R2 = 9,trig=2,echo=4;

void motor_straight_run()
{
  digitalWrite(MR_L1, 1);
  digitalWrite(MR_L2, 0);
  digitalWrite(MR_R1, 1);
  digitalWrite(MR_R2, 0);

}

void left_turn()
{
  digitalWrite(MR_L1, 1);
  digitalWrite(MR_L2, 1);
  digitalWrite(MR_R1, 1);
  digitalWrite(MR_R2, 0);

}

void right_turn()
{
  digitalWrite(MR_L1, 1);
  digitalWrite(MR_L2, 0);
  digitalWrite(MR_R1, 0);
  digitalWrite(MR_R2, 0);

}


void reverse()
{
  digitalWrite(MR_L1, 0);
  digitalWrite(MR_L2, 1);
  digitalWrite(MR_R1, 0);
  digitalWrite(MR_R2, 1);

}


void bt_stop()
{
  digitalWrite(MR_L1, 0);
  digitalWrite(MR_L2, 0);
  digitalWrite(MR_R1, 0);
  digitalWrite(MR_R2, 0);
}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bt.begin(38400);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(MR_R2, OUTPUT); //motor
  pinMode(MR_R1, OUTPUT); //motor
  pinMode(MR_L1, OUTPUT); //motor
  pinMode(MR_L2, OUTPUT); //motor

}

void loop() {
  // put your main code here, to run repeatedly:
  //    if (Serial.available())
  //    {
  //      bt.write(Serial.read());
  //    }
  //

    a = 'e';
  if (bt.available())
  {
    a = bt.read();

    if (a == 'U') {
      Serial.println("Moving forward ");
      motor_straight_run();
      delay(1000);

    }
    else if (a == 'D') {
      Serial.println("Moving downword ");
      reverse();

    }
    else if (a == 'L') {
      Serial.println("Moving left ");
      left_turn();

    }
    else if (a == 'R') {
      Serial.println("Moving right ");
      right_turn();

    }
    else if (a == 'S') {
      Serial.println("Stop");
      bt_stop();

    }
    else
    {
      bt_stop();
    }
  }
//  else
//  {
//    bt_stop();
//  }




}
