int a;
void setup() {
  // put your setup code here, to run once:
//pinMode(7,INPUT);
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
a=analogRead(A0);
Serial.println(a);
if(a>=90){
    digitalWrite(13,HIGH);
    Serial.println("JALA");
}else{
  digitalWrite(13,LOW);
  Serial.println("BUJA");  
}
}
