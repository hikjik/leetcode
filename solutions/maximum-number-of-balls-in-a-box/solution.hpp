#pragma once

#include <algorithm>
#include <array>

class Solution {
public:
  static int countBalls(int lowLimit, int highLimit) {
    std::array<int, 46> counter{};
    for (int i = lowLimit; i <= highLimit; ++i) {
      ++counter[digitsSum(i)];
    }
    return *std::max_element(counter.begin(), counter.end());
  }

  static int digitsSum(int n) {
    int sum = 0;
    for (int i = n; i; i /= 10) {
      sum += i % 10;
    }
    return sum;
  }
};
