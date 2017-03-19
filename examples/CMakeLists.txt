include_directories(${GStreamer_INCLUDE_DIRS})

add_executable(example example.cpp)

target_link_libraries(example gst-cpp glib-2.0)
