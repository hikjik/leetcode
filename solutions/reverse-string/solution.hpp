#pragma once

#include <algorithm>
#include <vector>

/*
  344. Reverse String
  https://leetcode.com/problems/reverse-string/
  Difficulty: Easy
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static void reverseString(std::vector<char> &str) {
    std::reverse(str.begin(), str.end());
  }
};
