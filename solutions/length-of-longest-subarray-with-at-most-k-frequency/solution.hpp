#pragma once

#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int maxSubarrayLength(const std::vector<int> &nums, int k) {
    std::unordered_map<int, int> cnt;
    int ans = 0;
    for (int l = 0, r = 0; r < std::ssize(nums); ++r) {
      ++cnt[nums[r]];
      while (cnt[nums[r]] > k) {
        --cnt[nums[l++]];
      }
      ans = std::max(ans, r - l + 1);
    }
    return ans;
  }
};
