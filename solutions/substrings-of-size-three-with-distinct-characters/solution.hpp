#pragma once

#include <string>

/*
  1876. Substrings of Size Three with Distinct Characters
  https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
  Difficulty: Easy
  Tags: Hash Table, String, Sliding Window, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int countGoodSubstrings(std::string s) {
    int cnt = 0;
    for (int i = 0; i + 2 < std::ssize(s); ++i) {
      if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
        ++cnt;
      }
    }
    return cnt;
  }
};
