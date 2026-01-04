#include "SimpleMorse.h"

SimpleMorse morse(11, 10, 9, 8);

// SimpleMorse morse(11, 10, 9);

void setup()
{
    Serial.begin(9600);
    morse.begin();
}

void loop()
{
    morse.update();
}
