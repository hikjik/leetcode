#pragma once

#include <algorithm>
#include <string>

/*
  2729. Check if The Number is Fascinating
  https://leetcode.com/problems/check-if-the-number-is-fascinating/
  Difficulty: Easy
  Tags: Hash Table, Math
  Time:
  Space:
*/

class Solution {
public:
  static bool isFascinating(int n) {
    auto s = std::to_string(n) + std::to_string(2 * n) + std::to_string(3 * n);
    std::sort(s.begin(), s.end());
    return s == "123456789";
  }
};
