#pragma once

#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
  static int distinctAverages(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());

    std::unordered_set<int> set;
    for (size_t i = 0; i < nums.size(); ++i) {
      set.insert(nums[i] + nums[nums.size() - 1 - i]);
    }
    return set.size();
  }
};
