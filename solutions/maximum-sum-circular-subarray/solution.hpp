#pragma once

#include <vector>

class Solution {
public:
  static int maxSubarraySumCircular(const std::vector<int> &nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int max_sum = maxSubArray(nums);
    int min_sum = minSubArray(nums);

    if (min_sum == sum) {
      return max_sum;
    }
    return std::max(max_sum, sum - min_sum);
  }

private:
  static int maxSubArray(const std::vector<int> &nums) {
    int max_sum = std::numeric_limits<int>::min();
    int max_so_far = 0;
    for (auto num : nums) {
      max_so_far = std::max(max_so_far + num, num);
      max_sum = std::max(max_sum, max_so_far);
    }
    return max_sum;
  }

  static int minSubArray(const std::vector<int> &nums) {
    int min_sum = std::numeric_limits<int>::max();
    int min_so_far = 0;
    for (auto num : nums) {
      min_so_far = std::min(min_so_far + num, num);
      min_sum = std::min(min_sum, min_so_far);
    }
    return min_sum;
  }
};
