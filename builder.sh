PROJ_DIR=$(pwd)
echo "Creating build env"
mkdir -p build/qt_resources
cd build/qt_resources
QT_DIR=$(pwd)


if [ ! -d "qt-everywhere-opensource-src-5.5.0" ]; then
	echo "Downloading Qt 5.5"
	wget "https://download.qt.io/archive/qt/5.5/5.5.0/single/qt-everywhere-opensource-src-5.5.0.tar.gz"
	tar -xzvf qt-everywhere-opensource-src-5.5.0.tar.gz
fi


if [ ! -d "m4-1.4.18"] then 
	wget"https://mirrors.peers.community/mirrors/gnu/m4/m4-1.4.18.tar.gz"
	tar -xzvf m4-1.4.18.tar.gz
fi 


if [! -d "automake-1.15.1"] then 
 	wget "ftp://ftp.gnu.org/gnu/automake/automake-1.15.1.tar.gz"
 	tar -xzvf automake-1.15.1.tar.gz
fi


if [ ! -d "autoconf-2.69" ]; then
	echo "Downloading autoconf"
	wget "http://ftp.gnu.org/gnu/autoconf/autoconf-2.69.tar.xz"
	tar -xvf autoconf-2.69.tar.xz
fi

if [ ! -d "macros" ]; then
	git clone "git://anongit.freedesktop.org/git/xorg/util/macros"
fi

if [ ! -d "libXau" ]; then
	git clone "git://anongit.freedesktop.org/git/xorg/lib/libXau"
fi

if [ ! -d "x11proto" ]; then
	git clone "git://anongit.freedesktop.org/git/xorg/proto/x11proto"
fi

if [ ! -d "pthread-stubs" ]; then
	git clone "git://anongit.freedesktop.org/git/xcb/pthread-stubs"
fi

if [ ! -d "proto" ]; then
	git clone "git://anongit.freedesktop.org/git/xcb/proto"
fi

if [ ! -d "libxcb" ]; then
	git clone "git://anongit.freedesktop.org/git/xcb/libxcb"
fi

cd m4-1.4.18
./configure
make install

cd $QT_DIR/automake-1.15.1
./configure
make install

cd $QT_DIR/autoconf-2.69
./configure
make install

cd $QT_DIR/macros
(./autogen.sh)
make install

cd $QT_DIR/libXau
(./autogen.sh)
make install

cd $QT_DIR/x11proto
(./autogen.sh)
make install

cd $QT_DIR/pthread-stubs
(./autogen.sh)
make install

cd $QT_DIR/proto
(./autogen.sh)
make install  

cd $QT_DIR/libxcb
(./autogen.sh)
make install 

cd $QT_DIR/qt-everywhere-opensource-src-5.5.0/qtbase/
echo "Building Qt 5.5"
./configure -opensource -nomake examples -nomake tests -confirm-license -qt-xcb
make install

cd $PROJ_DIR
echo "Building qt_solar_clok"
make






