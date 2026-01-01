# SimpleMorse
SimpleMorse is an Arduino library that converts simplified Morse code button inputs (dot, dash, space) into readable text and ASCII output.
It is designed for learning, experimentation, and embedded projects involving physical Morse code input.

### ✨ Features
- Converts dot (.) and dash (-) button presses into characters
- Supports space input to separate characters
- Includes back/delete functionality
- Outputs decoded text strings
- Lightweight and easy to integrate into Arduino projects
  
##
### 🔧 Installation
<b>Option 1: Arduino IDE (Manual)</b>

- Download or clone this repository:
- git clone https://github.com/HimanshuChauragade/SimpleMorse.git
- Copy the SimpleMorse folder into your Arduino libraries directory.
- Restart the Arduino IDE.

<b>Option 2: ZIP Import</b>
- Download the repository as a ZIP file.
- Open Arduino IDE
- Go to Sketch → Include Library → Add .ZIP Library
- Select the downloaded ZIP file.

### 🚀 Usage
- <b>Include the Library: </b>
  #include <SimpleMorse.h>

- <b>Create an Object: </b>
  SimpleMorse morse(dashPin, dotPin, spacePin, backPin); //backPin is optional

<b>Example Sketch</b>
- A minimal working example is provided in:
  examples/bare/bare.ino


This example demonstrates:
- Button-based Morse input
- Real-time decoding
- Output via Serial Monitor
- Button Mapping Concept
  
<b>Button	Function<b>
- Dot(.): input
- Dash(-): input
- Space:	End of character
- Back:	Delete last symbol (optional)

##

### 📚 Supported Characters
- Letters A–Z
- Numbers 0–9
- Defined internally using a Morse lookup table. Could be easily modified to map custom characters to the morse input

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
