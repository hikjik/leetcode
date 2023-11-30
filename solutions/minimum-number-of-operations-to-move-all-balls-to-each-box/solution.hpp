#pragma once

#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::vector<int> minOperations(std::string boxes) {
    std::vector<int> ans(boxes.size());
    for (int ops = 0, cnt = 0, i = 0; i < std::ssize(boxes); ++i) {
      ans[i] += ops;
      ops += cnt += boxes[i] == '1';
    }
    for (int ops = 0, cnt = 0, i = boxes.size() - 1; i >= 0; --i) {
      ans[i] += ops;
      ops += cnt += boxes[i] == '1';
    }
    return ans;
  }
};
