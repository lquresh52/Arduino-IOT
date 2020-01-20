int trig = 2, echo = 4,MR_L1 = 3, MR_L2 = 5, MR_R1 = 6, MR_R2 = 9;
float d, t;
void motor_straight_run()
{
  digitalWrite(MR_L1, 1);
  digitalWrite(MR_L2, 0);
  digitalWrite(MR_R1, 1);
  digitalWrite(MR_R2, 0);

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
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(100);
  digitalWrite(trig, HIGH);
  delayMicroseconds(50);
  digitalWrite(trig, LOW);
  t = pulseIn(echo, HIGH);
  t = t / 2;
  d = 0.0343 * t;
  if (d > 30)
  {
    motor_straight_run();
  } else
  {
    bt_stop();
  }

}
