#pragma once

#include <unordered_set>
#include <vector>

class Solution {
public:
  static bool containsNearbyDuplicate(const std::vector<int> &nums, size_t k) {
    std::unordered_set<int> set;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (set.count(nums[i])) {
        return true;
      }
      set.insert(nums[i]);
      if (i >= k) {
        set.erase(nums[i - k]);
      }
    }
    return false;
  }
};
