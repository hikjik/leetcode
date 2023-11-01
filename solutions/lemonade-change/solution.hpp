#pragma once

#include <vector>

/*
  860. Lemonade Change
  https://leetcode.com/problems/lemonade-change/
  Difficulty: Easy
  Tags: Array, Greedy
  Time:
  Space:
*/

class Solution {
public:
  static bool lemonadeChange(const std::vector<int> &bills) {
    int cnt5 = 0, cnt10 = 0;
    for (auto bill : bills) {
      if (bill == 5) {
        cnt5++;
      } else if (bill == 10) {
        if (!cnt5) {
          return false;
        }
        cnt5--;
        cnt10++;
      } else if (bill == 20) {
        if (cnt10 && cnt5) {
          cnt10--;
          cnt5--;
        } else if (cnt5 > 2) {
          cnt5 -= 3;
        } else {
          return false;
        }
      } else {
        throw;
      }
    }
    return true;
  }
};