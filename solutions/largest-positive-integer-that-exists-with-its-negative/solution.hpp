#pragma once

#include <unordered_set>
#include <vector>

class Solution {
public:
  static int findMaxK(const std::vector<int> &nums) {
    std::unordered_set<int> set;
    int max = -1;
    for (auto num : nums) {
      if (set.contains(-num)) {
        max = std::max(max, std::abs(num));
      }
      set.insert(num);
    }
    return max;
  }
};
