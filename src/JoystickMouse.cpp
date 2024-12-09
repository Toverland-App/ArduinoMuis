#include <Arduino.h>
#include <Mouse.h>

// Pin configuration
const int PIN_JOYSTICKX = A0;
const int PIN_JOYSTICKY = A1;
const int PIN_JOYSTICKBUTTON = 7;

const int MAX_ANGLE = 100;
const int MIN_ANGLE = -100;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_JOYSTICKBUTTON, INPUT_PULLUP);
  Mouse.begin();
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

  // Map the joystick angle to mouse movement
  int xMovement = map(xAngle, MIN_ANGLE, MAX_ANGLE, -10, 10);
  int yMovement = map(yAngle, MIN_ANGLE, MAX_ANGLE, -10, 10);

  // Move the mouse
  Mouse.move(xMovement, yMovement);

  // Handle button press for mouse click
  if (buttonState == LOW) {
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  } else {
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  }

  delay(20); // Add a small delay to avoid overwhelming the system
}