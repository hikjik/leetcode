#pragma once

#include <climits>
#include <string>
#include <vector>

/*
  2287. Rearrange Characters to Make Target String
  https://leetcode.com/problems/rearrange-characters-to-make-target-string/
  Difficulty: Easy
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int rearrangeCharacters(std::string s, std::string t) {
    const auto count_s = countChars(s), count_t = countChars(t);

    int cnt = INT_MAX;
    for (auto c : t) {
      cnt = std::min(cnt, count_s[c] / count_t[c]);
    }
    return cnt;
  }

private:
  static std::vector<int> countChars(std::string s) {
    std::vector<int> frequencies(128);
    for (auto c : s) {
      ++frequencies[c];
    }
    return frequencies;
  }
};
