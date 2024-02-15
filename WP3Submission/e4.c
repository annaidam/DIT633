// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 3
// Exercise 4
// Submission code: XXXXXX (provided by your TA-s)

#include <Keypad.h>

// set the row and column pins
byte rowPins[4] = {11, 10, 9, 8};
byte columnPins[4] = {7, 6, 5, 4};

// create a matrix matching the keypad
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7','8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

// create a new keypad and map the rows and column pins accordingly
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, 4, 4);

void setup(){
  Serial.begin(9600); // start serial
}

void loop() {
  // get the current value of the key
  char keyValue = keypad.getKey();
  
  // if the key is pressed, print the value
  if (keyValue) {
    Serial.println(keyValue);
  }
}