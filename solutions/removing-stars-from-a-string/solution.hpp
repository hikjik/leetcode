#pragma once

#include <string>

/*
  2390. Removing Stars From a String
  https://leetcode.com/problems/removing-stars-from-a-string/
  Difficulty: Medium
  Tags: String, Stack, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static std::string removeStars(std::string s) {
    int n = 0;
    for (auto c : s) {
      if (c == '*') {
        n--;
      } else {
        s[n++] = c;
      }
    }
    return s.substr(0, n);
  }
};
