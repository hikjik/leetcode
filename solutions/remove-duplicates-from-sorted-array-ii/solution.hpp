#pragma once

#include <vector>

class Solution {
public:
  static int removeDuplicates(std::vector<int> &nums) {
    size_t size = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (i < 2 || nums[i] != nums[size - 2]) {
        nums[size++] = nums[i];
      }
    }
    return size;
  }
};
