//doumaobang.ino
#include<Servo.h>
Servo Servo1;
Servo Servo2;
int pot1, pot2, pot3;
int s1 = 9;
int s2 = 10;
int yanchi = 15;
#define led 8
#define but1 12
#define but2 13
int valbut1 =0;
int valbut2 =0;
int old_valbut1 = 0;
int old_valbut2 = 0;
int ledstate= 1;
int servos = 0;
int zuoyou = 550;

void setup() {
  Servo1.attach(s1);
  Servo2.attach(s2);
  Servo1.write(90);
  Servo2.write(90);
  pinMode(led, OUTPUT);
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);

}

void loop() {
  valbut1 = digitalRead(but1);
  valbut2 = digitalRead(but2);
    if((valbut2 == HIGH)&&(old_valbut2 == LOW)){
      servos = 1 - servos;
      delay(100);
    }
    old_valbut2 = valbut2;
    if(servos == 1){
    pot1 = analogRead(0);
    pot2 = analogRead(1);
    pot1 = map(pot1, 0, 1023, 70, 110);
    pot2 = map(pot2, 0, 1023, 70, 110); 
    Servo1.write(pot1);
    Servo2.write(pot2);
    delay(yanchi); 
    }
    else
    {
        for(int pot3= 80; pot3 <=100 ; pot3 += 2){
            Servo1.write(pot3);
            delay(200);
	      	Servo2.write(84);
	      	delay(zuoyou);
	      	Servo2.write(96);
	      	delay(zuoyou); 
	        }
            delay(100);
        for(int pot3=100; pot3 >= 80; pot3 -= 2){
            Servo1.write(pot3);
            delay(200);
      		Servo2.write(84);
      		delay(zuoyou);
      		Servo2.write(96);
      		delay(zuoyou); 
        	} 
        	delay(100);
    }
    if((valbut1 == HIGH)&&(old_valbut1 == LOW)){
        ledstate = 1 - ledstate;
        delay(40);
    }
    old_valbut1 = valbut1;
    if(ledstate == 1){
        digitalWrite(led, HIGH);
    }
    else{digitalWrite(led, LOW);}
 }