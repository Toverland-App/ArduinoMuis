#include <Arduino.h>

// Pin configuration for buttons
const int PIN_BUTTON_1 = 6; 
const int PIN_BUTTON_2 = 2;  
const int PIN_BUTTON_3 = 3;
const int PIN_BUTTON_4 = 11;

// Pin configuration for joystick
const int PIN_JOYSTICKX = A0;
const int PIN_JOYSTICKY = A1;
const int PIN_JOYSTICKBUTTON = 7;

const int MAX_ANGLE = 120;
const int MIN_ANGLE = -120;

// Variables to store button states
int buttonState_1 = 0;  
int buttonState_2 = 0;  
int buttonState_3 = 0;
int buttonState_4 = 0;

// Variables to store previous joystick values
int prevXValue = 0;
int prevYValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP);
  pinMode(PIN_BUTTON_2, INPUT_PULLUP);
  pinMode(PIN_BUTTON_3, INPUT_PULLUP);
  pinMode(PIN_BUTTON_4, INPUT_PULLUP);
  pinMode(PIN_JOYSTICKBUTTON, INPUT_PULLUP);
}

int get_knob_angle(int pin) {
  int sensor_value = analogRead(pin);
  int angle = map(sensor_value, 0, 1023, MIN_ANGLE, MAX_ANGLE);
  return angle;
}

void loop() {
  // Read button states
  int buttonState_1 = digitalRead(PIN_BUTTON_1);
  int buttonState_2 = digitalRead(PIN_BUTTON_2);
  int buttonState_3 = digitalRead(PIN_BUTTON_3);
  int buttonState_4 = digitalRead(PIN_BUTTON_4);
  int buttonState = digitalRead(PIN_JOYSTICKBUTTON);

  // Read joystick values
  int xAngle = get_knob_angle(PIN_JOYSTICKX);
  int yAngle = get_knob_angle(PIN_JOYSTICKY);

  // Print button states
  if (buttonState_1 == LOW) {
    Serial.println("Groen");
    delay(500);
  }
  
  if (buttonState_2 == LOW) {
    Serial.println("Rood");
    delay(500);
  }
  
  if (buttonState_3 == LOW) {
    Serial.println("Geel");
    delay(500);
  }
  
  if (buttonState_4 == LOW) {
    Serial.println("Blauw");
    delay(500);
  }

  // Print joystick button state
  if (buttonState == LOW) {
    Serial.println("Joystick Button pressed");
    delay(500);
  }
  
  // Print joystick angles if they have changed
  if (abs(xAngle - prevXValue) > 5 || abs(yAngle - prevYValue) > 5) {
    Serial.print("Joystick X Angle: ");
    Serial.print(xAngle);
    Serial.print(" | Joystick Y Angle: "); 
    Serial.println(yAngle);
    prevXValue = xAngle;
    prevYValue = yAngle;
  }
 
}