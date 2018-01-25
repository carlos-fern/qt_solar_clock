source_dir=$1
pkgconfig_path=$2
prefix=$3
path=$4

export PKG_CONFIG_PATH=${pkgconfig_path}
export PATH=${PATH}:${4}
cd ${source_dir}/ && ./configure --prefix=${prefix} --with-harfbuzz=no && make -j4 install 
