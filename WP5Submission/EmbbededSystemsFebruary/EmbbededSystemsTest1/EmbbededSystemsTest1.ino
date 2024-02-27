// C++ code
//

int buttonState = 0;
unsigned long previousMillis = 0; // stores last time LED was updated
const long interval = 1000; // interval at which to blink (milliseconds)

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
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
