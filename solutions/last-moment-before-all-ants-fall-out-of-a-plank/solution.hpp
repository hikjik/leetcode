#pragma once

#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int getLastMoment(int n, const std::vector<int> &left,
                           const std::vector<int> &right) {
    return std::max(left.empty() ? 0 : std::ranges::max(left),
                    right.empty() ? 0 : n - std::ranges::min(right));
  }
};
