#pragma once

#include <vector>

class Solution {
public:
  static int subsetXORSum(const std::vector<int> &nums) {
    return subsetXORSum(0, 0, nums);
  }

private:
  static int subsetXORSum(size_t i, int xorTotal,
                          const std::vector<int> &nums) {
    if (i == nums.size()) {
      return xorTotal;
    }
    return subsetXORSum(i + 1, xorTotal, nums) +
           subsetXORSum(i + 1, xorTotal ^ nums[i], nums);
  }
};
