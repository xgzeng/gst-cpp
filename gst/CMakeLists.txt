include_directories(${GStreamer_INCLUDE_DIRS})

add_library(gst-cpp
    error.hpp error.cpp
    pipeline.hpp pipeline.cpp
    pipeline_builder.hpp pipeline_builder.cpp
    element.hpp element.cpp
    element_factory.hpp element_factory.cpp
    gst.hpp gst.cpp
)

target_link_libraries(gst-cpp PUBLIC gstreamer-1.0 gobject-2.0)

