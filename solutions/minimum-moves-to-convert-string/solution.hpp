#pragma once

#include <string>

class Solution {
public:
  static int minimumMoves(std::string s) {
    int moves = 0;
    for (int i = 0; i < std::ssize(s); ++i) {
      if (s[i] == 'X') {
        ++moves;
        i += 2;
      }
    }
    return moves;
  }
};
