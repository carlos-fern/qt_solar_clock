# qt_solar_clock
## Description
A Simple solar cock based on Qt5 OpenGLWidgets. Uses [NASA reference data](https://omniweb.gsfc.nasa.gov/coho/helios/planet.html)

## Features
- Zoom
- Tilt
- Sim speed control

## Build & Run

### Script (QT5 Provided)
- sudo chmod +x builder.sh
- sudo ./builder.sh

### Cmake (QT5 Assumed)
- mkdir ./build
- cd ./build
- cmake ..
- make 
- cd ./.
- ./qt_solar_clock

## Dependencies
- Ubuntu 16.04
- QT5
- CMake >= 2.8.11
