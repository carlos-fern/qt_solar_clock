source_dir=$1
pkgconfig_path=$2
prefix=$3

export PKG_CONFIG_PATH=${pkgconfig_path}


cd ${source_dir}/ && ./configure -opensource -confirm-license -gui -qt-xcb -linuxfb -widgets -no-compile-examples -release -xcb-xlib --prefix=${prefix} && make -j4  install

