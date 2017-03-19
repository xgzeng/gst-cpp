#pragma once

#include <gst/pipeline.hpp>
#include <vector>

namespace gst {

class PipelineBuilder {
public:
  PipelineBuilder();

  Pipeline FinishBuild();

  ElementRef AddElement(const char* plugin_name, const char* name = nullptr);

  ElementRef AddElementToTail(const char* plugin_name, const char* name = nullptr);

private:
  Pipeline pipeline_;
  std::vector<ElementRef> elements_;
};

} // namespace gst
