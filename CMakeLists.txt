cmake_minimum_required(VERSION 3.22)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(starter_project LANGUAGES CXX)

add_subdirectory(vendor/glfw)

include_directories(vendor/glfw/include)

set(SOURCE_FILES
  src/Main.cpp

  src/Application.cpp
  src/Application.h

  src/Events/Event.h
  src/Events/WindowEvents.h
)

add_executable(project ${SOURCE_FILES})

target_link_libraries(project PRIVATE GL)
target_link_libraries(project PRIVATE glfw)
