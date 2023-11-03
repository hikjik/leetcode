#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int removeDuplicates(std::vector<int> &nums) {
    int size = 0;
    for (auto num : nums) {
      if (size < 2 || num != nums[size - 2]) {
        nums[size++] = num;
      }
    }
    return size;
  }
};
