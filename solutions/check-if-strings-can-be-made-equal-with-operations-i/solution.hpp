#pragma once

#include <string>

/*
  2839. Check if Strings Can be Made Equal With Operations I
  https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static bool canBeEqual(std::string s1, std::string s2) {
    for (int i : {0, 1}) {
      if (s1[i] != s2[i]) {
        std::swap(s1[i], s1[i + 2]);
      }
    }
    return s1 == s2;
  }
};
