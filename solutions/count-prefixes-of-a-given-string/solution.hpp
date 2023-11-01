#pragma once

#include <string>
#include <vector>

/*
  2255. Count Prefixes of a Given String
  https://leetcode.com/problems/count-prefixes-of-a-given-string/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static int countPrefixes(const std::vector<std::string> &words,
                           std::string s) {
    int count = 0;
    for (const auto &word : words) {
      count += s.find(word) == 0;
    }
    return count;
  }
};
