#pragma once

#include <climits>
#include <ranges>
#include <vector>

// Time: O(N+M), M = max(nums)
// Space: O(M)

namespace sorting {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int partitionArray(std::vector<int> nums, int k) {
    std::ranges::sort(nums);
    int ans = 0;
    for (int min = INT_MIN; auto num : nums) {
      if (num - k > min) {
        min = num;
        ++ans;
      }
    }
    return ans;
  }
};

} // namespace sorting

namespace counting {

// Time: O(N+M), M = max(nums)
// Space: O(M)
class Solution {
public:
  static int partitionArray(const std::vector<int> &nums, int k) {
    std::vector<int> cnt(std::ranges::max(nums) + 1);
    for (auto num : nums) {
      ++cnt[num];
    }

    int ans = 0;
    for (int i = 0; i < std::ssize(cnt); ++i) {
      if (cnt[i]) {
        ++ans;
        i += k;
      }
    }
    return ans;
  }
};

} // namespace counting
