#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static bool winnerOfGame(std::string colors) {
    int cnt = 0;
    for (size_t i = 0; i + 2 < colors.size(); ++i) {
      if (colors[i] == colors[i + 1] && colors[i] == colors[i + 2]) {
        colors[i] == 'A' ? ++cnt : --cnt;
      }
    }
    return cnt > 0;
  }
};
