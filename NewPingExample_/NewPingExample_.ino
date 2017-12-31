/*--------------------------------------------------------------
Example NewPing library sketch that does a ping about 20 Hz
---------------------------------------------------------------*/
#include <NewPing.h>

#define TRIGGER_PIN  9   // trigger pin
#define ECHO_PIN     11  // echo pin
#define MAX_DISTANCE 200 // Maximum distance(in inches).
//                          rated 157.48-196.85 in.

int dist=0;
int tiem=0;
int count=0;

void align(int dig, int val){
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
  Serial.begin(115200); // Open serial monitor at 115200 baud
}

void loop() {
  delay(50);  // Wait 50ms between pings
  //            (about 20 pings/sec). 29ms be the shortest delay.
  if((count%2)==0){
    //Serial.print("Ping: ");// NO.
    dist=sonar.ping_in(); // Send ping, get distance in inch
    align(3,dist); // and print result
    //      (0=outside set distance range) (but maybe just zero.)
    if(dist==1)Serial.print(" inch");
    else Serial.print(" inches");}
  else if((count%2)==1){
    tiem=sonar.ping();
    Serial.print(' '); align(4,tiem);
    Serial.println("");}
  else Serial.println("WAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
  count++;
}
