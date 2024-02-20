// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 4
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

// define pin for temperature sensor
const int temperaturePin = A0;

// variable to store temperature value
volatile int temperature = 0;

// variables for the different ranges
const int min = -20;
const int low = 0;
const int mid = 20;
const int high = 60;
const int max = 100;
 
void setup() {
  pinMode(temperaturePin, INPUT);
  Serial.begin(9600);
  
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  
  // Set up Timer1 for regular interrupts
  cli(); // Disable interrupts
  TCCR1A = 0; // Set TCCR1A register to 0
  TCCR1B = 0; // Set TCCR1B register to 0
  TCNT1 = 0; // Initialize counter value to 0
  OCR1A = 15624; // Set the compare value (1s at 16MHz)
  TCCR1B |= (1 << WGM12); // Configure timer in CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10); // Set prescaler to 1024
  TIMSK1 |= (1 << OCIE1A); // Enable Timer1 compare A interrupt
  sei(); // Enable interrupts
}
 
void loop() {
  // convert temperature to celsius
  int reading = analogRead(temperaturePin);
  float voltage = reading * 4.68 / 1024.0;
  float temperatureC = (voltage - 0.5) * 100;
  
  // print temperature in celsius
  Serial.print("temp: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  
  // light up the correct LEDs by calling the function
  updateLEDs(temperatureC);
  
  delay(1000);
}

ISR(TIMER1_COMPA_vect) {
  int reading = analogRead(temperaturePin);
  float voltage = reading * 4.68 / 1024.0;
  float temperatureC = (voltage - 0.5) * 100;

  Serial.print("temp: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  updateLEDs(temperatureC);
}

void updateLEDs(float temp) {
  // Turn off all LEDs initially
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  // determine the temperature range and turn on the corresponding LED
  if (temp < low) {
    digitalWrite(3, HIGH); // LED for temperature < -20
    delay(500);
  } else if (temp < mid && temp > low) {
    digitalWrite(4, HIGH); // LED for temperature -20-0
    delay(500);
  } else if (temp < high && temp > mid) {
    digitalWrite(5, HIGH); // LED for temperature 0-20
    delay(500);
  } else if (temp < max && temp > high) {
    digitalWrite(6, HIGH); // LED for temperature > 20-60
    delay(500);
  } else {
    digitalWrite(7, HIGH); // LED for temperature > 100
    delay(500);
  }
}
