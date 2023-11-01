#pragma once

#include <vector>

/*
  1550. Three Consecutive Odds
  https://leetcode.com/problems/three-consecutive-odds/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static bool threeConsecutiveOdds(const std::vector<int> &arr) {
    for (int odds = 0; auto a : arr) {
      odds = a & 1 ? odds + 1 : 0;
      if (odds == 3) {
        return true;
      }
    }
    return false;
  }
};
