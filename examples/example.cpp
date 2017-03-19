#include <gst/pipeline_builder.hpp>
#include <gst/gst.hpp>

int main(int argc, char* argv[]) {
  gst::Initialize(&argc, &argv);

  gst::PipelineBuilder builder;

  builder.AddElement("autovideosrc");

  builder.AddElementToTail("autovideosink");

  gst::Pipeline pipeline = builder.FinishBuild();

  pipeline.Play();

  auto loop = g_main_loop_new(NULL, FALSE);
  g_main_loop_run(loop);
  return 0;
}

