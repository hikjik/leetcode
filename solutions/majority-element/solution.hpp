#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int majorityElement(const std::vector<int> &nums) {
    int ans = 0;
    for (int cnt = 0; auto num : nums) {
      if (!cnt) {
        ans = num;
      }
      cnt += ans == num ? 1 : -1;
    }
    return ans;
  }
};
