#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  2185. Counting Words With a Given Prefix
  https://leetcode.com/problems/counting-words-with-a-given-prefix/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static int prefixCount(const std::vector<std::string> &words,
                         std::string pref) {
    return count_if(words.begin(), words.end(), [&pref](const auto &word) {
      return word.starts_with(pref);
    });
  }
};
