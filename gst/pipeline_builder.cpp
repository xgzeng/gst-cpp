#include <gst/pipeline_builder.hpp>
#include <gst/element_factory.hpp>

#include <utility>
#include <cassert>

namespace gst {

PipelineBuilder::PipelineBuilder() {
}

Pipeline PipelineBuilder::FinishBuild() {
  return std::move(pipeline_);
}

ElementRef PipelineBuilder::AddElement(const char* plugin_name, const char* name) {
  assert(plugin_name);

  auto e = ElementFactory::Make(plugin_name, name);
  pipeline_.Add(e);
  elements_.push_back(e);
  return e;
}

ElementRef PipelineBuilder::AddElementToTail(const char* plugin_name, const char* name) {
  ElementRef last;
  if (!elements_.empty()) {
    last = elements_.back();
  }

  auto new_element = AddElement(plugin_name, name);

  try {
    LinkElement(last, new_element);
  } catch (...) {
    pipeline_.Remove(new_element);
    elements_.pop_back();
    throw;
  }

  return new_element;
}

} // namespace gst
