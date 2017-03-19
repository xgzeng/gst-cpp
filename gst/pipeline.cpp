#include <gst/pipeline.hpp>
#include <gst/error.hpp>

#include <gst/gstpipeline.h>
#include <cassert>

namespace gst {

Pipeline::Pipeline()
: Pipeline("default_pipeline") {
}

Pipeline::Pipeline(Pipeline&& other)
: p_impl_(std::move(other.p_impl_)) {
}

Pipeline::Pipeline(const char* name) {
  TypedRef<GstPipeline> impl{ GST_PIPELINE_CAST(gst_pipeline_new(name)) };
  p_impl_ = impl;
}

void Pipeline::Add(ElementRef e) {
  if (!gst_bin_add(GST_BIN(p_impl_.get()), e.get())) {
    throw GstError("gst_bin_add failed");
  }
}

void Pipeline::Remove(ElementRef e) {
  if (!gst_bin_remove(GST_BIN(p_impl_.get()), e.get())) {
    throw GstError("gst_bin_remove failed");
  };
}

void Pipeline::Play() {
  gst_element_set_state(GST_ELEMENT(p_impl_.get()), GST_STATE_PLAYING);
}

} // namespace gst

