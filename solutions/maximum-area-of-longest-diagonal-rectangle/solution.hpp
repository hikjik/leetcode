#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int
  areaOfMaxDiagonal(const std::vector<std::vector<int>> &dimensions) {
    const auto max =
        std::ranges::max(dimensions, [](const auto &a, const auto &b) {
          return std::make_tuple(a[0] * a[0] + a[1] * a[1], a[0] * a[1]) <
                 std::make_tuple(b[0] * b[0] + b[1] * b[1], b[0] * b[1]);
        });
    return max[0] * max[1];
  }
};
