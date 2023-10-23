#pragma once

#include <numeric>
#include <ranges>
#include <vector>

class Solution {
public:
  static std::vector<int> targetIndices(const std::vector<int> &nums,
                                        int target) {
    std::vector<int> ans(std::ranges::count(nums, target));
    std::iota(ans.begin(), ans.end(),
              std::ranges::count_if(nums, [=](int a) { return a < target; }));
    return ans;
  }
};
