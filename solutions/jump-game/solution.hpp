#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool canJump(const std::vector<int> &nums) {
    for (int i = 0, reach = 0; i < std::ssize(nums); ++i) {
      if (reach < i) {
        return false;
      }
      reach = std::max(reach, i + nums[i]);
    }
    return true;
  }
};
