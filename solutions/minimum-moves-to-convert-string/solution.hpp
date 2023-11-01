#pragma once

#include <string>

/*
  2027. Minimum Moves to Convert String
  https://leetcode.com/problems/minimum-moves-to-convert-string/
  Difficulty: Easy
  Tags: String, Greedy
  Time:
  Space:
*/

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
