#pragma once

#include <string>

/*
  1374. Generate a String With Characters That Have Odd Counts
  https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string generateTheString(int n) {
    return n & 1 ? std::string(n, 'a') : std::string(n - 1, 'a') + "b";
  }
};
