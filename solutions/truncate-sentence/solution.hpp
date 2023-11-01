#pragma once

#include <sstream>
#include <string>

/*
  1816. Truncate Sentence
  https://leetcode.com/problems/truncate-sentence/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static std::string truncateSentence(std::string s, int k) {
    std::string ans;
    std::istringstream stream(s);
    for (std::string word; stream >> word && k--;) {
      ans += word + (k ? " " : "");
    }
    return ans;
  }
};
