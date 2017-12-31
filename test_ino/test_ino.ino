void setup() {
  // put your setup code here, to run once:
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(10)==HIGH){
    digitalWrite(13,1);
    while(digitalRead(10)==HIGH){
      digitalWrite(11,1); digitalWrite(11,0);}}
  else digitalWrite(13,0);
}
