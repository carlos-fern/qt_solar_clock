#!/bin/bash
set -e
TOPLEVEL=${pwd}
usage="builds the qt_solar_clock and handles the QT 5.5 depedency"

echo "Creating build env"
mkdir -p build/qt_resources
cd build/qt_resources

echo "Downloading Qt 5.5"
wget "https://download.qt.io/archive/qt/5.5/5.5.0/single/qt-everywhere-opensource-src-5.5.0.tar.gz"
tar -xzf qt-everywhere-opensource-src-5.5.0.tar.gz
cd qt-everywhere-opensource-src-5.5.0/qtbase/

echo "Building Qt 5.5"
./configure -opensource -nomake examples -nomake tests -confirm-license -qt-xcb
make
cd ../../../../
echo "Building qt_solar_clock"
make


