#include <gst/element.hpp>
#include <gst/error.hpp>

#include <gst/gstutils.h>

namespace gst {

void LinkElement(ElementRef src, ElementRef dest) {
  if (!gst_element_link(src.get(), dest.get())) {
    throw GstError("gst_element_link failed");
  }
}

} // namespace gst
