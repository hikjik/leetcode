#pragma once

#include <string>

/*
  2697. Lexicographically Smallest Palindrome
  https://leetcode.com/problems/lexicographically-smallest-palindrome/
  Difficulty: Easy
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static std::string makeSmallestPalindrome(std::string s) {
    const int n = s.size();
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] != s[n - i - 1]) {
        s[i] = s[n - i - 1] = std::min(s[i], s[n - i - 1]);
      }
    }
    return s;
  }
};
