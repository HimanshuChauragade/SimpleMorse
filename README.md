# SimpleMorse
SimpleMorse is an Arduino library that converts simplified Morse code button inputs (dot, dash, space) into readable text and ASCII output.
It is designed for learning, experimentation, and embedded projects involving physical Morse code input.

### ✨ Features
- Converts dot (.) and dash (-) button presses into characters
- Uses space input to mark the end of a character
- Optinal back/delete functionality
- Outputs decoded text as a String
- Simple API, no external dependencies
- Lightweight and easy to integrate into any Arduino project
- No dynamic memory allocation
- No external dependencies
##

📁 Library Structure

```
SimpleMorse/
├── examples/
│   ├── bare/
│   |   └── bare.ino
│   └── bare_with_lcd/
│       └── bare_with_lcd.ino
├── src/
│   ├── SimpleMorse.h
│   └── SimpleMorse.cpp
├── library.properties
├── library.json
├── LICENSE
└── README.md
```
##

### 🔧 Installation
<b>Option 1: Arduino IDE (Manual)</b>

- Download or clone this repository:
```bash
git clone https://github.com/HimanshuChauragade/SimpleMorse.git
```
- Copy the 'SimpleMorse' folder into your Arduino 'libraries' directory.
- Restart the Arduino IDE.

<b>Option 2: ZIP Import</b>
- Download the repository as a ZIP file.
- Open Arduino IDE
- Go to Sketch → Include Library → Add .ZIP Library
- Select the downloaded ZIP file.

<b>Option 3: Arduino IDE Library Manager (Not yet published)</b>
- Open Arduino IDE
- Go to Sketch → Include Library → Manage Libraries...
- Search "SimpleMorse", select and install

##

### 🚀 Usage
- <b>Include the Library: </b>
```c++
#include <SimpleMorse.h>
```
- <b>Create an Object: </b>
```c++
  SimpleMorse morse(dashPin, dotPin, spacePin, backPin); //backPin is optional
```
- <b>Process button input and update buffers: </b>
```c++
  morse.begin();
  morse.update();
```
- <b>Look for change in input and print the data: </b>
```c++
  if (morse.stateChange() != false){
    Serial.print("textBuffer:  ");
    Serial.println(morse.getText());
    Serial.print("symbolBuffer:  ");
    Serial.println(morse.getSymbol());
  }
```
##

### 📘 Examples
`bare.ino` - **Serial Monitor Example**

This example demonstrates:
- Button-based Morse input
- Real-time character decoding
- Output via Serial Monitor
- Button-to-function mapping

##
`bare_with_lcd.ino` - **LCD Output Example**
This example demonstrates:
- Displaying decoded text on a 16*2 I2C LCD Desplay
- Simultaneous Serial + LCD output
  
Use this example if you want:
- Visual feedback without a PC
- Standalone Morse decoder projects
- Integration with LCD-based embedded systems
  
##

### 🔘 Button	Function
- Dot(.): input
- Dash(-): input
- Space:	End of character
- Back:	Delete last symbol (optional)

##

### 📚 Supported Characters
- Letters A–Z
- Numbers 0–9
Characters are defined internally using a Morse lookup table, which can be easily extended or customized.

##

### 🧠 How It Works

- Button presses build a symbol buffer
- Space input triggers character decoding
- The decoded character is appended to a text buffer
- The buffer can be read or printed via Serial

##

### 🛠️ Compatibility
- Architectures: * (All Arduino-supported boards)
- AVR based boards (ATmega, ATtiny)
- ARM based boards (STM32, RP2040)

Tested with:
- Arduino Uno and nano
- ESP32, ESP8266
- ATtiny85

##

### 📄 Metadata
- Name: SimpleMorse
- Version: 1.0.0
- Category: Data Processing & Communication
- Author & Maintainer: Himanshu Chauragade
- Repository: https://github.com/HimanshuChauragade/SimpleMorse

##

### 🔮🌱 Future Improvements
- Adding various examples
- Option to enable/disable internal pullup resistor.
- Implement error-checking for more reliable data processing  

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature/amazing-feature`
3. **Commit your changes**: `git commit -m 'Add amazing feature'`
4. **Push to the branch**: `git push origin feature/amazing-feature`
5. **Open a Pull Request**

### 🙌 Development Guidelines

- Follow Arduino coding best practices  
- Keep circuit diagrams clear and well-documented  
- Use meaningful and descriptive commit messages  

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📞 Contact

- **GitHub**: [@HimanshuChauragade](https://github.com/HimanshuChauragade)
- **LinkedIn**: [Himanshu Chauragade](https://linkedin.com/in/himanshu-chauragade/)
- **Email**: 2024000129@mssu.ac.in
