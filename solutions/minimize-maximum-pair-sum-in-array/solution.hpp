#pragma once

#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

namespace sorting {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int minPairSum(std::vector<int> nums) {
    std::ranges::sort(nums);
    int ans = 0;
    for (int i = 0; i < std::ssize(nums) / 2; ++i) {
      ans = std::max(ans, nums[i] + nums[nums.size() - i - 1]);
    }
    return ans;
  }
};

} // namespace sorting

namespace counting_sort {

// M is the maximum element in the nums array
// N is the length of the array
// Time: O(N+M)
// Space: O(M)
class Solution {
public:
  static int minPairSum(std::vector<int> nums) {
    std::vector<int> counter(std::ranges::max(nums) + 1);
    for (auto a : nums) {
      ++counter[a];
    }

    for (int i = 0, j = 0; i < std::ssize(counter); ++i) {
      while (counter[i]--) {
        nums[j++] = i;
      }
    }

    int ans = 0;
    for (int i = 0; i < std::ssize(nums) / 2; ++i) {
      ans = std::max(ans, nums[i] + nums[nums.size() - i - 1]);
    }
    return ans;
  }
};

} // namespace counting_sort

namespace stl {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int minPairSum(std::vector<int> nums) {
    std::ranges::sort(nums);
    return std::transform_reduce(
        nums.cbegin(), nums.cbegin() + nums.size() / 2, nums.crbegin(), 0,
        [](int a, int b) { return std::max(a, b); }, std::plus{});
  }
};

} // namespace stl
