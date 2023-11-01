#pragma once

#include <vector>

/*
  338. Counting Bits
  https://leetcode.com/problems/counting-bits/
  Difficulty: Easy
  Tags: Dynamic Programming, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> countBits(int n) {
    std::vector<int> ans(n + 1);
    for (int i = 1; i < n + 1; ++i) {
      ans[i] = ans[i / 2] + i % 2;
    }
    return ans;
  }
};
