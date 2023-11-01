#pragma once

#include <vector>

/*
  2455. Average Value of Even Numbers That Are Divisible by Three
  https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/
  Difficulty: Easy
  Tags: Array, Math
  Time:
  Space:
*/

class Solution {
public:
  static int averageValue(const std::vector<int> &nums) {
    int sum = 0, cnt = 0;
    for (auto a : nums) {
      if (a % 6 == 0) {
        ++cnt, sum += a;
      }
    }
    return cnt ? sum / cnt : 0;
  }
};
