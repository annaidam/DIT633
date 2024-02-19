// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 4
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>

int sensorPin = A0;

const int min = 0;
const int low = 10;
const int mid = 20;
const int high = 30;
const int max = 35;
 
void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  
  pinMode(3, OUTPUT); // < 0
  pinMode(4, OUTPUT); // 0-10
  pinMode(5, OUTPUT); // 11-20
  pinMode(6, OUTPUT); // 21-30
  pinMode(7, OUTPUT); // > 35
}
 
void loop() {
  int reading = analogRead(sensorPin);
  float voltage = reading * 4.68 / 1024.0;
  float temperatureC = (voltage - 0.5) * 100;
  
  Serial.print("Temperature is ");
  Serial.print(temperatureC);
  Serial.println(" degrees Celsius");
  
  if (temperatureC < min) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  } else if (temperatureC >= min && temperatureC <= low) {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  } else if (temperatureC > low && temperatureC <= mid) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  } else if (temperatureC > mid && temperatureC <= high) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  } else if (temperatureC > max) {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
  
  delay(1000);
}
