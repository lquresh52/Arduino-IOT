/*------ Arduino Line Follower Code----- */
/*-------definning Inputs------*/
#define LS 2      // left sensor
#define RS 4      // right sensor

/*-------definning Outputs------*/
#define LM1 3       // left motor
#define LM2 5       // left motor
#define RM1 6       // right motor
#define RM2 9       // right motor
int a, b;
void setup()
{
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
   
  a = digitalRead(LS); //left
  b = digitalRead(RS); //right
  if (digitalRead(LS) && digitalRead(RS))    // Move Forward
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    Serial.println(a);
//    delay(2000);
    Serial.println(b);
//  delay(2000);
  }

  if (!(digitalRead(LS)) && digitalRead(RS))    // Turn right
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    Serial.println(a);
//    delay(2000);
    Serial.println(b);
//  delay(2000);
  }

  if (digitalRead(LS) && !(digitalRead(RS)))    // turn left
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    Serial.println(a);
//    delay(2000);
    Serial.println(b);
//  delay(2000);
  }

  if (!(digitalRead(LS)) && !(digitalRead(RS)))    // stop
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
     Serial.println(a);
//    delay(2000);
    Serial.println(b);
//  delay(2000);
  }
}
