#pragma once

#include <algorithm>
#include <string>

/*
  1332. Remove Palindromic Subsequences
  https://leetcode.com/problems/remove-palindromic-subsequences/
  Difficulty: Easy
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static int removePalindromeSub(std::string s) {
    return 2 - std::equal(s.cbegin(), s.cbegin() + s.size() / 2, s.crbegin());
  }
};
