#pragma once

#include <stack>
#include <vector>

class Solution {
public:
  static std::vector<int> canSeePersonsCount(const std::vector<int> &heights) {
    std::vector<int> ans(heights.size(), 0);
    std::stack<int> stack;
    for (size_t i = 0; i < heights.size(); ++i) {
      while (!stack.empty() && heights[stack.top()] <= heights[i]) {
        ans[stack.top()]++;
        stack.pop();
      }
      if (!stack.empty()) {
        ans[stack.top()]++;
      }
      stack.push(i);
    }
    return ans;
  }
};
