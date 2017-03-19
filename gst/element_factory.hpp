#pragma once

#include <gst/element.hpp>

namespace gst {

class ElementFactory {
public:
  static ElementRef Make(const char* factory_name,
                         const char* element_name = nullptr);

};

} // namespace gst
