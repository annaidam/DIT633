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
  {'*', '0', '#',