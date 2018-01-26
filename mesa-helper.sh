source_dir=$1
pkgconfig_path=$2
prefix=$3
include=$4

export PKG_CONFIG_PATH=${pkgconfig_path}
export CFLAGS=-I"${include}"
export C_INCLUDE_PATH="${C_INCLUDE_PATH}:${include}"
cd ${source_dir}/ && ./configure --with-dri-drivers=swrast --with-gallium-drivers=swrast  --enable-driglx-direct --enable-gles1 --enable-gles2 --enable-glx-tls --with-egl-platforms='x11 drm' --prefix=${prefix} && make  install
      
