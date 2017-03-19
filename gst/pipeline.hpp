#pragma once

#include <gst/typed_ref.hpp>
#include <gst/element.hpp>

#include <gst/gstpipeline.h>

namespace gst {

class Pipeline {
public:
  Pipeline();

  Pipeline(const char* name);

  // move constructor
  Pipeline(Pipeline&&);

  // disable object copy
  Pipeline(const Pipeline&) = delete;
  Pipeline& operator=(const Pipeline&) = delete;

  // bin_add
  void Add(ElementRef e);

  // bin_remove
  void Remove(ElementRef e);

  void Play();

private:
  TypedRef<GstPipeline> p_impl_;
};

} // namespace gst

