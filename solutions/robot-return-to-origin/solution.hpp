#pragma once

#include <string>

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
