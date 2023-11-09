#pragma once

#include <cmath>
#include <ranges>
#include <unordered_map>
#include <vector>

// Time: O(N^2)
// Space: O(N)

namespace naive {

// Time: O(N^3)
// Space: O(N)
class Solution {
public:
  static int maxPoints(const std::vector<std::vector<int>> &points) {
    int ans = 1;
    for (int i = 0; i < std::ssize(points); ++i) {
      for (int j = i + 1; j < std::ssize(points); ++j) {
        const auto dx = points[i][0] - points[j][0];
        const auto dy = points[i][1] - points[j][1];
        const int cnt = std::ranges::count_if(points, [&](const auto &p) {
          return (p[0] - points[i][0]) * dy == (p[1] - points[i][1]) * dx;
        });
        ans = std::max(ans, cnt);
      }
    }
    return ans;
  }
};

} // namespace naive

namespace efficient {

// Time: O(N^2)
// Space: O(N)
class Solution {
public:
  static int maxPoints(std::vector<std::vector<int>> points) {
    std::ranges::sort(points);
    int ans = 0;
    for (int i = 0; i < std::ssize(points); ++i) {
      std::unordered_map<double, int> counter;
      for (int j = i + 1; j < std::ssize(points); ++j) {
        const auto atan2 = std::atan2(points[j][1] - points[i][1],
                                      points[j][0] - points[i][0]);
        ans = std::max(ans, ++counter[atan2]);
      }
    }
    return ans + 1;
  }
};

} // namespace efficient
