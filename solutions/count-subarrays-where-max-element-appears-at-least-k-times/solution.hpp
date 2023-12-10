#pragma once

#include <ranges>
#include <unordered_map>
#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static long long countSubarrays(const std::vector<int> &nums, int k) {
    const int max = std::ranges::max(nums);
    const int n = nums.size();

    std::unordered_map<int, int> cnt;
    auto ans = n * (n + 1LL) / 2;
    for (int l = 0, r = 0; r < std::ssize(nums); ++r) {
      ++cnt[nums[r]];
      while (cnt[max] >= k) {
        --cnt[nums[l++]];
      }
      ans -= r - l + 1;
    }
    return ans;
  }
};
