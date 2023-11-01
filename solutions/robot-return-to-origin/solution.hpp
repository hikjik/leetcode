#pragma once

#include <string>

/*
  657. Robot Return to Origin
  https://leetcode.com/problems/robot-return-to-origin/
  Difficulty: Easy
  Tags: String, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static bool judgeCircle(std::string moves) {
    int x = 0, y = 0;
    for (auto c : moves) {
      if (c == 'L') {
        --y;
      } else if (c == 'R') {
        ++y;
      } else if (c == 'U') {
        --x;
      } else {
        ++x;
      }
    }
    return x == 0 && y == 0;
  }
};
