int IR_L = 7, IR_R = 8, MR_L1 = 3, MR_L2 = 5, MR_R1 = 6, MR_R2 = 9;
void IR_read()
{
  int a, b;
  a = digitalRead(IR_L); //left
  b = digitalRead(IR_R); //right
  if (a == 0 && b == 0)
  {
    motor_straight_run();
  }
  else if (a == 1 && b == 0)
  {
//  motor_correct_write
  }
}

void motor_straight_run()
{
  digitalWrite(MR_L1, 1);
  digitalWrite(MR_L2, 0);
  digitalWrite(MR_R1, 1);
  digitalWrite(MR_R2, 0);
  
}

void setup() {
  // put your setup code here, to run once:
  pinMode(IR_L, INPUT); //IR
  pinMode(IR_R, INPUT); //IR
  pinMode(MR_R2, OUTPUT); //motor
  pinMode(MR_R1, OUTPUT); //motor
  pinMode(MR_L1, OUTPUT); //motor
  pinMode(MR_L2, OUTPUT); //motor

}


void loop() {
  IR_read();

}
