#pragma once

#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int sumCounts(const std::vector<int> &nums) {
    int ans = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      std::unordered_set<int> set;
      for (size_t j = i; j < nums.size(); ++j) {
        set.insert(nums[j]);
        ans += set.size() * set.size();
      }
    }
    return ans;
  }
};
