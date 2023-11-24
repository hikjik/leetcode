#pragma once

#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

namespace stl {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static long long countFairPairs(std::vector<int> nums, int lower, int upper) {
    std::ranges::sort(nums);

    long long ans = 0;
    for (auto it = nums.cbegin(); it != nums.end(); ++it) {
      ans += std::upper_bound(nums.cbegin(), it, upper - *it) -
             std::lower_bound(nums.cbegin(), it, lower - *it);
    }
    return ans;
  }
};

} // namespace stl

namespace two_pointers {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static long long countFairPairs(std::vector<int> nums, int lower, int upper) {
    std::ranges::sort(nums);
    return countPairs(nums, upper) - countPairs(nums, lower - 1);
  }

private:
  static long long countPairs(const std::vector<int> &nums, int upper) {
    long long ans = 0;
    for (int l = 0, r = nums.size() - 1; l < r; ++l) {
      while (l < r && nums[l] + nums[r] > upper) {
        --r;
      }
      ans += r - l;
    }
    return ans;
  }
};

} // namespace two_pointers