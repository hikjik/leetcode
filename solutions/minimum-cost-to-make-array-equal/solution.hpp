#pragma once

#include <algorithm>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static long long minCost(const std::vector<int> &nums,
                           const std::vector<int> &cost) {
    const auto [it_min, it_max] = std::minmax_element(nums.begin(), nums.end());
    auto left = *it_min, right = *it_max;

    while (left < right) {
      const auto middle = left + (right - left) / 2;

      if (totalCost(nums, cost, middle) <= totalCost(nums, cost, middle + 1)) {
        right = middle;
      } else {
        left = middle + 1;
      }
    }

    return totalCost(nums, cost, left);
  }

private:
  static long long totalCost(const std::vector<int> &nums,
                             const std::vector<int> &cost, int base) {
    long long total_cost = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      total_cost += std::abs(nums[i] - base) * 1LL * cost[i];
    }
    return total_cost;
  }
};
