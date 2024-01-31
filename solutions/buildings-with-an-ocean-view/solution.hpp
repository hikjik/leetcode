#pragma once

#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int> findBuildings(const std::vector<int> &heights) {
    std::vector<int> stack;
    for (int i = 0; i < std::ssize(heights); ++i) {
      while (!stack.empty() && heights[stack.back()] <= heights[i]) {
        stack.pop_back();
      }
      stack.push_back(i);
    }
    return stack;
  }
};
