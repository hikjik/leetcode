#pragma once

#include <vector>

/*
  1304. Find N Unique Integers Sum up to Zero
  https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
  Difficulty: Easy
  Tags: Array, Math
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int> sumZero(int n) {
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = 2 * i - n + 1;
    }
    return ans;
  }
};
