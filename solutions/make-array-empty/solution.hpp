#pragma once

#include <numeric>
#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static long long countOperationsToEmptyArray(const std::vector<int> &nums) {
    std::vector<int> indexes(nums.size());
    std::iota(indexes.begin(), indexes.end(), 0);
    std::ranges::sort(indexes, [&](int i, int j) { return nums[i] < nums[j]; });

    long long ans = nums.size();
    for (int i = 1; i < std::ssize(nums); ++i) {
      if (indexes[i] < indexes[i - 1]) {
        ans += nums.size() - i;
      }
    }
    return ans;
  }
};
