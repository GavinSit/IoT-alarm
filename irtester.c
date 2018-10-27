#include <stdio.h>
#include <wiringPi.h>

int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);

   while(1) {
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1);
    printf("Waiting for event\n");
    Alarm(1);
    while(digitalRead(0) == 0);
    Alarm(0);
    printf("Alarm\n");
  }
  /*NOTREACHED*/
  return 0 ;
}

void Alarm(int state){
  if (state == 1){ /*alarm is ready*/
    digitalWrite(1, HIGH);
    digitalWrite(2,LOW);
  }else if (state == 0){ /* alarm is ringing */
    digitalWrite(2, HIGH);
    digitalWrite(1, LOW);
  }
}
