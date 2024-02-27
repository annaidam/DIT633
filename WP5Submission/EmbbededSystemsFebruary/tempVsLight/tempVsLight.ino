// C++ code
//
#include <DHT.h>

float temperatureValue;
int lightValue;
float lightVoltage;
int GREEN = 12;
int YELLOW = 10;
int RED = 9;
int tempSensorPin = 5;
int lightSensorPin = 1;
unsigned long previousMillis = 0;
const long interval = 1000;
DHT dht(tempSensorPin, DHT11);


void setup()
{
  
  Serial.begin(9600);
  
  //input
  //pinMode(tempSensorPin, INPUT);
  //pinMode(lightSensorPin, INPUT);
  
  //LEDs
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);

  dht.begin();
}

void loop()
{
  unsigned long currentMillis = millis();
  int OnLED;
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
	  recordAnalog();
    compare();
  }
}

void recordAnalog() {
  //0.055-4V
  lightVoltage = analogRead(lightSensorPin)*5.0195;
  lightVoltage /= 1024.0;
  
  //Celsius
  temperatureValue = dht.readTemperature();
  //%
  lightValue = ((lightVoltage-0.055)/(4-0.055))*100*1;
  
  Serial.print("Temperature (C): ");
  Serial.println(temperatureValue);
  Serial.print("Light (%): ");
  Serial.println(lightValue);
}

int compare() {
  int light;
  int temperature;
  
  if (temperatureValue <= -12) {
    temperature = 1;
  } else if (temperatureValue > -12 && temperatureValue <= 0) {
    temperature = 2;
  } else if (temperatureValue > 0 && temperatureValue <= 20) {
    temperature = 3;
  } else if (temperatureValue >= 21) {
    temperature = 4;
  } else {
    return 0;
  }
  
  if (lightValue < 1) {
    light = 1;
  } else if (lightValue >= 1 && lightValue <= 20) {
    light = 2;
  } else if (lightValue >= 21 && lightValue <= 60) {
    light = 3;
  } else if (lightValue >= 61) {
    light = 4;
  } else {
    return 0;
  }
  
  Serial.print("Temperature condition: ");
  Serial.println(temperature);
  Serial.print("Light condition: ");
  Serial.println(light);
  
  if (light == temperature) {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
  } else if (light > temperature) {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
  } else if (light < temperature) {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
  } else {
    return 0;
  }
}
  