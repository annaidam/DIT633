// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 3
// Exercise 3.2
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>

// set the row pins and column pins
byte rowPins[4] = {11, 10, 9, 8};
byte columnPins[4] = {7, 6, 5, 4};

// create a matrix matching the keypad
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7','8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void setup(){
  Serial.begin(9600); // start serial
  
  for (int i = 0; i < 4; i++) {
    pinMode(rowPins[i], OUTPUT); // set the row pins to output
    pinMode(columnPins[i], INPUT); // set the column pins to input
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(rowPins[i], LOW); // set all row pins low
    
    for (int j = 0; j < 4; j++) {
      // check if the column pins are low at the same time the row pins are low
      if (digitalRead(columnPins[j]) == LOW) {
        // if yes, print the key
        Serial.println(keys[i][j]);
        // delay for 0.5 seconds
        delay(500);
      }
    }
    // set the row pins back to high
    digitalWrite(rowPins[i], HIGH);
  }
}