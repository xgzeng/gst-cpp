#pragma once

#include <stdexcept>

namespace gst {

class GstError : public std::runtime_error {
public:
  GstError(const char* error_msg);

};

} // namespace gst
