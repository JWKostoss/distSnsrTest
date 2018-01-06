/*--------------------------------------------------------------
Example NewPing library sketch that does a ping about 20 Hz
---------------------------------------------------------------*/
#include <NewPing.h>

int TRIGGER_PIN=5;    // trigger pin
int ECHO_PIN=3;       // echo pin
int MAX_DISTANCE=500; // Maximum distance(in inches).
//                        rated 157.48-196.85 in.

int dist=0;
int tyym=0;
int count=0;

void align(int dig,int val){
  int ref=9999;
  switch(dig){
    case 5:ref/=1; break;
    case 4:ref/=10; break;
    case 3:ref/=100; break;
    case 2:ref/=1000; break;
    case 1:ref/=10000; break;}
  while(ref>0){
    if(val>ref)break;
    else Serial.print(' '); ref/=10;}
  Serial.print(val);
}

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
// NewPing setup of pins and maximum distance. AN INSTANCE

void setup() {
  pinMode(13,OUTPUT);
  digitalWrite(13,0);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(115200); // Open serial monitor at 115200 baud
}

void loop() {
  //while((millis()%50)!=0)continue;  
  delay(50); // Wait 50ms between pings
  //            (about 20 pings/sec). 29ms be the shortest delay.
  if((count%2)==0){
    //Serial.print("Ping: ");// NO.
    dist=sonar.ping_in(); // Send ping, get distance in inch
    align(3,dist); //        and print result
    //      (0=outside set distance range) (but maybe just zero.)
    if(dist==1)Serial.print(" inch  ");
    else Serial.print(" inches");}
  else if((count%2)==1){
    tyym=sonar.ping();
    Serial.print("   "); align(4,tyym);
    Serial.println("");}
  else Serial.println("Eric says REEEEEEEEEEEEEEEEEEEEEEEEEEEE");
  if(tyym > 6 && tyym <= 10){
    digitalWrite(9, 1);
    digitalWrite(10, 0);
    digitalWrite(11, 0);}
  else if(tyym > 4 && tyym <= 6){
    digitalWrite(9, 1);
    digitalWrite(10, 0);
    digitalWrite(11, 1);}
  else if(tyym > 0 && tyym <= 4);{
    digitalWrite(9, 0);
    digitalWrite(10, 0);
    digitalWrite(11, 1);}
/*  else{
    digitalWrite(9,0);
    digitalWrite(10,1);
    digitalWrite(11,0);}*/
  count++;
}
