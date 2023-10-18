#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static std::vector<int> separateDigits(const std::vector<int> &nums) {
    std::vector<int> ans;
    for (int i = nums.size() - 1; i >= 0; --i) {
      for (auto num = nums[i]; num; num /= 10) {
        ans.push_back(num % 10);
      }
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
};
