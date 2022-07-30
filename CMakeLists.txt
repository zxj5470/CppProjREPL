cmake_minimum_required(VERSION 3.5)

project(CppProjREPL LANGUAGES CXX)

add_subdirectory(lua)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(LuaBridge)

add_executable(CppProjREPL
  main.cpp
  Widget.cpp
  Widget.h
  Widget.ui

  MyLib.h
  MyLib.cpp
)

target_link_libraries(CppProjREPL lua Qt5::Widgets)
