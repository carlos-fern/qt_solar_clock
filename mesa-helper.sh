source_dir=$1
pkgconfig_path=$2
prefix=$3

export PKG_CONFIG_PATH=${pkgconfig_path}
#export EXPAT_LIBS=/home/ubuntu/qt_solar_clock/build/expat-2.0.1/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/ubuntu/qt_solar_clock/build/expat-2.0.1/lib

cd ${source_dir}/ && ./configure --with-dri-drivers=nouveau --enable-llvm --with-gallium-drivers=nouveau  --enable-driglx-direct --enable-gles1 --enable-gles2 --enable-glx-tls   --with-egl-platforms='drm x11' --prefix=${prefix} && make -j4 install
      