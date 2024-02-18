#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int maxOperations(const std::vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i + 1 < std::ssize(nums); i += 2) {
      if (nums[i] + nums[i + 1] == nums[0] + nums[1]) {
        ++ans;
      } else {
        break;
      }
    }
    return ans;
  }
};
