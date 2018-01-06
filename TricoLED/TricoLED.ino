void setup() {
  // put your setup code here, to run once:
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int pot1 = analogRead(0);
int red = map(pot1, 0, 1023, 255, 0);
Serial.print(pot1);
Serial.print(' ');
Serial.println(red);
int pot2 = analogRead(1);
int gren = map(pot2, 0, 1023, 255, 0);
Serial.print(pot2);
Serial.print(' ');
Serial.println(gren);
int pot3 = analogRead(2);
int blu = map(pot3, 0, 1023, 255, 0);
Serial.print(pot3);
Serial.print(' ');
Serial.println(blu);
Serial.println("");

analogWrite(9, red);
analogWrite(10, gren);
analogWrite(11, blu);
}
