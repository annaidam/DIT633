// C++ code
//

unsigned long previousMillis = 0;
const long interval = 1000;
int colPin = 0;
const int ROWS = 4;
const int COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void setup()
{
  //input
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  
  //output
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  
  Serial.begin(9600);
}

void loop()
{
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
     previousMillis = currentMillis;
	 
     colPin = checkButtonPressed();
     if (colPin) {
        for (int i = 8; i < 12; i++) {
          digitalWrite(i, HIGH);
          if (digitalRead(colPin) == HIGH) {
            char character = hexaKeys[i-8][colPin-4];
          	Serial.print("pressed: ");
            Serial.println(character);
          }
          digitalWrite(i, LOW);
        }
     }
  }
}

int checkButtonPressed(){
  if (digitalRead(7) == LOW){
    return 7;
  } else if (digitalRead(6) == LOW){
    return 6;
  } else if (digitalRead(5) == LOW){
    return 5;
  } else if (digitalRead(4) == LOW){
    return 4;
  }
  return 0;
}