#pragma once

#include <ranges>
#include <vector>

// Time: O(NLogN)
// Space: O(N)

namespace bf {

// Time: O(N^2)
// Space: O(1)
class Solution {
public:
  static int twoSumLessThanK(const std::vector<int> &nums, int k) {
    int ans = -1;
    for (int i = 0; i < std::ssize(nums); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] + nums[j] < k) {
          ans = std::max(ans, nums[i] + nums[j]);
        }
      }
    }
    return ans;
  }
};

} // namespace bf

namespace sorting {

// Time: O(NLogN)
// Space: O(N)
class Solution {
public:
  static int twoSumLessThanK(std::vector<int> nums, int k) {
    std::ranges::sort(nums);

    int ans = -1;
    for (int i = 0, j = nums.size() - 1; i < j;) {
      if (nums[i] + nums[j] < k) {
        ans = std::max(ans, nums[i] + nums[j]);
        ++i;
      } else {
        --j;
      }
    }
    return ans;
  }
};

} // namespace sorting

namespace counting {

// Time: O(N+K)
// Space: O(K)
class Solution {
public:
  static int twoSumLessThanK(const std::vector<int> &nums, int k) {
    std::vector<int> cnt(k);
    for (auto num : nums) {
      if (num < k) {
        ++cnt[num];
      }
    }

    int ans = -1;
    for (int i = 1, j = k - 1; i <= j;) {
      if (i + j >= k || !cnt[j]) {
        --j;
      } else {
        if (cnt[i] > (i == j)) {
          ans = std::max(ans, i + j);
        }
        ++i;
      }
    }
    return ans;
  }
};

} // namespace counting
