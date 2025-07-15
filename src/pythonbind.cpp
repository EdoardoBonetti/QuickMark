#include <comp.hpp>
#include <python_comp.hpp>

#include "quickmark.hpp"  // Include the header for ngafem


PYBIND11_MODULE(quickmark, m) {
        // compute_xStar gets a vector and a double
  m.def("ComputeXStar", &nsquickmark::compute_xStar, "Compute xStar value from eta vector and theta value");
}
