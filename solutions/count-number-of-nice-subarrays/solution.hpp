#pragma once

#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static int numberOfSubarrays(const std::vector<int> &nums, int k) {
    return numberOfSubarraysAtMostK(nums, k) -
           numberOfSubarraysAtMostK(nums, k - 1);
  }

  static int numberOfSubarraysAtMostK(const std::vector<int> &nums, int k) {
    int odd = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < std::ssize(nums); ++r) {
      odd += nums[r] & 1;
      while (odd > k) {
        odd -= nums[l++] & 1;
      }
      ans += r - l + 1;
    }
    return ans;
  }
};
