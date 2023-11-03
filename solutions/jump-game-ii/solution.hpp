#pragma once

#include <algorithm>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int jump(const std::vector<int> &nums) {
    int jumps = 0;
    int max_reach = 0, cur_reach = 0;
    for (int i = 0; i + 1 < std::ssize(nums); ++i) {
      max_reach = std::max(max_reach, i + nums[i]);
      if (cur_reach == i) {
        ++jumps;
        cur_reach = max_reach;
      }
    }
    return jumps;
  }
};
