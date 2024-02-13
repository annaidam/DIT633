// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 3
// Exercise 3.1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>

// set the pins in A0 and A1
int sensorPin = A0; // temperature sensor
int lightPin = A1; // light sensor
 
void setup()
{
  pinMode(sensorPin, INPUT); // temperature is input
  pinMode(lightPin, INPUT); // light is input
  Serial.begin(9600); // start serial
  
  pinMode(3, OUTPUT); // led in pin 3, blue
  pinMode(2, OUTPUT); // led in pin 2, red
  pinMode(4, OUTPUT); // led in pin 4, green
}
 
void loop()
{
  // the input from temperature sensor
  int reading = analogRead(sensorPin);
  // change the voltage of the input
  float voltage = reading * 4.68 / 1024.0;
  // turn the value into celsius
  float temperatureC = (voltage - 0.5) * 100;
  
  // print the temperature in celsius
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" degrees C");
  
  // map the value of lightPin to a percentage
  int lightPercentage = map(analogRead(lightPin), 0, 1023, 0, 100);

  // print the light in percentage
  Serial.print("Light Percentage: ");
  Serial.print(lightPercentage);
  Serial.println("%");
  
  // check if the temperature matches the correct light percentage
  if (temperatureC < -12) {
    if (lightPercentage == 0) {
      // turn on the correct led accordingly
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
    } else {
      digitalWrite(3, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
    }
  } else if ((temperatureC >= -12) && (temperatureC <= 0)) {
    if ((lightPercentage >= 1) && (lightPercentage <= 20)) {
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);
    } else if (lightPercentage < 1) {
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
    } else {
      digitalWrite(3, LOW);
      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
    }
  } else if ((temperatureC >= 0) && (temperatureC <= 20)) {
    if ((lightPercentage >= 21) && (