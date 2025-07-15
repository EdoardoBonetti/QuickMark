
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>  // For automatic conversion between C++ STL containers and Python lists
#include <memory>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>
#include "quickmark.hpp"


namespace nsquickmark {

    const double xStarKernel(Iterator_t subX_begin, Iterator_t subX_end, double goal)
    {
        // QuickMark , step (i)-(ii): partition by median element
        auto length{std::distance(subX_begin, subX_end)};
        auto subX_middle{subX_begin + length / 2};
        std::nth_element(subX_begin, subX_middle, subX_end, std::greater<double>());
        auto pivot_val{*subX_middle};
        // QuickMark , step (iii)
        auto sigma_g{std::accumulate(subX_begin, subX_middle, (double)0.0)};
        // QuickMark , step (iv), (v) and (vi)
        if (sigma_g >= goal)
            return xStarKernel(subX_begin, subX_middle, goal);
        if (sigma_g + pivot_val >= goal)
            return pivot_val;
        return xStarKernel(++subX_middle, subX_end, goal - sigma_g - pivot_val);
    }

    const double compute_xStar(const std::vector<double>& eta, double theta)
    {
        std::vector<double> x{eta};
        double goal{theta * std::accumulate(x.cbegin(), x.cend(), (double)0.0)};
        return xStarKernel(x.begin(), x.end(), goal);
    }

}  // namespace nsquickmark
