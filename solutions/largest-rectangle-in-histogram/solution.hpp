#pragma once

#include <stack>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int largestRectangleArea(const std::vector<int> &heights) {
    const int n = heights.size();
    std::stack<int> stack;
    int max_area = 0;
    for (int i = 0; i <= n; ++i) {
      while (!stack.empty() && (i == n || heights[stack.top()] > heights[i])) {
        const auto height = heights[stack.top()];
        stack.pop();
        const auto width = stack.empty() ? i : i - stack.top() - 1;
        max_area = std::max(max_area, height * width);
      }
      stack.push(i);
    }
    return max_area;
  }
};
