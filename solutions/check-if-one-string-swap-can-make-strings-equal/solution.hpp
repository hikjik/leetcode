#pragma once

#include <string>

/*
  1790. Check if One String Swap Can Make Strings Equal
  https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
  Difficulty: Easy
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static bool areAlmostEqual(std::string s1, std::string s2) {
    auto i1 = s1.begin();
    auto i2 = s2.begin();
    while (i1 != s1.end() && *i1 == *i2) {
      ++i1, ++i2;
    }

    if (i1 == s1.end()) {
      return true;
    }

    auto j1 = std::next(i1);
    auto j2 = std::next(i2);
    while (j1 != s1.end() && *j1 == *j2) {
      ++j1, ++j2;
    }

    if (j1 == s1.end() || *i1 != *j2 || *i2 != *j1) {
      return false;
    }

    return std::equal(std::next(j1), s1.end(), std::next(j2));
  }
};
