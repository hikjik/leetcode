#pragma once

#include <vector>

// Time: O(NlogM)
// Space: O(1)

class Solution {
public:
  static int minOrAfterOperations(const std::vector<int> &nums, int k) {
    int ans = 0;
    int mask = 0;
    for (int i = 30; i >= 0; --i) {
      mask |= 1 << i;
      if (countOps(nums, mask, ans) > k) {
        ans |= 1 << i;
      }
    }
    return ans;
  }

private:
  static int countOps(const std::vector<int> &nums, int source, int target) {
    int ops = 0;
    for (int sum = source; auto num : nums) {
      sum &= num;
      if ((sum | target) == target) {
        sum = source;
      } else {
        ++ops;
      }
    }
    return ops;
  }
};
