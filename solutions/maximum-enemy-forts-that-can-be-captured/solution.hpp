#pragma once

#include <vector>

/*
  2511. Maximum Enemy Forts That Can Be Captured
  https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/
  Difficulty: Easy
  Tags: Array, Two Pointers
  Time:
  Space:
*/

class Solution {
public:
  static int captureForts(const std::vector<int> &forts) {
    int ans = 0;
    for (int i = 0, j = 0; j < std::ssize(forts); ++j) {
      if (forts[j]) {
        if (forts[i] == -forts[j]) {
          ans = std::max(ans, j - i - 1);
        }
        i = j;
      }
    }
    return ans;
  }
};
