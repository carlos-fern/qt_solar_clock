#!/bin/bash

usage="builds the qt_solar_clock and handles the QT 5.5 depedency"
PROJ_DIR=$(pwd)
echo "Creating build env"
mkdir -p build/qt_resources
cd build/qt_resources
QT_DIR=$(pwd)


if [ ! -d "qt-everywhere-opensource-src-5.5.0" ]; then
	echo "Downloading Qt 5.5"
	wget "https://download.qt.io/archive/qt/5.5/5.5.0/single/qt-everywhere-opensource-src-5.5.0.tar.gz"
	tar -xzf qt-everywhere-opensource-src-5.5.0.tar.gz
fi

if [ ! -d "libxcb-1.12" ]; then
	echo "Downloading libxcb 1.12"
	wget "https://xcb.freedesktop.org/dist/libxcb-1.12.tar.gz"
	tar -xzf libxcb-1.12.tar.gz
fi

if [ ! -d "xcb-proto-1.12" ]; then
	echo "Downloading xcb-prot 1.12"
	wget "https://xcb.freedesktop.org/dist/xcb-proto-1.12.tar.gz"
	tar -xzf xcb-proto-1.12.tar.gz
fi


cd xcb-proto-1.12
echo "Building xcb-proto 1.12"
./configure
make
make install

cd $QT_DIR/libxcb-1.12
echo "Building libxcb 1.12"
./configure
make
make install

cd $QT_DIR/qt-everywhere-opensource-src-5.5.0/qtbase/
echo "Building Qt 5.5"
./configure -opensource -nomake examples -nomake tests -confirm-license -qt-xcb
make
make install

cd $PROJ_DIR
echo "Building qt_solar_clock"
make 



