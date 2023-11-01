#pragma once

#include <vector>

/*
  717. 1-bit and 2-bit Characters
  https://leetcode.com/problems/1-bit-and-2-bit-characters/
  Difficulty: Easy
  Tags: Array
  Time:
  Space:
*/

class Solution {
public:
  static bool isOneBitCharacter(const std::vector<int> &bits) {
    bool last_1bit = false;
    for (int i = 0; i < std::ssize(bits); ++i) {
      last_1bit = !bits[i];
      i += bits[i];
    }
    return last_1bit;
  }
};
