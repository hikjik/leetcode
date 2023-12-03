#pragma once

#include <unordered_set>
#include <vector>

// Time: O(N)
// Space: O(K)

class Solution {
public:
  static bool containsNearbyDuplicate(const std::vector<int> &nums, int k) {
    std::unordered_set<int> set;
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (set.contains(nums[i])) {
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
