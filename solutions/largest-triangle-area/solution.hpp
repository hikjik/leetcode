#pragma once

#include <cmath>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static double
  largestTriangleArea(const std::vector<std::vector<int>> &points) {
    double area = 0;
    for (size_t i = 0; i + 2 < points.size(); ++i) {
      for (size_t j = i + 1; j + 1 < points.size(); ++j) {
        for (size_t k = j + 1; k < points.size(); ++k) {
          area = std::max(area,
                          computeTriangleArea(points[i], points[j], points[k]));
        }
      }
    }
    return area;
  }

private:
  static double computeTriangleArea(const std::vector<int> &first,
                                    const std::vector<int> &second,
                                    const std::vector<int> &third) {
    return 0.5 * std::abs((second[0] - first[0]) * (third[1] - first[1]) -
                          (third[0] - first[0]) * (second[1] - first[1]));
  }
};
