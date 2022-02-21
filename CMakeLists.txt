cmake_minimum_required(VERSION 3.22)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(starter_project LANGUAGES CXX)

add_library(projectStandards INTERFACE)
target_compile_features(projectStandards INTERFACE cxx_std_20)

add_subdirectory(vendor/glfw)

include_directories(vendor/glfw/include)

set(SOURCE_FILES
  src/Main.cpp

  src/Application.cpp
  src/Application.h

  src/Events/Event.h
  src/Events/WindowEvents.h

  src/Window.cpp
  src/Window.h
)

add_executable(project ${SOURCE_FILES})

target_link_libraries(project PRIVATE projectStandards)
target_link_libraries(project PRIVATE GL)
target_link_libraries(project PRIVATE glfw)
