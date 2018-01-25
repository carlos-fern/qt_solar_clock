source_dir=$1
pkgconfig_path=$2
prefix=$3
include=$4
libs=$5
export PKG_CONFIG_PATH=${PKG_CONFIG_PATH}:${pkgconfig_path}
export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${libs}
cd ${source_dir}/ && ./configure -I ${include}  -L /home/ubuntu/qt_solar_clock/build/libxcb-1.12/lib -L /home/ubuntu/qt_solar_clock/libX11-1.6.5/lib/ -L /home/ubuntu/qt_solar_clock/build/pcre-8.41/lib -L /home/ubuntu/qt_solar_clock/build/freetype-2.9/lib/ -R /home/ubuntu/qt_solar_clock/build/pcre-8.41/lib  -opensource -confirm-license -gui -v -xcb -linuxfb -widgets -no-compile-examples -opengl -system-xcb  -release -xcb-xlib -system-pcre -qt-zlib -no-dbus -no-harfbuzz -system-freetype 