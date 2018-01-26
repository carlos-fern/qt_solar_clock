source_dir=$1
pkgconfig_path=$2
prefix=$3
include=$4
libs=$5
xcb=$6

export PKG_CONFIG_PATH="${PKG_CONFIG_PATH}:${pkgconfig_path}"
export LIBRARY_PATH="${LIBRARY_PATH}:${libs}"
export CPLUS_INCLUDE_PATH="${CPLUS_INCLUDE_PATH}:${xcb}:${include}"
cd ${source_dir}/ && ./configure -I "${xcb}"  -L "${libs}" -R "${libs}"  -opensource -confirm-license -gui  -xcb -linuxfb -widgets -no-compile-examples -opengl -system-xcb  -release -xcb-xlib -system-pcre -no-alsa  -no-pulseaudio -no-openssl -no-qml-debug -no-largefile -no-gif -no-libproxy -no-xkbcommon-evdev -qt-zlib -no-dbus -no-harfbuzz -system-freetype -no-slog2 -no-pps -no-imf  -no-lgmon -no-android-style-assets  && make -j4
