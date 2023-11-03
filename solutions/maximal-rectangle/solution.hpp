#pragma once

#include <stack>
#include <vector>

// Time: O(MN)
// Space: O(N)

class Solution {
public:
  static int maximalRectangle(const std::vector<std::vector<char>> &matrix) {
    const int m = matrix.size(), n = matrix.back().size();

    int max_rectangle = 0;
    std::vector<int> heights(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
      }
      max_rectangle = std::max(max_rectangle, largestRectangleArea(heights));
    }
    return max_rectangle;
  }

private:
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
