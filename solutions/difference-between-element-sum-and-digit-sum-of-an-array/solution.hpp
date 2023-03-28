#pragma once

#include <vector>

class Solution {
public:
  static int differenceOfSum(const std::vector<int> &nums) {
    int sum = 0, digits_sum = 0;
    for (auto num : nums) {
      sum += num;
      while (num) {
        digits_sum += num % 10;
        num /= 10;
      }
    }
    return abs(sum - digits_sum);
  }
};