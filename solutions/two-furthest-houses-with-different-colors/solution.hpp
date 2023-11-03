#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxDistance(const std::vector<int> &colors) {
    size_t left = 0, right = colors.size() - 1;
    while (colors[left] == colors.back()) {
      ++left;
    }
    while (colors.front() == colors[right]) {
      --right;
    }
    return std::max(right, colors.size() - left - 1);
  }
};
