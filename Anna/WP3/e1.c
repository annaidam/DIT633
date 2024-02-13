// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 3
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>

// set the buttonState to 0
int buttonState = 0;

void setup()
{
  pinMode(2, INPUT); // input pin
  pinMode(13, OUTPUT); // output pin
  pinMode(3, OUTPUT); // output pin
}

void loop()
{
  buttonState = digitalRead(2); // read from pin 2 i.e. the input pin

  // check if the state of the button is HIGH i.e. if the button is pressed
  if (buttonState == HIGH) {
    digitalWrite(13, HIGH); // when button is pressed set the led in pin 13 on
  } else {
    digitalWrite(13, LOW); // otherwise set led in pin 13 off
  }

  digitalWrite(3, HIGH); // the led in pin 3 should be on
  delay(1000); // stay on for 1 second
  digitalWrite(3, LOW); // then turn off
  delay(1000); // and stay off for 1 second
}