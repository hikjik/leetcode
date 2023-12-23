#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static long long largestPerimeter(std::vector<int> nums) {
    std::ranges::sort(nums);
    long long ans = -1;
    for (long long sum = 0; auto num : nums) {
      if (sum > num) {
        ans = sum + num;
      }
      sum += num;
    }
    return ans;
  }
};
