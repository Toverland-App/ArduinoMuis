#include <Arduino.h>
// Pin configuration
const int PIN_JOYSTICKX = A0;
const int PIN_JOYSTICKY = A1;
const int PIN_JOYSTICKBUTTON = 7;


const int MAX_ANGLE = 120;
const int MIN_ANGLE = -120;

int prevXValue = 0;
int prevYValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_JOYSTICKBUTTON, INPUT_PULLUP);

  
}

int get_knob_angle(int pin) {
  int sensor_value = analogRead(pin);
  int angle = map(sensor_value, 0, 1023, MIN_ANGLE, MAX_ANGLE);
  return angle;
}

void loop() {
  int buttonState = digitalRead(PIN_JOYSTICKBUTTON);
  int xAngle = get_knob_angle(PIN_JOYSTICKX);
  int yAngle = get_knob_angle(PIN_JOYSTICKY);

  if (buttonState == LOW) {
    Serial.println("Button pressed");
    delay(500);
  }

 if (abs(xAngle - prevXValue) > 5 || abs(yAngle - prevYValue) > 5) {
    Serial.print("Joystick X Angle: ");
    Serial.print(xAngle);
    Serial.print(" | Joystick Y Angle: "); 
    Serial.println(yAngle);
    prevXValue = xAngle;
    prevYValue = yAngle;
  }

}