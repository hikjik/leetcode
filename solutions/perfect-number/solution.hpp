#pragma once

#include <vector>

/*
  507. Perfect Number
  https://leetcode.com/problems/perfect-number/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static bool checkPerfectNumber(int num) {
    const std::vector<int> primes{2, 3, 5, 7, 13};
    for (auto p : primes) {
      if (((1 << p) - 1) * ((1 << (p - 1))) == num) {
        return true;
      }
    }
    return false;
  }
};
