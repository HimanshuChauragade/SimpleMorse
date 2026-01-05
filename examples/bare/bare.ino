/*
  SimpleMorse Library Example Sketch
  Demonstrates how to use the SimpleMorse library with
  push buttons. Internal pull-up resistors are used by default.

  Button Wiring:
  - One terminal of each push button goes to the Arduino pin
  - The other terminal goes to GND
  - Pins are configured with INPUT_PULLUP
*/

#include "SimpleMorse.h"

#define DASH_PIN   11   // Dash ( - )
#define DOT_PIN    10   // Dot  ( . )
#define SPACE_PIN   9   // Space
#define BACK_PIN    8   // Backspace (Optional)

// Create SimpleMorse object
SimpleMorse morse(DASH_PIN, DOT_PIN, SPACE_PIN, BACK_PIN);

void setup() {
  Serial.begin(9600);
  morse.begin();
}

void loop() {

  // Process button input and update buffers
  morse.update();

  // Look for change in input and print the data
  if (morse.stateChange() != false){
    Serial.print("textBuffer:  ");
    Serial.println(morse.getText());
    Serial.print("symbolBuffer:  ");
    Serial.println(morse.getSymbol());
  }

}
