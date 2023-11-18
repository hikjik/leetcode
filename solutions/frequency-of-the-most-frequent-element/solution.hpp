#pragma once

#include <numeric>
#include <ranges>
#include <vector>

// Time: O(NlogN)
// Space: O(N)

namespace sliding_window {

// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
  static int maxFrequency(std::vector<int> nums, int k) {
    std::ranges::sort(nums);

    long long sum = 0;
    long long left = 0, right = 0;
    while (right < std::ssize(nums)) {
      sum += nums[right];
      if (nums[right] * (right - left + 1) - sum > k) {
        sum -= nums[left++];
      }
      ++right;
    }
    return right - left;
  }
};

} // namespace sliding_window

namespace counting_sort {

// Time: O(M), where M is the max element in nums
// Space: O(N)
class Solution {
public:
  static int maxFrequency(std::vector<int> nums, int k) {
    std::vector<int> counter(std::ranges::max(nums) + 1);
    for (auto a : nums) {
      ++counter[a];
    }
    for (int i = 0, j = 0; i < std::ssize(counter); ++i) {
      while (counter[i]--) {
        nums[j++] = i;
      }
    }

    long long sum = 0;
    long long left = 0, right = 0;
    while (right < std::ssize(nums)) {
      sum += nums[right];
      if (nums[right] * (right - left + 1) - sum > k) {
        sum -= nums[left++];
      }
      ++right;
    }
    return right - left;
  }
};

} // namespace counting_sort
