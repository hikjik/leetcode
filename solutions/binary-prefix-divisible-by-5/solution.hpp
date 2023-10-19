#pragma once

#include <vector>

class Solution {
public:
  static std::vector<bool> prefixesDivBy5(const std::vector<int> &nums) {
    std::vector<bool> ans(nums.size());
    for (int i = 0, num = 0; i < std::ssize(nums); ++i) {
      num = (num * 2 + nums[i]) % 5;
      ans[i] = num == 0;
    }
    return ans;
  }
};
