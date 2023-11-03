#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxNumOfMarkedIndices(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());

    auto end = nums.end();
    auto begin = nums.begin() + nums.size() / 2;
    int total = 0;
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
      if (auto it = std::lower_bound(begin, end, 2 * nums[i]); it != end) {
        total += 2;
        end = std::prev(end);
      }
    }
    return total;
  }
};
