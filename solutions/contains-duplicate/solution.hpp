#pragma once

#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static bool containsDuplicate(const std::vector<int> &nums) {
    std::unordered_set<int> set;
    for (auto num : nums) {
      if (set.find(num) != set.end()) {
        return true;
      }
      set.insert(num);
    }
    return false;
  }
};
