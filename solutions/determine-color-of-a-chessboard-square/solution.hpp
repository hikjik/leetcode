#pragma once

#include <string>

/*
  1812. Determine Color of a Chessboard Square
  https://leetcode.com/problems/determine-color-of-a-chessboard-square/
  Difficulty: Easy
  Tags: Math, String
  Time:
  Space:
*/

class Solution {
public:
  static bool squareIsWhite(std::string coordinates) {
    return (coordinates[0] & 1) ^ (coordinates[1] & 1);
  }
};
