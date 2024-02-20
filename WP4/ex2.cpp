// C++ code
//
/*
  Sweep

  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

int pos = 180;
int count = 0;
Servo servo_11;

void setup()
{
  Serial.begin(9600);
  servo_11.attach(11);
  setupTimer();
}

void loop()
{

}

void setupTimer()//this creates a timer that calls an interupt every 16ms
{
  cli();
  
  //timer stuff for interupts 
  //credits:(https://www.youtube.com/watch?v=Uv9UeYUsA8A&ab_channel=Electronoobs)
  TCCR2A = 0; //reset entire control register A to 0
  TCCR2B = 0; //reset entire control register B to 0
  TCCR2B |= B00000111; //Set CS22, CS21, and CS20 to 1 so we get prescalar 1024
  
  TIMSK2 |= B00000010; //Set OCIE1A to 1 so we get compare match A
  
  OCR2A = 249; //Finally we compare register A to this value
  sei();
}

void turnServo() {
  pos = pos - 3;
  servo_11.write(pos);
  Serial.println("turned 1 degree");
}
  
ISR(TIMER2_COMPA_vect) {
  TCNT2 = 0;
  count++;
  float time = count*16;
  time /= 1000;
  Serial.print("seconds: ");
  Serial.println(time);
  if (count%62 == 0|| count %63 == 0) {
    pos = (count / 62)*2;
    Serial.println("1 turn");
  }
}
