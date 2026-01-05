#ifndef SIMPLE_MORSE_H
#define SIMPLE_MORSE_H

#include <Arduino.h>

class SimpleMorse
{
private:
    // Button pins
    int dashPin;
    int dotPin;
    int spacePin;
    int backPin;

    // Button states
    int dashState = 1, dashLastState = 1;
    int dotState = 1, dotLastState = 1;
    int spaceState = 1, spaceLastState = 1;

    int backButtonState = 1;

    String symbolBuffer;
    String textBuffer;

    bool available = false;
    bool change = false;

    String symbolsAlphabet[36][2] =
    {
      { ".-","A" }, { "-...","B" }, { "-.-.","C" }, { "-..","D" },
      { ".","E" }, { "..-.","F" }, { "--.","G" }, { "....","H" },
      { "..","I" }, { ".---","J" }, { "-.-","K" }, { ".-..","L" },
      { "--","M" }, { "-.","N" }, { "---","O" }, { ".--.","P" },
      { "--.-","Q" }, { ".-.","R" }, { "...","S" }, { "-","T" },
      { "..-","U" }, { "...-","V" }, { ".--","W" }, { "-..-","X" },
      { "-.--","Y" }, { "--..","Z" },
      { "0","0" }, { ".----","1" }, { "..---","2" }, { "...--","3" },
      { "....-","4" }, { ".....","5" }, { "-....","6" },
      { "--...","7" }, { "---..","8" }, { "----.","9" }
    };

public:
    SimpleMorse(int dashPin, int dotPin, int spacePin, int backPin);
    SimpleMorse(int dashPin, int dotPin, int spacePin);

    void begin();
    void read();
    void print_details();
    void spit_info();
    void clear();
    void backspace();
    void back_butt_check();
    void update_butt_state();
    void instructions_check();
    void update();

    bool stateChange();

    char getInput();
    char searchSymbol();

    String getText();
    String getSymbol();

};

#endif