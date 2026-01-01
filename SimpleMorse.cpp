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

char SimpleMorse::decodeSymbol()
{
    if (symbolBuffer == "")
        return ' ';

    for (int i = 0; i < 36; i++)
        if (symbolBuffer == symbolsAlphabet[i][0])
            return symbolsAlphabet[i][1][0];

    return (char)0;
}

void SimpleMorse::leastPriorityCheck()
{
    if (symbolBuffer == "......")
        if (textBuffer.length() > 0)
            textBuffer.remove(textBuffer.length() - 1, 1);

    if (symbolBuffer == "------")
        textBuffer = "";
}

void SimpleMorse::update()
{
    dashState = digitalRead(dashPin);
    dotState = digitalRead(dotPin);
    spaceState = digitalRead(spacePin);
    backButtonState = digitalRead(backPin);

    char tone = getInput();
    delay(50);

    if (tone != (char)0)
    {
        if (tone == ' ')
        {
            char symbol = decodeSymbol();

            if (symbol != (char)0)
            {
                textBuffer += symbol;
                if (textBuffer.length() > 16)
                    textBuffer = (String)symbol;
            }
            else
            {
                leastPriorityCheck();
            }
            symbolBuffer = "";
        }
        else
        {
            symbolBuffer += tone;
            if (symbolBuffer.length() > 6)
                symbolBuffer = (String)tone;
        }

        Serial.print("textBuffer:  ");
        Serial.println(textBuffer);
        Serial.print("symbolBuffer:  ");
        Serial.println(symbolBuffer);
    }

    if (backButtonState == 0)
    {
        if (textBuffer.length() > 0)
            textBuffer.remove(textBuffer.length() - 1, 1);

        Serial.print("textBuffer:  ");
        Serial.println(textBuffer);
        delay(50);
    }

    dashLastState = dashState;
    dotLastState = dotState;
    spaceLastState = spaceState;
}

String SimpleMorse::getText()
{
    return textBuffer;
}

String SimpleMorse::getCurrentSymbol()
{
    return symbolBuffer;
}

void SimpleMorse::clear()
{
    textBuffer = "";
    symbolBuffer = "";
}

