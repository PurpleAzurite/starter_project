cmake_minimum_required(VERSION 3.22)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(starter_project LANGUAGES CXX)

set(SOURCE_FILES
  src/Main.cpp
)

add_executable(project ${SOURCE_FILES})
