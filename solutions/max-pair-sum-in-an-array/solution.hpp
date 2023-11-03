#pragma once

#include <vector>

// Time:
// Space:

class Solution {
public:
  static int maxSum(const std::vector<int> &nums) {
    int max_sum = -1;
    std::vector<int> max_number(10);
    for (auto a : nums) {
      const auto d = maxDigit(a);
      if (max_number[d]) {
        max_sum = std::max(max_sum, max_number[d] + a);
      }
      max_number[d] = std::max(max_number[d], a);
    }
    return max_sum;
  }

private:
  static int maxDigit(int n) {
    int d = 0;
    while (n) {
      d = std::max(d, n % 10);
      n /= 10;
    }
    return d;
  }
};
