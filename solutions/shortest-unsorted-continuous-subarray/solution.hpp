#pragma once

#include <numeric>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace sorting {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int findUnsortedSubarray(const std::vector<int> &nums) {
    auto sorted = nums;
    std::ranges::sort(sorted);

    int l = nums.size(), r = 0;
    for (int i = 0; i < std::ssize(nums); ++i) {
      if (nums[i] != sorted[i]) {
        l = std::min(l, i);
        r = std::max(r, i);
      }
    }
    return r >= l ? r - l + 1 : 0;
  }
};

} // namespace sorting

namespace opt {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static int findUnsortedSubarray(const std::vector<int> &nums) {
    const int n = nums.size();

    int max = INT_MIN;
    int r = 0;
    for (int i = 0; i < n; ++i) {
      if (max > nums[i]) {
        r = i;
      }
      max = std::max(max, nums[i]);
    }

    int min = INT_MAX;
    int l = n;
    for (int i = n - 1; i >= 0; --i) {
      if (min < nums[i]) {
        l = i;
      }
      min = std::min(min, nums[i]);
    }

    return r >= l ? r - l + 1 : 0;
  }
};

} // namespace opt
