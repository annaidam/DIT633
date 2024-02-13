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
  buttonState = digitalRead(2); // read from pin