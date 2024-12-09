#include <Arduino.h>

// Pin configuration
const int joystickX = A0;  // X-axis of joystick
const int joystickY = A1;  // Y-axis of joystick
const int joystickSW = 2;  // Joystick button (SW)
const int buttonA = 3;     // Button A
const int buttonB = 4;     // Button B
const int buttonC = 5;     // Button C
const int buttonD = 6;     // Button D
const int buttonE = 7;     // Button E

// Variables to store previous states
int prevXValue = 0;
int prevYValue = 0;
int prevSWState = HIGH;
int prevButtonAState = HIGH;
int prevButtonBState = HIGH;
int prevButtonCState = HIGH;
int prevButtonDState = HIGH;
int prevButtonEState = HIGH;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up button pins as inputs
  pinMode(joystickSW, INPUT_PULLUP);
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(buttonC, INPUT_PULLUP);
  pinMode(buttonD, INPUT_PULLUP);
  pinMode(buttonE, INPUT_PULLUP);

  Serial.println("Funduino Joystick Shield Test");
}

void loop() {
  // Read joystick values
  int xValue = analogRead(joystickX);
  int yValue = analogRead(joystickY);
  int swState = digitalRead(joystickSW);

  // Read button states
  int buttonAState = digitalRead(buttonA);
  int buttonBState = digitalRead(buttonB);
  int buttonCState = digitalRead(buttonC);
  int buttonDState = digitalRead(buttonD);
  int buttonEState = digitalRead(buttonE);

  // Print joystick values if they have changed
  if (xValue != prevXValue || yValue != prevYValue) {
    Serial.print("Joystick X: "); Serial.print(xValue);
    Serial.print(" | Joystick Y: "); Serial.println(yValue);
    prevXValue = xValue;
    prevYValue = yValue;
  }

  // Print joystick button state if it has changed
  if (swState != prevSWState) {
    Serial.print("Joystick SW: "); Serial.println(swState == LOW ? "Pressed" : "Released");
    prevSWState = swState;
  }

  // Print button states if they have changed
  if (buttonAState != prevButtonAState) {
    Serial.print("Button A: "); Serial.println(buttonAState == LOW ? "Pressed" : "Released");
    prevButtonAState = buttonAState;
  }
  if (buttonBState != prevButtonBState) {
    Serial.print("Button B: "); Serial.println(buttonBState == LOW ? "Pressed" : "Released");
    prevButtonBState = buttonBState;
  }
  if (buttonCState != prevButtonCState) {
    Serial.print("Button C: "); Serial.println(buttonCState == LOW ? "Pressed" : "Released");
    prevButtonCState = buttonCState;
  }
  if (buttonDState != prevButtonDState) {
    Serial.print("Button D: "); Serial.println(buttonDState == LOW ? "Pressed" : "Released");
    prevButtonDState = buttonDState;
  }
  if (buttonEState != prevButtonEState) {
    Serial.print("Button E: "); Serial.println(buttonEState == LOW ? "Pressed" : "Released");
    prevButtonEState = buttonEState;
  }

  // Add a small delay for better readability in Serial Monitor
  delay(200);
}