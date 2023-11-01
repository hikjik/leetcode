#pragma once

#include <vector>

/*
  1566. Detect Pattern of Length M Repeated K or More Times
  https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
  Difficulty: Easy
  Tags: Array, Enumeration
  Time:
  Space:
*/

class Solution {
public:
  static bool containsPattern(const std::vector<int> &arr, int m, int k) {
    for (int i = 0, cnt = 0; i + m < std::ssize(arr); ++i) {
      if (arr[i] != arr[i + m]) {
        cnt = 0;
      } else if (++cnt == (k - 1) * m) {
        return true;
      }
    }
    return false;
  }
};
