#pragma once

#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static std::vector<int> rearrangeArray(const std::vector<int> &nums) {
    std::vector<int> ans(nums.size());
    int pos = -2, neg = -1;
    for (auto a : nums) {
      ans[a > 0 ? pos += 2 : neg += 2] = a;
    }
    return ans;
  }
};
