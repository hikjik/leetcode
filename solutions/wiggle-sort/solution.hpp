#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static void wiggleSort(std::vector<int> &nums) {
    for (int i = 0; i + 1 < std::ssize(nums); ++i) {
      if ((i & 1) == nums[i] < nums[i + 1]) {
        std::swap(nums[i], nums[i + 1]);
      }
    }
  }
};
