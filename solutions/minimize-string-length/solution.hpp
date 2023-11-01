#pragma once

#include <string>
#include <unordered_set>

/*
  2716. Minimize String Length
  https://leetcode.com/problems/minimize-string-length/
  Difficulty: Easy
  Tags: Hash Table, String
  Time:
  Space:
*/

class Solution {
public:
  static int minimizedStringLength(std::string s) {
    return std::unordered_set<char>(s.begin(), s.end()).size();
  }
};
