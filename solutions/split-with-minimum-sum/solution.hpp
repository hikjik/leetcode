#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static int splitNum(int num) {
    std::vector<int> digits;
    while (num) {
      digits.push_back(num % 10);
      num /= 10;
    }
    std::sort(digits.begin(), digits.end());

    std::vector<int> nums(2);
    for (int i = 0; i < std::ssize(digits); ++i) {
      nums[i & 1] = nums[i & 1] * 10 + digits[i];
    }
    return nums[0] + nums[1];
  }
};
