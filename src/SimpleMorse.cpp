#include "SimpleMorse.h"

SimpleMorse::SimpleMorse(int dashPin, int dotPin, int spacePin, int backPin)
{
    this->dashPin  = dashPin;
    this->dotPin   = dotPin;
    this->spacePin = spacePin;
    this->backPin  = backPin;
}

SimpleMorse::SimpleMorse(int dashPin, int dotPin, int spacePin)
{
    this->dashPin  = dashPin;
    this->dotPin   = dotPin;
    this->spacePin = spacePin;
}

void SimpleMorse::begin()
{
    pinMode(dashPin, INPUT_PULLUP);
    pinMode(dotPin, INPUT_PULLUP);
    pinMode(spacePin, INPUT_PULLUP);
    if (backPin != -1){
        pinMode(backPin, INPUT_PULLUP);
    }
}

void SimpleMorse::read()
{
    dashState = digitalRead(dashPin);
    dotState = digitalRead(dotPin);
    spaceState = digitalRead(spacePin);
    backButtonState = digitalRead(backPin);
}

void SimpleMorse::print_details()
{
    Serial.print("textBuffer:  ");
    Serial.println(textBuffer);
    Serial.print("symbolBuffer:  ");
    Serial.println(symbolBuffer);
}

void SimpleMorse::spit_info()
{
    Serial.print("dashPin: ");
    Serial.println(dashPin);
    Serial.print("dotPin: ");
    Serial.println(dotPin);
    Serial.print("spacePin: ");
    Serial.println(spacePin);
    Serial.print("backPin: ");
    Serial.println(backPin);
}

void SimpleMorse::clear()
{
    textBuffer = "";
    symbolBuffer = "";
}

void SimpleMorse::backspace()
{
    if (textBuffer.length() > 0)
        textBuffer.remove(textBuffer.length() - 1, 1);
}

void SimpleMorse::back_butt_check()
{
    if (backButtonState == 0)
    {
        backspace();
        delay(50);
    }
}

void SimpleMorse::update_butt_state()
{
    dashLastState = dashState;  //Updating the state of buttons
    dotLastState = dotState;
    spaceLastState = spaceState;
}

void SimpleMorse::instructions_check()
{
    if (symbolBuffer == "......")
        backspace();

    if (symbolBuffer == "------")
        clear();
}

void SimpleMorse::update()
{
    change = false;
    read();

    char tone = getInput();
    delay(50);

    if (tone != (char)0)
    {
        if (tone == ' ')
        {
            char symbol = searchSymbol();

            if (symbol != (char)0)
            {
                textBuffer += symbol;
                if (textBuffer.length() > 16) // max sting length
                    textBuffer = (String)symbol;
            }
            else
                instructions_check();

            symbolBuffer = ""; // resetting variable
        }
        else
        {
            symbolBuffer += tone;
            if (symbolBuffer.length() > 6) // max symbol buffer length
                symbolBuffer = (String)tone;
        }
        change = true;
        // print_details(); 
        //Uncomment if need to print the input info by default
    }

    back_butt_check();
    update_butt_state();
}

char SimpleMorse::getInput()
{
    if (!dashState && dashLastState)
        return '-';
    if (!dotState && dotLastState)
        return '.';
    if (!spaceState && spaceLastState)
        return ' ';
    return (char)0;
}

char SimpleMorse::searchSymbol() // Looks for the Alpha-numeric character associated with the morse input
{
    if (symbolBuffer == "")
        return ' ';

    for (int i = 0; i < 36; i++)
        if (symbolBuffer == symbolsAlphabet[i][0])
            return symbolsAlphabet[i][1][0];

    return (char)0;
}

String SimpleMorse::getText()
{
    return textBuffer;
}

String SimpleMorse::getSymbol()
{
    return symbolBuffer;
}

bool SimpleMorse::stateChange()
{
    return change;
}