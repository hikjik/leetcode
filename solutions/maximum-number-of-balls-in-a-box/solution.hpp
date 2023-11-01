#pragma once

#include <algorithm>
#include <array>

/*
  1742. Maximum Number of Balls in a Box
  https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
  Difficulty: Easy
  Tags: Hash Table, Math, Counting
  Time:
  Space:
*/

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
