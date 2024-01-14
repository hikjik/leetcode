#pragma once

#include <climits>
#include <stack>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool verifyPreorder(const std::vector<int> &preorder) {
    int min = INT_MIN;
    std::stack<int> stack;
    for (auto val : preorder) {
      while (!stack.empty() && stack.top() < val) {
        min = stack.top();
        stack.pop();
      }
      if (val <= min) {
        return false;
      }
      stack.push(val);
    }
    return true;
  }
};
