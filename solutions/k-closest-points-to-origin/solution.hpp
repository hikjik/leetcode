#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<std::vector<int>>
  kClosest(std::vector<std::vector<int>> points, int k) {
    std::nth_element(points.begin(), points.begin() + k, points.end(),
                     compareByDistance);
    points.resize(k);
    return points;
  }

private:
  static bool compareByDistance(const std::vector<int> &first,
                                const std::vector<int> &second) {
    return distance(first) < distance(second);
  }

  static int distance(const std::vector<int> &point) {
    return point[0] * point[0] + point[1] * point[1];
  }
};
