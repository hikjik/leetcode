#pragma once

#include <vector>

class Solution {
public:
  static int removeDuplicates(std::vector<int> &nums) {
    int size = 1;
    for (size_t i = 0; i < nums.size(); ++i) {
      if (!i || nums[i] == nums[i - 1]) {
        size--;
      }
      nums[size++] = nums[i];
    }
    return size;
  }
};
