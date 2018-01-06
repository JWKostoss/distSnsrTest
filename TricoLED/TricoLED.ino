void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
//  Serial.begin(9600);
}

void loop() {
  int pot1 = analogRead(0);
  int red = map(pot1, 0, 1023, 255, 0);
//  Serial.print(pot1); Serial.print(' ');
//  Serial.print(red); Serial.print(' ');
  int pot2 = analogRead(1);
  int grn = map(pot2, 0, 1023, 255, 0);
//  Serial.print(pot2); Serial.print(' ');
//  Serial.print(grn); Serial.print(' ');
  int pot3 = analogRead(2);
  int blu = map(pot3, 0, 1023, 255, 0);
//  Serial.print(pot3); Serial.print(' ');
//  Serial.println(blu); Serial.println("");
  analogWrite(9, red);
  analogWrite(10, grn);
  analogWrite(11, blu);
}
