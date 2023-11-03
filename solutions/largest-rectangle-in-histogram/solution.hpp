#pragma once

#include <stack>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace two_pass {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static int largestRectangleArea(const std::vector<int> &heights) {
    const int n = heights.size();

    std::vector<int> left_smaller(n, -1), right_smaller(n, n);
    std::stack<int> stack{{-1}};
    for (int i = 0; i < n; ++i) {
      while (stack.top() != -1 && heights[stack.top()] > heights[i]) {
        right_smaller[stack.top()] = i;
        stack.pop();
      }
      if (i && heights[i] == heights[i - 1]) {
        left_smaller[i] = left_smaller[i - 1];
      } else {
        left_smaller[i] = stack.top();
      }
      stack.push(i);
    }

    int area = 0;
    for (int i = 0; i < n; ++i) {
      area =
          std::max(area, heights[i] * (right_smaller[i] - left_smaller[i] - 1));
    }
    return area;
  }
};

} // namespace two_pass

namespace one_pass {

// Time: O(N)
// Space: O(N)
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

} // namespace one_pass
