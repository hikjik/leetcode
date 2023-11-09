#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static void rotate(std::vector<int> &nums, int k) {
    k = nums.size() - k % nums.size();
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
    std::reverse(nums.begin(), nums.end());
  }
};
