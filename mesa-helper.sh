source_dir=$1
pkgconfig_path=$2
prefix=$3
include=$4

export PKG_CONFIG_PATH=${pkgconfig_path}
export CFLAGS=-I${include}
cd ${source_dir}/ && ./configure --with-dri-drivers=nouveau --with-gallium-drivers=nouveau  --enable-driglx-direct --enable-gles1 --enable-gles2 --enable-glx-tls   --with-egl-platforms='drm x11' --prefix=${prefix} && make -j4 install
      
