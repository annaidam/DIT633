// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 4
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)
#include <Adafruit_NeoPixel.h>

#define RED 8
#define LED_PIN 6
#define tempSensor A0

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 12

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


float temperature = 0;
float temperatureVoltage = 0;
int range = 10;


int delayval = 500;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(tempSensor, INPUT);
  
  Serial.begin(9600);
  
  strip.begin();
  strip.show();
  
  cli();
  
  //timer stuff for interupts 
  //credits:(https://www.youtube.com/watch?v=Uv9UeYUsA8A&ab_channel=Electronoobs)
  TCCR1A = 0; //reset entire control register A to 0
  TCCR1B = 0; //reset entire control register B to 0
  TCCR1B |= B00000100; //Set CS12 to 1 so we get prescalar 256
  
  TIMSK1 |= B00000010; //Set OCIE1A to 1 so we get compare match A
  
  OCR1A = 31250; //Finally we compare register A to this value
  sei();
  
}

void loop()
{
  
}

float getTemp()
{
  temperatureVoltage = analogRead(tempSensor)*5.0195;
  temperatureVoltage /= 1024.0;
  Serial.print("Voltage: ");
  Serial.println(temperatureVoltage);
  return (((temperatureVoltage-0.1)/(1.75-0.1))*165)-40;
}

ISR(TIMER1_COMPA_vect) {
  Serial.println("ISR");
  TCNT1 = 0;//set the Timer back to 0
  temperature = getTemp();
  Serial.print("temperature: ");
  Serial.println(temperature);
  
  if (temperature < 0) {
    Serial.print("freezing temps");
  }
  
  int numberOfLEDs = temperature / range;
  
  for (int i = 0; i < numberOfLEDs; i++) {
    strip.setPixelColor(i, 0, 255, 0);
  }	
  for (int i = numberOfLEDs; i < LED_COUNT; i++) {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
  
  if (numberOfLEDs >= LED_COUNT) {
    digitalWrite(RED, HIGH);
  } else {
    digitalWrite(RED, LOW);
  }
}
