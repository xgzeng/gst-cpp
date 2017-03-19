cmake_minimum_required(VERSION 3.7)

project(gst-cpp)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 11)

find_package(GStreamer REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(gst)

add_subdirectory(examples)

