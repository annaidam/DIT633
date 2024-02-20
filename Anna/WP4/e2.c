// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 4
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

#include <Adafruit_NeoPixel.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define PIN 2

Adafruit_NeoPixel ring = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

// define pin for temperature sensor
const int temperaturePin = A0;

void setup() {
  ring.begin(); // start ring
  pinMode(temperaturePin, INPUT); // temperature sensor to input
  pinMode(9, OUTPUT); // extra led to output
  Serial.begin(9600); // start serial

  // set up Timer1 for regular interrupts
  cli(); // disable interrupts
  TCCR1A = 0; // set TCCR1A register to 0
  TCCR1B = 0; // set TCCR1B register to 0
  TCNT1 = 0; // initialise counter value to 0
  OCR1A = 15624; // set the compare value
  TCCR1B |= (1 << WGM12); // configure timer in CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10); // set prescaler to 1024
  TIMSK1 |= (1 << OCIE1A); // enable Timer1 compare A interrupt
  sei(); // enable interrupts
}

// main loop gets the temperature and lights up the leds
void loop() {
  float temperature = getTemperature();
  updateLEDs(temperature);
  delay(1000);
}

// function to light up the leds
void updateLEDs(float temp) {
  // first turn off all leds
  clearLights();

  // when temperature is less than -20
  if (temp < (-20)) {
    // light up one light
    ring.setPixelColor(0, 255, 0, 0);
    ring.show();
    // else if the temperature is between -20 and 90
  } else if (temp >= (-20) && temp < 90) {
    int numPixelsToLight = map(temp, -20, 90, 0, ring.numPixels());
    // check for the temperature and lit up leds one by one based on the value
    for (int i = 0; i < numPixelsToLight; i++) {
      ring.setPixelColor(i, 255, 0, 0);
    }
    ring.show();
    // else if the temperature is above 89
  } else if (temp >= 90) {
    // light up the extra led
    digitalWrite(9, HIGH);
  }
}

// function to turn off all the leds
void clearLights() {
  // go through one by one and turn all off
  for (int i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, 0, 0, 0);
  }
  // turn extra led off as well
  digitalWrite(9, LOW);
  ring.show();
}

ISR(TIMER1_COMPA_vect) {}

// function to get the temperature and print it in celsius
float getTemperature() {
  int reading = analogRead(temperaturePin);
  float voltage = reading * 4.68 / 1024.0;
  float temperatureC = (voltage - 0.5) * 100;

  Serial.print("temp: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  return temperatureC;
}
