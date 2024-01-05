#pragma once

#include <array>
#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool isRobotBounded(std::string instructions) {
    static const std::array<std::array<int, 2>, 4> kDirs{
        {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    int x = 0, y = 0;
    int d = 0;
    for (auto c : instructions) {
      if (c == 'G') {
        x += kDirs[d][0], y += kDirs[d][1];
      } else {
        d += c == 'R' ? 1 : 3;
        d %= 4;
      }
    }
    return !x && !y || d;
  }
};
