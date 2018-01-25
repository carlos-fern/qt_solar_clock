cmake_minimum_required(VERSION 2.8.11)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
project(qt_solar_clock)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../)

ExternalProject_Add(qt5
  URL https://download.qt.io/archive/qt/5.5/5.5.0/single/qt-everywhere-opensource-src-5.5.0.tar.gz
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}/qt-everywhere-opensource-src-5.5.0
  CONFIGURE_COMMAND "${CMAKE_CURRENT_BINARY_DIR}/qt-everywhere-opensource-src-5.5.0/src/qt5/configure" "-opensource;-confirm-license;-qt-xcb;-no-compile-examples;-static;-release"
  BUILD_COMMAND make
  INSTALL_COMMAND make install
  PREFIX=${CMAKE_CURRENT_BINARY_DIR}/qt-everywhere-opensource-src-5.5.0
)




find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui Svg OpenGL)

include_directories("${PROJECT_SOURCE_DIR}/include")

qt5_wrap_ui(UI_HEADERS src/mainwindow.ui) 

set(SOURCES
src/main.cpp 
src/mainwindow.cpp 
src/celestialbody.cpp 
src/orbitaltrack.cpp 
src/solarsystem.cpp  
)

qt5_wrap_cpp(SOURCES include/celestialbody.h include/orbitaltrack.h include/solarsystem.h include/mainwindow.h)

add_executable(qt_solar_clock ${SOURCES} ${UI_HEADERS})

set_target_properties(qt_solar_clock PROPERTIES AUTOMOC TRUE)

add_dependencies(qt_solar_clock qt5)

# Use the Widgets module from Qt 5.
target_link_libraries(qt_solar_clock Qt5::Widgets Qt5::Gui Qt5::Core Qt5::Svg Qt5::OpenGL )



