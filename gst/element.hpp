#pragma once

#include <gst/typed_ref.hpp>
#include <gst/gstelement.h>

namespace gst {

class ElementRef : public TypedRef<GstElement> {
public:
  using TypedRef::TypedRef;
};

void LinkElement(ElementRef src, ElementRef dest);

} // namespace gst

