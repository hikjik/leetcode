#pragma once

#include <cmath>

/*
  2843.   Count Symmetric Integers
  https://leetcode.com/problems/count-symmetric-integers/
  Difficulty: Easy
  Tags: Math, Enumeration
  Time:
  Space:
*/

class Solution {
public:
  static int countSymmetricIntegers(int low, int high) {
    int cnt = 0;
    for (int i = low; i <= high; ++i) {
      if (isSymmetric(i)) {
        ++cnt;
      }
    }
    return cnt;
  }

private:
  static bool isSymmetric(int n) {
    const int num_digits = std::log10(n) + 1;
    if (num_digits % 2 == 1) {
      return false;
    }

    int sum = 0;
    for (int i = 0; i < num_digits; ++i) {
      const auto d = n % 10;
      n /= 10;
      sum += i < num_digits / 2 ? d : -d;
    }
    return sum == 0;
  }
};
