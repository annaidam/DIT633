// (C) Anna Mäkinen, David Schön, Milena Maćkowiak, group: 3 (2024)
// Work package 3
// Exercise 6
// Submission code: 9IL6WF (provided by your TA-s)

// C++ code
//

int buttonState = 0;
unsigned long previousMillis = 0; // stores last time LED was updated
const long interval = 1000; // interval at which to blink (milliseconds)

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }

  // Check if it's time to blink
  if (currentMillis - previousMillis >= interval) {
    // save the last time the LED blinked
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa
    int ledState = digitalRead(13);
    if (ledState == LOW) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }
}
