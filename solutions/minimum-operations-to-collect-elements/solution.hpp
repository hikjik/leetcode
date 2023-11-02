#pragma once

#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int minOperations(const std::vector<int> &nums, int k) {
    std::unordered_set<int> set;
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] <= k) {
        set.insert(nums[i]);
        if (set.size() == k * 1ULL) {
          return nums.size() - i;
        }
      }
    }
    throw;
  }
};
