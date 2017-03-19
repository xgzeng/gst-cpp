#include <gst/gst.hpp>

#include <gst/gst.h>

namespace gst {

void Initialize(int *argc, char* *argv[]) {
  gst_init(argc, argv);
}

} // namespace gst
