#define dashPin A0
#define dotPin A1
#define spacePin A2
#define backPin A3

int dashState = 1, dashLastState = 1;
int dotState = 1, dotLastState = 1;
int spaceState = 1, spaceLastState = 1;

int backButtonState = 1;

int str_len = 0;

String symbolBuffer;
String textBuffer;


String  symbolsAlphabet[][2] =
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

char getInput(){
	if (!dashState&& dashLastState)
		return '-';
	if (!dotState && dotLastState)
		return '.';
	if (!spaceState && spaceLastState)
		return ' ';
	return (char)0;
}


char getSymbolFromBuffer()
{
	if (symbolBuffer == "")
		return ' ';

	for (int i = 0; i < sizeof symbolsAlphabet / sizeof symbolsAlphabet[0]; i++)
		if (symbolBuffer == symbolsAlphabet[i][0])
			return symbolsAlphabet[i][1][0];

	return (char)0;
}

void extractActionFromTonesBuffer()
{
	if (symbolBuffer == "......") //Backspace
		textBuffer.remove(textBuffer.length() - 1, 1);
	if (symbolBuffer == "------") //Clear textBuffer
		textBuffer = "";
}


void setup() {

  Serial.begin(9600);

	pinMode(dashPin, INPUT_PULLUP);
	pinMode(dotPin, INPUT_PULLUP);
	pinMode(spacePin, INPUT_PULLUP);
	pinMode(backPin, INPUT_PULLUP);
}

void loop() {

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
			char symbol = getSymbolFromBuffer();

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
				extractActionFromTonesBuffer();
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
    str_len = textBuffer.length();
    textBuffer.remove(str_len - 1);
		Serial.print("textBuffer:  ");
		Serial.println(textBuffer);
    delay(150);
  }

	dashLastState = dashState;
	dotLastState = dotState;
	spaceLastState = spaceState;
}
