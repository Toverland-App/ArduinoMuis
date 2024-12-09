#include <Arduino.h>
const int PIN_BUTTON_1 = 6; 
const int PIN_BUTTON_2 = 2;  
const int PIN_BUTTON_3 = 3;
const int PIN_BUTTON_4 = 11;

int buttonState_1 = 0;  
int buttonState_2 = 0;  
int buttonState_3 = 0;
int buttonState_4 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP);
  pinMode(PIN_BUTTON_2, INPUT_PULLUP);
  pinMode(PIN_BUTTON_3, INPUT_PULLUP);
  pinMode(PIN_BUTTON_4, INPUT_PULLUP);
}

void loop() {
  buttonState_1 = digitalRead(PIN_BUTTON_1);
  buttonState_2 = digitalRead(PIN_BUTTON_2);
  buttonState_3 = digitalRead(PIN_BUTTON_3);
  buttonState_4 = digitalRead(PIN_BUTTON_4);
  

  if (buttonState_1 == LOW){
    Serial.println("Groen");
    delay(500);
  }
  
  if (buttonState_2 == LOW){
    Serial.println("Rood");
    delay(500);
  }
  if (buttonState_3 == LOW){
    Serial.println("Geel");
    delay(500);
  }
  if (buttonState_4 == LOW){
    Serial.println("Blauw");
    delay(500);
  }
}
