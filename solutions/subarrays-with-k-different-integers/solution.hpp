#pragma once

#include <vector>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static int subarraysWithKDistinct(std::vector<int> &nums, int k) {
    return DistinctAtMostK(nums, k) - DistinctAtMostK(nums, k - 1);
  }

private:
  static int DistinctAtMostK(const std::vector<int> &nums, int k) {
    std::vector<int> counter(nums.size() + 1);
    int distinct_count = 0;

    int ans = 0;
    for (int l = 0, r = 0; r < std::ssize(nums); ++r) {
      distinct_count += counter[nums[r]]++ == 0;
      while (distinct_count > k) {
        distinct_count -= counter[nums[l++]]-- == 1;
      }
      ans += r - l + 1;
    }
    return ans;
  }
};
