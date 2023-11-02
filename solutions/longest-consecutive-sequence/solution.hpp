#pragma once

#include <algorithm>
#include <unordered_set>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int longestConsecutive(const std::vector<int> &nums) {
    std::unordered_set<int> set(nums.begin(), nums.end());
    int longest = 0;
    for (auto num : nums) {
      if (set.count(num - 1)) {
        continue;
      }

      int length = 1;
      while (set.count(num + 1)) {
        length++;
        num++;
      }
      longest = std::max(longest, length);
    }
    return longest;
  }
};
