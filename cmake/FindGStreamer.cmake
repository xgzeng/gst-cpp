find_path(GSTREAMER_INCLUDE_DIR
    "gst/gst.h"
    PATH_SUFFIXES gstreamer-1.0
)

find_path(GLIB_INCLUDE_DIR
    "glib.h"
    PATH_SUFFIXES "glib-2.0"
)

find_path(GLIB_CONFIG_INCLUDE_DIR
    "glibconfig.h"
    HINTS "/usr/local/lib"
    PATH_SUFFIXES "glib-2.0/include"
)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(GStreamer DEFAULT_MSG
    GSTREAMER_INCLUDE_DIR GLIB_INCLUDE_DIR
    GLIB_CONFIG_INCLUDE_DIR
)

if(GStreamer_FOUND)
    set(GStreamer_INCLUDE_DIRS
        "${GSTREAMER_INCLUDE_DIR}" "${GLIB_INCLUDE_DIR}" "${GLIB_CONFIG_INCLUDE_DIR}")
endif()

