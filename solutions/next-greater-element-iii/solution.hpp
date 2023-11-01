#pragma once

#include <algorithm>
#include <climits>
#include <string>

/*
  556. Next Greater Element III
  https://leetcode.com/problems/next-greater-element-iii/
  Difficulty: Medium
  Tags: Math, Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static int nextGreaterElement(int n) {
    auto s = std::to_string(n);
    if (std::next_permutation(s.begin(), s.end())) {
      const auto greater = std::stol(s);
      if (greater <= INT_MAX * 1L) {
        return greater;
      }
    }
    return -1;
  }
};
