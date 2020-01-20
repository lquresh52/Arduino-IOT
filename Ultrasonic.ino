float t,d;
int trig=2,echo=3;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(100);
  digitalWrite(trig,HIGH);
  delayMicroseconds(50);
  digitalWrite(trig,LOW);
  t=pulseIn(echo,HIGH);
  t=t/2;
  d=0.0343*t;
  Serial.println(d);
  delay(100);
  

}
