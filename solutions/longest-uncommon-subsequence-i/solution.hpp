#pragma once

#include <string>

/*
  521. Longest Uncommon Subsequence I
  https://leetcode.com/problems/longest-uncommon-subsequence-i/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static int findLUSlength(std::string a, std::string b) {
    return a == b ? -1 : std::max(a.size(), b.size());
  }
};
