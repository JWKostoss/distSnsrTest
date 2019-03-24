#include <NewPing.h>

byte TRIGGER_PIN=5;
byte ECHO_PIN=3;
int MAX_DISTANCE=500;

byte dist=0;
int tyym=0;
byte count=0;
int far=10800; int mid=5400; int cls=3000; int stp=400;
byte red=127;
int tiem=0;
int dely=0;
int blnk=1;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);//    instance


void align(byte dig,int val){
  int ref=9999;
  switch(dig){
    case 5:ref/=1; break;
    case 4:ref/=10; break;
    case 3:ref/=100; break;
    case 2:ref/=1000; break;
    case 1:ref/=10000; break;}
  while(ref>0){
    if(val>ref)break;
    else{Serial.print(' '); ref/=10;}}
  Serial.print(val);
}

void mult(){
  while((tiem<300)&&(tiem>0)){
    blnk=300/(tyym+1);
    dely=50/blnk;
    for(int n=0; n<blnk; n++){
      delay(dely);
      if(red==127) red=0;
      else if(red==0) red=127;
      else break;
      analogWrite(9,red);}
    tyym=sonar.ping(); tiem=tyym-stp;
    Serial.print("             "); align(5,tyym);
    Serial.print("  "); align(4,dely);
    Serial.print("  "); align(5,blnk);
    Serial.println("");}
}

void sngl(){
  while((tyym<=cls)&&(tiem>=300)){
    //if(tiem>=1400) blnk=15;    else 
    blnk=tiem/(50*6);
    dely=50;
    for(int n=0; n<blnk; n++){
      delay(dely);
      tyym=sonar.ping(); tiem=tyym-stp;
      if(tyym>cls) break;
      //else if(tiem>=1400) blnk=15;      else 
      blnk=tiem/(50*6);
      analogWrite(9,red);
      Serial.print("             "); align(5,tyym);
      Serial.print("  "); align(1,blnk);
      Serial.println("");}
    if(red==127) red=0;
    else if(red==0) red=127;
    else break;}
}

void setup() {
  pinMode(9,OUTPUT);// RED
  pinMode(10,OUTPUT);//GRN
  pinMode(11,OUTPUT);//BLU
  digitalWrite(11,0);
  Serial.begin(115200);
}

void loop() {
  if(digitalRead(8)==0){
    delay(50);//                          Wait 50ms between pings
    if((count%2)==0){
      dist=sonar.ping_in(); tiem=tyym-stp;
      align(3,dist);
      if(dist==1)Serial.print(" inch  ");
      else Serial.print(" inches");}
    else if((count%2)==1){
      tyym=sonar.ping();//             NOTE: MICROSECONDS .00000X
      Serial.print("   "); align(5,tyym);
      Serial.println("");}
    else Serial.println("Eric says REEEEEEEEEEEEEEEEEEEEEEEEEE");
    if((tyym>mid)&&(tyym<=far)){
      analogWrite(9, 0);
      analogWrite(10, 127);}
    else if((tyym>cls)&&(tyym<=mid)){
      analogWrite(9, 119); analogWrite(10, 26);}
    else if((tyym>0)&&(tyym<=cls)){
      analogWrite(9, red);
      analogWrite(10, 0);
      if(tiem>=300) sngl();
      else if((tiem<300)&&(tiem>0)) mult();
      else analogWrite(9,red);
      red=127;}
    else{analogWrite(9,0); analogWrite(10,0);}
    count++;}
  else delay(50);
}
