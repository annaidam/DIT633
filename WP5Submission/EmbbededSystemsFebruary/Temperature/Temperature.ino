// C++ code
//

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int LED5 = 9;
int tempSensor = 5;
int range = 10;
int period = 31250;

float temperatureVoltage;
float temperature;

void setup()
{
  //Serial
  Serial.begin(9600); 
  
  //LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  
  //tempSensor
  pinMode(tempSensor, INPUT);
  
  cli();
  
  //timer stuff for interupts 
  //credits:(https://www.youtube.com/watch?v=Uv9UeYUsA8A&ab_channel=Electronoobs)
  TCCR1A = 0; //reset entire control register A to 0
  TCCR1B = 0; //reset entire control register B to 0
  TCCR1B |= B00000100; //Set CS12 to 1 so we get prescalar 256
  
  TIMSK1 |= B00000010; //Set OCIE1A to 1 so we get compare match A
  
  OCR1A = period; //Finally we compare register A to this value
  sei();
  
}

void loop()
{
	
}

float getTemp()
{
  
  temperatureVoltage = analogRead(tempSensor)*5.0195;
  temperatureVoltage /= 1024.0;
  return (((temperatureVoltage)/1.75)*165);
  
  //return map((analogRead(A5) * 3.04), 0, 1023, -40, 125);
}

ISR(TIMER1_COMPA_vect) {
  TCNT1 = 0; //set the Timer back to 0
  temperature = getTemp();
  Serial.print("temperature: ");
  Serial.println(temperature);
  int numberOfLEDs = temperature / range;
  if (numberOfLEDs > 5) {
    numberOfLEDs = 5;
    Serial.println("temp to high for given range");
  } else if (numberOfLEDs < 0) {
    numberOfLEDs = 0;
    Serial.println("temp to low");
  }
  
  if (numberOfLEDs == 0) {
    bigDigitalWrite(0,0,0,0,0);
  } else if (numberOfLEDs == 1) {
    bigDigitalWrite(1,0,0,0,0);
  } else if (numberOfLEDs == 2) {
    bigDigitalWrite(1,1,0,0,0);
  } else if (numberOfLEDs == 3) {
    bigDigitalWrite(1,1,1,0,0);
  } else if (numberOfLEDs == 4) {
    bigDigitalWrite(1,1,1,1,0);
  } else if (numberOfLEDs == 5) {
    bigDigitalWrite(1,1,1,1,1);
  } else {
    Serial.print("error");
  }
}
  
void bigDigitalWrite(int LED1ON, int LED2ON, int LED3ON, int LED4ON, int LED5ON) {
  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  
  if(LED1ON == 1) {
    digitalWrite(LED1, HIGH);
  }
  if(LED2ON == 1) {
    digitalWrite(LED2, HIGH);
  } 
  if(LED3ON == 1) {
    digitalWrite(LED3, HIGH);
  } 
  if(LED4ON == 1) {
    digitalWrite(LED4, HIGH);
  } 
  if(LED5ON == 1) {
    digitalWrite(LED5, HIGH);
  }
}