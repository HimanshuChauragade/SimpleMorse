/*
  ------------------------------------------------------------
  SimpleMorse Library Example (I2C LCD)
  ------------------------------------------------------------
  This sketch demonstrates how to use the SimpleMorse library
  with push buttons and a 16x2 I2C LCD display.

  Wiring Notes:
  - One terminal of each push button goes to the Arduino pin
  - The other terminal goes to GND
  - Pins are configured using INPUT_PULLUP internally
    (button pressed = LOW)
*/

#include <SimpleMorse.h>
#include <LiquidCrystal_I2C.h>

#define DASH_PIN   11   // Dash ( - )
#define DOT_PIN    10   // Dot  ( . )
#define SPACE_PIN   9   // Space
#define BACK_PIN    8   // Backspace (Optional)

// Create SimpleMorse object
SimpleMorse morse(DASH_PIN, DOT_PIN, SPACE_PIN, BACK_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize Morse
  morse.begin();
  Serial.begin(9600);
  
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  static_txt();
}

void static_txt(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Txt:");
  lcd.setCursor(0, 1);
  lcd.print("In :");
}

void loop()
{
  // Update morse logic (read buttons, decode)
  morse.update();


  // Look for change in input and print the data
  if (morse.stateChange() != false){
    Serial.print("textBuffer:  ");
    Serial.println(morse.getText());
    Serial.print("symbolBuffer:  ");
    Serial.println(morse.getSymbol());

    static_txt();
    lcd.setCursor(5, 0);
    lcd.print(morse.getText());
    lcd.setCursor(5, 1);
    lcd.print(morse.getSymbol());
    delay(50);
  }

}
