#pragma once

#include <string>
#include <vector>

/*
  1961. Check If String Is a Prefix of Array
  https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static bool isPrefixString(std::string s,
                             const std::vector<std::string> &words) {
    for (size_t i = 0, j = 0; i < s.size(); i += words[j++].size()) {
      if (j == words.size() || s.substr(i, words[j].size()) != words[j]) {
        return false;
      }
    }
    return true;
  }
};
