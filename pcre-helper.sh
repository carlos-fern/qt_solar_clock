source_dir=$1
pkgconfig_path=$2
prefix=$3

export PKG_CONFIG_PATH=${pkgconfig_path}
export EXPAT_LIBS=/home/ubuntu/qt_solar_clock/build/expat-2.0.1/lib
echo $EXPAT_LIBS
cd ${source_dir}/ && ./configure --enable-pcre16 --enable-pcre32 --prefix=${prefix} && make -j4 install 
