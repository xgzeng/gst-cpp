#include <gst/element_factory.hpp>
#include <gst/error.hpp>

#include <gst/gstelementfactory.h>

namespace gst {

ElementRef ElementFactory::Make(const char* factory_name,
                                const char* element_name) {
  GstElement* e = gst_element_factory_make(factory_name, element_name);
  if (!e) {
    throw GstError("make element failed");
  }

  return ElementRef(e);
}

} // namespace gst

