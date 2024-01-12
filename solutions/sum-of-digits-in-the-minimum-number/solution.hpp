#pragma once

#include <ranges>
#include <vector>

// Time: O(logN)
// Space: O(1)

class Solution {
public:
  static int sumOfDigits(const std::vector<int> &nums) {
    int sum = 0;
    for (int n = std::ranges::min(nums); n; n /= 10) {
      sum += n % 10;
    }
    return sum % 2 == 0;
  }
};
