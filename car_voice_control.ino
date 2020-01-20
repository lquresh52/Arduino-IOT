#include<SoftwareSerial.h>
SoftwareSerial bt(10, 11); //rx,tx
String readvoice;
#define LS 2      // left sensor
#define RS 4      // right sensor
int MR_L1 = 3, MR_L2 = 5, MR_R1 = 6, MR_R2 = 9;
int a, b;
void setup() {
  Serial.begin(9600);
  bt.begin(38400);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(MR_R2, OUTPUT); //motor
  pinMode(MR_R1, OUTPUT); //motor
  pinMode(MR_L1, OUTPUT); //motor
  pinMode(MR_L2, OUTPUT); //motor
  pinMode(12, OUTPUT); //led lights
}

void loop() {
  while (bt.available()) {
    delay(10);
    char c = bt.read();
//    readvoice = bt.readString(); //build the string- "forward", "reverse", "left" and "right"
  readvoice +=c; 
  }
  a = digitalRead(LS);
  b = digitalRead(RS);

  if (readvoice.length() > 0)
  {
    Serial.println(readvoice);
  }

  if (readvoice.equals("forward")) {

    Serial.println("Moving forward ");
    motor_straight_run();
    //    delay(1000);

  }
  else if (readvoice.equals("back")) {

    Serial.println("Moving backworks ");
    reverse();

  }
  else if (readvoice.equals("left")) {

    Serial.println("Moving left ");
    left_turn();

  }
  else if (readvoice.equals("right")) {

    Serial.println("Moving right ");
    right_turn();

  }
  else if (readvoice.equals("stop")) {

    Serial.println("Stopped");
    bt_stop();

  }
  else if (readvoice.equals("Park")) {
    while (1)
    {
      a = digitalRead(LS);
      b = digitalRead(RS);
      if (a == 0 && b == 0)
      {
        //straight run
        motor_straight_run();
      } else if (a == 1 && b == 0)
      {
        //right
        right_turn2();
      } else if (a == 0 && b == 1) {
        //left
        left_turn1();
      } else if (a == 1 && b == 1) {
        //stop
        bt_stop();
        break;
      }
    }
  }
  readvoice = "";
}

void motor_straight_run()
{
  digitalWrite(MR_L1, 1);
  digitalWrite(MR_L2, 0);
  digitalWrite(MR_R1, 1);
  digitalWrite(MR_R2, 0);
  digitalWrite(12, 1);
}

void left_turn()
{
  digitalWrite(MR_L1, 150);
  digitalWrite(MR_L2, 0);
  digitalWrite(MR_R1, 0);
  digitalWrite(MR_R2, 150);
  digitalWrite(12, 1);
}

void right_turn()
{
  digitalWrite(MR_L1, 0);
  digitalWrite(MR_L2, 150);
  digitalWrite(MR_R1, 150);
  digitalWrite(MR_R2, 0);
  digitalWrite(12, 1);
}


void reverse()
{
  digitalWrite(MR_L1, 0);
  digitalWrite(MR_L2, 1);
  digitalWrite(MR_R1, 0);
  digitalWrite(MR_R2, 1);
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(12, 0);
    delay(1000);
    digitalWrite(12, 1);
    delay(1000);
  }
}


void bt_stop()
{
  digitalWrite(MR_L1, 0);
  digitalWrite(MR_L2, 0);
  digitalWrite(MR_R1, 0);
  digitalWrite(MR_R2, 0);
  digitalWrite(12, 0);
}

void left_turn1()
{
  digitalWrite(MR_L1, 0);
  digitalWrite(MR_L2, 150);
  digitalWrite(MR_R1, 150);
  digitalWrite(MR_R2, 0);
  digitalWrite(12, 1);
}

void right_turn2()
{
  analogWrite(MR_L1, 150);
  digitalWrite(MR_L2, 0);
  digitalWrite(MR_R1, 0);
  digitalWrite(MR_R2, 150);
  digitalWrite(12, 1);
}
