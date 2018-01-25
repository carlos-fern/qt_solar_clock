cmake_minimum_required(VERSION 2.8.11)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
project(qt_solar_clock)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)


#################################################################################################################################
# set include paths
#################################################################################################################################
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xproto-7.0.31/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libXau-1.0.8/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libpthread-stubs-0.4/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xcb-proto-1.12/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libxcb-1.12/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libX11-1.6.5/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xextproto-7.3.0/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/inputproto-2.3/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/kbproto-1.0.7/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xtrans-1.3.5/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/mesa-17.3.3/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.11/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/glproto-1.4.17/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libpciaccess-0.14/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libdrm-2.4.89/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/dri2proto-2.8/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libXext-1.3.3/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libXfixes-5.0/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libXdamage-1.1/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/fixesproto-5.0/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/damageproto-1.2.1/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libxshmfence-1.2/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/expat-2.0.1/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/pcre-8.41/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/freetype-2.9/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xcb-util-wm-0.4.1/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/m4-1.4/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xcb-util-0.4.0/include")
set( INCLUDE_DIRS "${INCLUDE_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/util-macros-1.19.1/include")

#################################################################################################################################
# Set library paths
#################################################################################################################################
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xproto-7.0.31/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libXau-1.0.8/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libpthread-stubs-0.4/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xcb-proto-1.12/lib")
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libxcb-1.12/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xlibX11-1.6.5/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xextproto-7.3.0/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/inputproto-2.3/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/kbproto-1.0.7/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xtrans-1.3.5/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/mesa-17.3.3/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.1/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/glproto-1.4.17/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libpciaccess-0.14/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libdrm-2.4.89/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/dri2proto-2.8/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libXext-1.3.3/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libXfixes-5.0/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libXdamage-1.1/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/fixesproto-5.0/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/damageproto-1.2./lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/libxshmfence-1.2/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/expat-2.0.1/lib ")
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/pcre-8.41/lib ")
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/freetype-2.9/lib ")
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xcb-util-wm-0.4.1/lib ")
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/m4-1.4/lib" )
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/xcb-util-0.4.0/lib ")
set( LIB_DIRS "${LIB_DIRS}:${CMAKE_CURRENT_BINARY_DIR}/util-macros-1.19.1/lib" )

#################################################################################################################################
# Set pkg config paths
#################################################################################################################################
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/xproto-7.0.31/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/libXau-1.0.8/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/libpthread-stubs-0.4/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/xcb-proto-1.12/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/libxcb-1.12/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/libX11-1.6.5/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/xextproto-7.3.0/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/inputproto-2.3/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/kbproto-1.0.7/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/xtrans-1.3.5/share/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/mesa-17.3.3/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.11/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/glproto-1.4.17/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/libpciaccess-0.14/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/libdrm-2.4.89/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/dri2proto-2.8/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/libXext-1.3.3/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/libXfixes-5.0/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/libXdamage-1.1/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/fixesproto-5.0/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/damageproto-1.2.1/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/libxshmfence-1.2/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/expat-2.0.1/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/pcre-8.41/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/freetype-2.9/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/xcb-util-wm-0.4.1/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/m4-1.4/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/xcb-util-0.4.0/lib/pkgconfig/" )
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_BINARY_DIR}/util-macros-1.19.1/share/pkgconfig/" )

#################################################################################################################################
# set m4 bin path
#################################################################################################################################
set (M4_BIN_PATH "${CMAKE_CURRENT_BINARY_DIR}/m4-1.4/bin")

#################################################################################################################################
# Get libxcb and it's dependencies
#################################################################################################################################
ExternalProject_Add(util-macros
  URL https://www.x.org/archive/individual/util/util-macros-1.19.1.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/util-macros-1.19.1
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/util-macros-1.19.1/src/util-macros/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/util-macros-1.19.1"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(xproto
  URL https://www.x.org/archive//individual/proto/xproto-7.0.31.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/xproto-7.0.31
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/xproto-7.0.31/src/xproto/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/xproto-7.0.31"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(libXau
  URL https://www.x.org/archive//individual/lib/libXau-1.0.8.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libXau-1.0.8
  CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/libXau-1.0.8/src/libXau;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/libXau-1.0.8"
  INSTALL_COMMAND echo "NONE"
)


ExternalProject_Add(libxcb
  URL https://xcb.freedesktop.org/dist/libxcb-1.12.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libxcb-1.12
     CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/libxcb-1.12/src/libxcb;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/libxcb-1.12"
  INSTALL_COMMAND echo "NONE"
)

ExternalProject_Add(xcb-util
  URL https://xcb.freedesktop.org/dist/xcb-util-0.4.0.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/xcb-util-0.4.0
  CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/xcb-util-0.4.0/src/xcb-util;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/xcb-util-0.4.0"
  INSTALL_COMMAND echo "NONE"
)


ExternalProject_Add(xcb-util-wm
  URL https://xcb.freedesktop.org/dist/xcb-util-wm-0.4.0.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/xcb-util-wm-0.4.0
     CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/xcb-util-wm-0.4.0/src/xcb-util-wm;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/xcb-util-wm-0.4.0;${M4_BIN_PATH}"
  INSTALL_COMMAND echo "NONE"
)

ExternalProject_Add(libXdamage
  URL https://www.x.org/archive//individual/lib/libXdamage-1.1.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libXdamage-1.1
  CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/libXdamage-1.1/src/libXdamage;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/libXdamage-1.1"
  INSTALL_COMMAND echo "NONE"
)


ExternalProject_Add(freetype
  URL https://download.savannah.gnu.org/releases/freetype/freetype-2.9.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/freetype-2.9
  CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/freetype-helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/freetype-2.9/src/freetype;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/freetype-2.9"
  INSTALL_COMMAND echo "NONE"
)


ExternalProject_Add(damageproto
  URL https://www.x.org/archive//individual/proto/damageproto-1.2.1.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/damageproto-1.2.1
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/damageproto-1.2.1/src/damageproto/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/damageproto-1.2.1"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(m4
  URL https://ftp.gnu.org/gnu/m4/m4-1.4.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/m4-1.4
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/m4-1.4/src/m4/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/m4-1.4"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(libXfixes
  URL https://www.x.org/archive//individual/lib/libXfixes-5.0.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libXfixes-5.0
   CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/libXfixes-5.0/src/libXfixes;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/libXfixes-5.0"
  INSTALL_COMMAND echo "NONE"
)

ExternalProject_Add(fixesproto
  URL https://www.x.org/archive//individual/proto/fixesproto-5.0.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/fixesproto-5.0
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/fixesproto-5.0/src/fixesproto/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/fixesproto-5.0"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)


ExternalProject_Add(expat
  URL https://sourceforge.net/projects/expat/files/expat/2.1.0/expat-2.1.0.tar.gz/download
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/expat-2.0.1
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/expat-2.0.1/src/expat/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/expat-2.0.1"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)



ExternalProject_Add(libxshmfence
  URL https://www.x.org/archive//individual/lib/libxshmfence-1.2.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libxshmfence-1.2
   CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/libxshmfence-1.2/src/libxshmfence;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/libxshmfence-1.2"
  INSTALL_COMMAND echo "NONE"
)

ExternalProject_Add(libpthread-stubs
  URL https://xcb.freedesktop.org/dist/libpthread-stubs-0.4.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libpthread-stubs-0.4
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/libpthread-stubs-0.4/src/libpthread-stubs/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/libpthread-stubs-0.4"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(xcb-proto
  URL https://xcb.freedesktop.org/dist/xcb-proto-1.12.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/xcb-proto-1.12
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/xcb-proto-1.12/src/xcb-proto/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/xcb-proto-1.12"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(pcre
  URL https://downloads.sourceforge.net/pcre/pcre-8.41.tar.bz2

  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/pcre-8.41
  CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/pcre-helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/pcre-8.41/src/pcre;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/pcre-8.41"
  INSTALL_COMMAND echo "NONE"
)

ExternalProject_Add(xextproto
  URL https://www.x.org/archive//individual/proto/xextproto-7.3.0.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/xextproto-7.3.0
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/xextproto-7.3.0/src/xextproto/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/xextproto-7.3.0"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(inputproto
  URL https://www.x.org/archive//individual/proto/inputproto-2.3.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/inputproto-2.3
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/inputproto-2.3/src/inputproto/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/inputproto-2.3"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(kbproto
  URL https://www.x.org/archive//individual/proto/kbproto-1.0.7.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/kbproto-1.0.7
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/kbproto-1.0.7/src/kbproto/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/kbproto-1.0.7"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(xtrans
  URL https://www.x.org/archive//individual/lib/xtrans-1.3.5.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/xtrans-1.3.5
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/xtrans-1.3.5/src/xtrans/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/xtrans-1.3.5"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(libXext
  URL https://www.x.org/archive//individual/lib/libXext-1.3.3.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libXext-1.3.3
  CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/libXext-1.3.3/src/libXext;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/libXext-1.3.3"
  INSTALL_COMMAND echo "NONE"
)

ExternalProject_Add(zlib
  URL http://zlib.net/zlib-1.2.11.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.11
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.11/src/zlib/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/zlib-1.2.11"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(mesa
  URL https://mesa.freedesktop.org/archive/mesa-17.3.3.tar.xz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/mesa-17.3.3
  CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/mesa-helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/mesa-17.3.3/src/mesa;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/mesa-17.3.3;${INCLUDE_DIRS}:"
  INSTALL_COMMAND echo "NONE"
)

ExternalProject_Add(libdrm
  URL https://dri.freedesktop.org/libdrm/libdrm-2.4.89.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libdrm-2.4.89
  CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/libdrm-2.4.89/src/libdrm;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/libdrm-2.4.89"
  INSTALL_COMMAND echo "NONE"
)

ExternalProject_Add(dri2proto
  URL https://www.x.org/archive/individual/proto/dri2proto-2.8.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/dri2proto-2.8
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/dri2proto-2.8/src/dri2proto/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/dri2proto-2.8"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(libpciaccess
  URL https://www.x.org/archive//individual/lib/libpciaccess-0.14.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libpciaccess-0.14
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/libpciaccess-0.14/src/libpciaccess/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/libpciaccess-0.14"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)

ExternalProject_Add(glproto
  URL https://www.x.org/archive/individual/proto/glproto-1.4.17.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/glproto-1.4.17
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/glproto-1.4.17/src/glproto/configure" "--prefix=${CMAKE_CURRENT_BINARY_DIR}/glproto-1.4.17"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
)


ExternalProject_Add(libX11
  URL https://www.x.org/archive//individual/lib/libX11-1.6.5.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/libX11-1.6.5
  CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/libX11-1.6.5/src/libX11;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/libX11-1.6.5"
  INSTALL_COMMAND echo "NONE"
)


ExternalProject_Add(qt5_proj
  URL https://download.qt.io/archive/qt/5.5/5.5.0/single/qt-everywhere-opensource-src-5.5.0.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/qt-everywhere-opensource-src-5.5.0
  CONFIGURE_COMMAND echo "NONE"
  BUILD_COMMAND sh "${CMAKE_SOURCE_DIR}/qt_helper.sh" "${CMAKE_CURRENT_BINARY_DIR}/qt-everywhere-opensource-src-5.5.0/src/qt5_proj;$ENV{PKG_CONFIG_PATH};${CMAKE_CURRENT_BINARY_DIR}/qt-everywhere-opensource-src-5.5.0;${INCLUDE_DIRS};${LIB_DIRS}"
  INSTALL_COMMAND echo "NONE"

)





MESSAGE($ENV{PKG_CONFIG_PATH})


ExternalProject_Get_Property(qt5_proj install_dir)

add_library(qt5 STATIC IMPORTED)



set_property(TARGET qt5 PROPERTY IMPORTED_LOCATION ${install_dir}/lib/qt-everywhere-opensource-src-5.5.0)

#find_package(LLVM REQUIRED)
#find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui Svg OpenGL)

include_directories("${PROJECT_SOURCE_DIR}/include")

#qt5_wrap_ui(UI_HEADERS src/mainwindow.ui)

set(SOURCES
src/main.cpp
src/mainwindow.cpp
src/celestialbody.cpp
src/orbitaltrack.cpp
src/solarsystem.cpp
)

#qt5_wrap_cpp(SOURCES include/celestialbody.h include/orbitaltrack.h include/solarsystem.h include/mainwindow.h)

add_executable(qt_solar_clock ${SOURCES} ${UI_HEADERS})

set_target_properties(qt_solar_clock PROPERTIES AUTOMOC TRUE)

add_dependencies(xproto util-macros)
add_dependencies(libXau xproto)
add_dependencies(libpthread-stubs libXau)
add_dependencies(xcb-proto libpthread-stubs)
add_dependencies(libxcb xcb-proto)



add_dependencies(libX11 xextproto)
add_dependencies(libX11 xtrans)
add_dependencies(libX11 kbproto)
add_dependencies(libX11 inputproto)
add_dependencies(libX11 libxcb)

add_dependencies(libXext libX11)
add_dependencieS(libXdamage damageproto)
add_dependencies(libXdamage fixesproto)
add_dependencies(libXdamage libXfixes)
add_dependencies(libXdamage libX11)

add_dependencies(libdrm libpciaccess)


add_dependencies(mesa libdrm)
add_dependencies(mesa zlib)
add_dependencies(mesa xextproto)
add_dependencies(mesa glproto)
add_dependencies(mesa libXext)
add_dependencies(mesa libXdamage)
add_dependencies(mesa dri2proto)
add_dependencies(mesa libX11)
add_dependencies(mesa libxshmfence)
add_dependencies(mesa libXfixes)
add_dependencies(mesa expat)

add_dependencies(xcb-util m4)

add_dependencies(xcb-util-wm xcb-util)
add_dependencies(xcb-util-wm m4)
add_dependencies(xcb-util-wm libxcb)

add_dependencies(qt5_proj xcb-util-wm)
add_dependencies(qt5_proj freetype)
add_dependencies(qt5_proj libxcb)
add_dependencies(qt5_proj mesa)
add_dependencies(qt5_proj pcre)
add_dependencies(qt5_proj libX11)

add_dependencies(qt_solar_clock qt5_proj)

# Use the Widgets module from Qt 5.
target_link_libraries(qt_solar_clock qt5)








