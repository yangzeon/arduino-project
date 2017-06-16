#include <Servo.h>
Servo Servo1;
Servo Servo2;

int s1 = 6;
int s2 = 7;
int yanchi = 15;
int bot1=8;
int bot2=9;
int bot3=10;
int bot4=11;
int bot5=12;

int Received=0;
int bot1_state =0;
int bot2_state = 0;
int bot3_state = 0;


void setup(){
  
  Serial.begin(9600);
  pinMode(bot4,OUTPUT);
  pinMode(bot2,OUTPUT);
  pinMode(bot1,OUTPUT);
  pinMode(bot3,OUTPUT);
  
}

void loop(){
 
 if(Serial.available()>0)
 { 
    Received = Serial.read();
    
 }
////////////////bot1/////////////////////
if (bot1_state == 0 && Received == '1')
  {
    digitalWrite(bot1,HIGH);
    bot1_state=1;
    Received=0;  
  }
if (bot1_state ==1 && Received == '1')
  {
    digitalWrite(bot1,LOW);
    bot1_state=0;
    Received=0;
  }
///////////////////////////////////////////



////////////////bot2/////////////////////
if (bot2_state == 0 && Received == 'a')
  {
    digitalWrite(bot2,HIGH);
    bot2_state=1;
    Received=0;  
  }
if (bot2_state ==1 && Received == 'a')
  {
    digitalWrite(bot2,LOW);
    bot2_state=0;
    Received=0;
  }
///////////////////////////////////////////




////////////////bot3/////////////////////
if (bot3_state == 0 && Received == '2')
  {
    digitalWrite(bot3,HIGH);
    bot3_state=1;
    Received=0;  
  }
if (bot3_state ==1 && Received == '2')
  {
    digitalWrite(bot3,LOW);
    bot3_state=0;
    Received=0;
  }
///////////////////////////////////////////




  
////////////////bot4/////////////////////
 if (Received =='8'){
   digitalWrite(bot4,HIGH);   
  }  
 if (Received == '9'){
 digitalWrite(bot4,LOW);
 }
 ///////////////////////////////////////////

 
 
}

