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
    
    
    String  symbolsAlphabet[36][2] =
    {
      { ".-","A" },
      { "-...","B" },
      { "-.-.","C" },
      { "-..","D" },
      { ".","E" },
      { "..-.","F" },
      { "--.","G" },
      { "....","H" },
      { "..","I" },
      { ".---","J" },
      { "-.-","K" },
      { ".-..","L" },
      { "--","M" },
      { "-.","N" },
      { "---","O" },
      { ".--.","P" },
      { "--.-","Q" },
      { ".-.","R" },
      { "...","S" },
      { "-","T" },
      { "..-","U" },
      { "...-","V" },
      { ".--","W" },
      { "-..-","X" },
      { "-.--","Y" },
      { "--..","Z" },
      { ".----","1" },
      { "..---","2" },
      { "...--","3" },
      { "....-","4" },
      { ".....","5" },
      { "-....","6" },
      { "--...","7" },
      { "---..","8" },
      { "----.","9" },
      { "-----","0"}
    };


public:
    // Constructor
    SimpleMorse(int dashPin, int dotPin, int spacePin, int backPin = -1)
    {
      this->dashPin  = dashPin;
      this->dotPin   = dotPin;
      this->spacePin = spacePin;
      this->backPin  = backPin;
    }

    void begin()
    {
      pinMode(dashPin, INPUT_PULLUP);
      pinMode(dotPin, INPUT_PULLUP);
      pinMode(spacePin, INPUT_PULLUP);
      if (backPin != -1){
        pinMode(backPin, INPUT_PULLUP);
      }
    }
    
    char getInput(){
      if (!dashState&& dashLastState)
        return '-';
      if (!dotState && dotLastState)
        return '.';
      if (!spaceState && spaceLastState)
        return ' ';
      return (char)0;
    }
    
    char decodeSymbol()
    {
      if (symbolBuffer == "")
        return ' ';
    
      for (int i = 0; i < 36; i++)
        if (symbolBuffer == symbolsAlphabet[i][0])
          return symbolsAlphabet[i][1][0];
    
      return (char)0;
    }
    
    void leastPriorityCheck()
    {
      if (symbolBuffer == "......") //Backspace
        if (textBuffer.length() > 0){
              textBuffer.remove(textBuffer.length() - 1, 1);
          }
      if (symbolBuffer == "------") //Clear textBuffer
        textBuffer = "";
    }

    void update()
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
            {
              textBuffer = (String)symbol;
            }
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
          if (symbolBuffer.length() > 6) //max tone buffer length
          {
            symbolBuffer = (String)tone;
          }
        }
    
        Serial.print("textBuffer:  ");
        Serial.println(textBuffer);
        Serial.print("symbolBuffer:  ");
        Serial.println(symbolBuffer);
      }
    
      if (backButtonState == 0)
      {
        if (textBuffer.length() > 0)
          {
             textBuffer.remove(textBuffer.length() - 1, 1);
          }
        Serial.print("textBuffer:  ");
        Serial.println(textBuffer);
        delay(50);
      }
    
      dashLastState = dashState;
      dotLastState = dotState;
      spaceLastState = spaceState;
    }

    String getText() {
      return textBuffer;
    }

    String getCurrentSymbol() {
      return symbolBuffer;
    }

    void clear() {
      textBuffer = "";
      symbolBuffer = "";
    }

};


SimpleMorse morse(A0, A1, A2, A3);

void setup()
{
    Serial.begin(9600);
    morse.begin();
}

void loop()
{
    morse.update();
}
