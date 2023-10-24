#pragma once

#include <numeric>
#include <vector>

class Solution {
public:
  static constexpr int kMaxValue = 100;

  static std::vector<int>
  smallerNumbersThanCurrent(const std::vector<int> &nums) {
    std::vector<int> counter(kMaxValue + 1);
    for (auto a : nums) {
      ++counter[a];
    }

    std::partial_sum(counter.begin(), counter.end(), counter.begin());

    std::vector<int> ans(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
      ans[i] = nums[i] ? counter[nums[i] - 1] : 0;
    }
    return ans;
  }
};
