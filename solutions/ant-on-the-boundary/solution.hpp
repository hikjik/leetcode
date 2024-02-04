#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int returnToBoundaryCount(const std::vector<int> &nums) {
    int ans = 0;
    for (int sum = 0; auto num : nums) {
      sum += num;
      ans += !sum;
    }
    return ans;
  }
};
