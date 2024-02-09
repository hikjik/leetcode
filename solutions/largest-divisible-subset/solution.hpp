#pragma once

#include <ranges>
#include <vector>

// Time:  O(N^2)
// Space: O(N)

class Solution {
public:
  static std::vector<int> largestDivisibleSubset(std::vector<int> nums) {
    std::ranges::sort(nums);

    std::vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
    for (int i = 0; i < std::ssize(nums); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
        }
      }
    }

    std::vector<int> ans;
    for (int i = std::ranges::max_element(dp) - dp.begin(); i != -1;
         i = prev[i]) {
      ans.push_back(nums[i]);
    }
    return ans;
  }
};
