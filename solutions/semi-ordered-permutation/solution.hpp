#pragma once

#include <vector>

class Solution {
public:
  static int semiOrderedPermutation(const std::vector<int> &nums) {
    const int n = nums.size();
    const int first = find(nums.begin(), nums.end(), 1) - nums.begin();
    const int last = find(nums.rbegin(), nums.rend(), n) - nums.rbegin();
    return first + last - (last + first >= n);
  }
};
