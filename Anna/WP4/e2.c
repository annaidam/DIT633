// (C) Anna Mäkinen, David Schön, Milena Mackowiak, group: 3 (2024)
// Work package 4
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

#include <Servo.h>

int servoPin = 8;
Servo servo;

// store seconds in variable
volatile int seconds = 0;

// counter for interrupts
volatile int intrCounter = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);

  // set Timer2 interrupt every second
  noInterrupts();            // disable interrupts during setup
  TCCR2A = 0;                // Timer2 Control Register A
  TCCR2B = 0;                // Timer2 Control Register B
  TCNT2 = 0;                 // initialise counter value to 0
  OCR2A = 249;
  TCCR2A |= (1 << WGM21);    // set WGM to CTC
  TCCR2B |= (1 << CS22);  	 // set prescaler to 1024
  TIMSK2 |= (1 << OCIE2A);   // enable timer compare interrupt
  interrupts();              // enable interrupts
}

void loop() {}

ISR(TIMER2_COMPA_vect) {
  // increment the interrupt counter
  intrCounter++;
  
  // once it hits 1000
  if (intrCounter >= 1000) {
    
    // update seconds and print them
    seconds++;
    Serial.print("secs: ");
    Serial.println(seconds);

    // move the servo based on the seconds value
    moveServo();

    // reset the seconds to 0 after reaching 60
    if (seconds >= 60) {
      seconds = 0;
    }
    
    // set counter back to 0
    intrCounter = 0;
  }
}

void moveServo() {
  // map the seconds value to the servo angle from 0 to 180
  int angle = map(seconds, 0, 60, 0, 180);

  // move the servo to the calculated angle
  servo.write(angle);
}
