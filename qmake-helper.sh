source_dir=$1
qmake=$2
pro_file=$3
pkg_conf=$4
include=$5
libs=$6
export PKG_CONFIG_PATH="${pkgconfig_path}"
export CFLAGS=-I"${include}"
export CPPFLAGS=-I"${include}"
export C_INCLUDE_PATH="${C_INCLUDE_PATH}:${include}"
export LIBRARY_PATH="${LIBRARY_PATH}:${libs}"

cd ${source_dir}/ && ${qmake} ${pro_file} && make 
