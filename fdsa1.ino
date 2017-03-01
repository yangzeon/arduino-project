//doumaobang.ino
#include<Servo.h>
Servo Servo1;
Servo Servo2;
int pot1, pot2;
int s1 = 9;
int s2 = 10;
int led1 = 7;
int tou1 = 5;

void setup() {
	Servo1.attach(s1);
 	Servo2.attach(s2);
 	Servo1.write(90);
 	Servo2.write(90);
 	pinMode(led1, OUTPUT);
 	pinMode(tou1, INPUT);
}

void loop() {
	if(tou1 == LOW){
	  digitalWrite(led1, HIGH);
	  pot1 = analogRead(0);
	  pot2 = analogRead(1);
	  pot1 = map(pot1, 0, 1023, 0, 180);
	  pot2 = map(pot2, 0, 1023, 5, 180);
	  Servo1.write(pot1);
	  Servo2.write(pot2);
	  delay(15);
	}
    if(tou1 == HIGH)        
    {
    	digitalWrite(led1, LOW);
 		Servo1.write(80);
 		delay(100);
 		Servo2.write(100);
 		delay(100);
    }
}
