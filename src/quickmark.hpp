#ifndef NSQUICKMARK_HPP
#define NSQUICKMARK_HPP

#include <vector>

namespace nsquickmark {

    // Declare Iterator type for better readability
    using Iterator_t = std::vector<double>::iterator;

    // Function declarations
    const double xStarKernel(Iterator_t subX_begin, Iterator_t subX_end, double goal);
    const double compute_xStar(const std::vector<double>& eta, double theta);

}  // namespace quickmark

#endif  // NSQUICKMAK_HPP
