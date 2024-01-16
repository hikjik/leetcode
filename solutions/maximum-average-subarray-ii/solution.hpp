#pragma once

#include <ranges>
#include <vector>

// E = 1e-5;
// M = max(nums) - min(nums)
// Time: O(Nlog(M/E)])
// Space: O(1)

class Solution {
public:
  static constexpr double kError = 1e-5;

  static double findMaxAverage(const std::vector<int> &nums, int k) {
    const auto [min, max] = std::ranges::minmax(nums);
    double left = min, right = max;
    while (right - left > kError) {
      const auto middle = (left + right) * 0.5;
      check(nums, middle, k) ? left = middle : right = middle;
    }
    return left;
  }

private:
  static bool check(const std::vector<int> &nums, double mean, int k) {
    double currSum = 0, prevSum = 0, minPrevSum = 0;
    for (int i = 0; i < std::ssize(nums); ++i) {
      currSum += nums[i] - mean;
      if (i >= k) {
        prevSum += nums[i - k] - mean;
        minPrevSum = std::min(minPrevSum, prevSum);
      }
      if (i >= k - 1 && currSum - minPrevSum >= 0) {
        return true;
      }
    }
    return false;
  }
};
