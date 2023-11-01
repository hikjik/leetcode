#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  2114. Maximum Number of Words Found in Sentences
  https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static int mostWordsFound(const std::vector<std::string> &sentences) {
    int ans = 0;
    for (const auto &s : sentences) {
      const int words_count = std::count(s.begin(), s.end(), ' ') + 1;
      ans = std::max(ans, words_count);
    }
    return ans;
  }
};
