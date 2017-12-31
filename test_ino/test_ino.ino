void setup() {
  // put your setup code here, to run once:
  pinMode(10,INPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(10)==1)digitalWrite(13,1);
}
