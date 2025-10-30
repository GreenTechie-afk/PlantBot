# Arduino code

This folder contains the Arduino sketches, libraries, and build instructions for the PlantBot project.

Suggested structure:
- /Arduino code/Sketches/PlantBot/    (main sketch folder — keep Arduino sketch filename and folder name the same)
- /Arduino code/Libraries/            (any custom libraries or third-party libraries used by the project)
- /Arduino code/Examples/             (example sketches or usage demos)
- /Arduino code/Builds/               (optional: compiled binaries such as .hex files)
- /Arduino code/CHANGELOG.md          (track notable changes)

Contents to include for each sketch:
- a README explaining purpose and wiring diagram
- a .ino file with the sketch
- a libraries list (names + links) for third-party libraries
- example configuration (e.g., config.h.example)

How to build and upload
- Open the sketch in the Arduino IDE or VS Code + PlatformIO.
- Install required libraries listed in the Libraries section.
- Select the appropriate board and COM port, then upload.

Example: PlantBot sketch
- Arduino IDE: /Arduino code/Sketches/PlantBot/PlantBot.ino
- Brief wiring summary: sensors on A0-A2, I2C LCD on SDA/SCL, pump relay on D8, power from a 5V regulator.

PlatformIO
- You can add a platformio.ini file at the sketch root to support PlatformIO builds.

Notes on licensing and contributions
- Include license information that applies to the code (LICENSE file at repo root applies here unless otherwise noted).
- If you include third-party libraries, include attribution and links.