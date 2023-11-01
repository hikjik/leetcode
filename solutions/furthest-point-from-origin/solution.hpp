#pragma once

#include <cmath>
#include <string>

/*
  2833. Furthest Point From Origin
  https://leetcode.com/problems/furthest-point-from-origin/
  Difficulty: Easy
  Tags: Array, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int furthestDistanceFromOrigin(std::string moves) {
    int left = 0, right = 0, underscore = 0;
    for (auto c : moves) {
      if (c == 'R') {
        ++right;
      } else if (c == 'L') {
        ++left;
      } else {
        ++underscore;
      }
    }
    return underscore + std::abs(left - right);
  }
};
