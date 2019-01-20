cmake_minimum_required(2.8.8)
project(quick_seek)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)

set(quick_seek_SRC
  src/main.cpp
  src/controller.cpp
  src/model.cpp
  src/prefix_tree.cpp
  src/qt_mainwindow.cpp
  src/qt_scan_window.cpp
  src/view.cpp
  forms/main_window.ui
  forms/scan_window.ui
)

add_executable(quick_seek WIN32 ${quick_seek_SRC})
target_link_libraries(quick_seek Qt5::Widgets)