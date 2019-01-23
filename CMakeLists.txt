cmake_minimum_required(VERSION 3.10.0)
project(quick_seek)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)

if(WIN32)
  add_definitions(-D__CONFIG_WINDOWS__)
elseif(UNIX)
  add_definitions(-D__CONFIG_UNIX__)
else()
  message( FATAL_ERROR "Unsupported platform." )  
endif()

find_package(Qt5Widgets CONFIG REQUIRED)
include_directories(./src)
include_directories(./forms)

set(quick_seek_SOURCES
  src/main.cpp
  src/controller.cpp
  src/file_manager.cpp
  src/prefix_tree.cpp
  src/qt_main_window.cpp
  src/qt_scan_window.cpp
  src/qt_view.cpp
  forms/main_window.ui
  forms/scan_window.ui
)

set(quick_seek_HEADERS
  src/controller.hpp
  src/file_manager.hpp
  src/prefix_tree.hpp
  src/qt_main_window.hpp
  src/qt_scan_window.hpp
  src/prefix_tree.hpp
  src/qt_main_window.hpp
  src/qt_scan_window.hpp
  src/qt_view.hpp
  src/view_base.hpp

  src/prefix_tree.tpp
)

add_executable(quick_seek WIN32 ${quick_seek_SOURCES} ${quick_seek_HEADERS})
target_link_libraries(quick_seek Qt5::Widgets)
