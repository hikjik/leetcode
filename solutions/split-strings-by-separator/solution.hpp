#pragma once

#include <sstream>
#include <string>
#include <vector>

/*
  2788. Split Strings by Separator
  https://leetcode.com/problems/split-strings-by-separator/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::string>
  splitWordsBySeparator(const std::vector<std::string> &words, char separator) {
    std::vector<std::string> ans;
    for (const auto &word : words) {
      std::stringstream stream(word);
      for (std::string s; std::getline(stream, s, separator);) {
        if (!s.empty()) {
          ans.push_back(s);
        }
      }
    }
    return ans;
  }
};
