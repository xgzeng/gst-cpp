#include <gst/error.hpp>

namespace gst {

GstError::GstError(const char* error_msg)
: std::runtime_error(error_msg) {
}

} // namespace gst
