source_dir=$1
pkgconfig_path=$2
prefix=$3
include=$4
m4_path=$5
bison_path=$6

export PKG_CONFIG_PATH="${pkgconfig_path}"
export PATH="${PATH}:${m4_path}:${bison_path}"
export M4="m4-1.4.18/bin"
cd ${source_dir}/ && ./configure --prefix=${prefix} && make -j4 install 
