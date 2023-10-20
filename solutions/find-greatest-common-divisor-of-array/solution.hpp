#pragma once

#include <numeric>
#include <vector>

class Solution {
public:
  static int findGCD(const std::vector<int> &nums) {
    const auto [it_min, it_max] = std::minmax_element(nums.begin(), nums.end());
    return std::gcd(*it_min, *it_max);
  }
};
