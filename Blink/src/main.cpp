#include <Arduino.h>

int ledPin = 2;

const long evenHigh = 1500;
const long evenLow = 4000;

bool ledState = LOW;
unsigned long previousTime = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime = millis();

  if (ledState == HIGH){
    if(currentTime - previousTime >= evenHigh){
      ledState = LOW;
      Serial.println("LOW");
      digitalWrite(ledPin, ledState);
      previousTime = currentTime;
    }
  }
  else{
    if(currentTime - previousTime >= evenLow){
      ledState = HIGH;
      Serial.println("HIGH");
      digitalWrite(ledPin, ledState);
      previousTime = currentTime;
    }
  }
}