#pragma once

#include <string>

/*
  2038. Remove Colored Pieces if Both Neighbors are the Same Color
  https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
  Difficulty: Medium
  Tags: Math, String, Greedy, Game Theory
  Time:
  Space:
*/

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
