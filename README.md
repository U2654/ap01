# ap01
### This repo contains the examples of the course Applied Programming I. 

The examples are sorted by programming language:
* *asm*: RISC-V assembly 
* *c/singles*: standalone C programs
* *c/projects*: C projects
* *py/singles*: standalone Python programs
* *py/projects*: Python projects
* *js/singles*: standalone JavaScript programs
* *js/projects*: JavaScript projects
* *js/websites*: HTML/JavaScript exampels
* *cs/*: C# console programs
* *esp*: Microcontroller projects for ESP32C6


### 1. Installation of Visual Studio Code:
(This should already have been done in the first lecture)
* Download: <https://code.visualstudio.com/>

### 2. Extension installation:
The examples run within VS code. The installation of the following extensions for VS code are recommended:
* .NET Install Tool
* C/C++
* C/C++ Extension Pack
* CodeLLDB
* C#
* C# Dev Kit
* IntelliCode for C# Dev Kit
* JavaScript Debugger
* Python
* Python Debugger
* Pylance
* RISC-V Support
* RISC-V Venus Simulator
* Git (Submodule) Assistant
* Live Preview
* Jupyter

For the embedded programming part:
* ESP-IDF (configure 'advanced and install v5.1.4)
* (optional: Wokwi Simulator) 

### Hints and tips:
Please open the leaf directories seperately as folder so that VS code applies the correct language. However... do the following before.

### Python Examples
- Install [Python](https://www.python.org/downloads/) 

### C# Examples:
- To run the C# single examples, install and use [.NET](https://dotnet.microsoft.com/).
- Install version .NET 8.0
- **IMPORTANT (WINDOWS ONLY): Start Visual Studio as follows:**
   - Press Windows key
   - Write: Developer Command Prompt and open it
   - type in the following command:
     ```
     code .
     ````

### JavaScript Examples: 

1. To run the JavaScript examples, install and use [node.js](https://nodejs.org).
2. And install prompt-sync:
   - (re)start VS Code
   - open a terminal in VS Code (in menu: Terminal -> New Terminal)
   - In the opened terminal window, type in the following command: 
      ```
      npm i prompt-sync
      ```

### C Examples
- macOS: install developer tools, open a Terminal and type
     ```
     git
     ````
    and agree to install.
- Windows: install GCC with minGW following [this instructions](https://code.visualstudio.com/docs/cpp/config-mingw)


### Microcontroller ESP32C6 examples
- Choose ESP32C6 as device target
- For debugging on hardware, use Eclipse CDT GDB Adapter
- For debugging with Wokwi, use Wokwi GDB





