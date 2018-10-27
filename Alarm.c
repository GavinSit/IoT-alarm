#include <stdio.h>
#include <wiringPi.h>

wiringPiSetup();
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);

void alarm(int state){
  if (state == 1) { /*alarm is waiting */
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
  }else if (state == 0){ /*alarm is running */
    digitalWrite(2, HIGH);
    digitalWrite(1, LOW); 
}
