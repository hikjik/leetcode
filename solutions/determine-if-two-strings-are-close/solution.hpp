#pragma once

#include <algorithm>
#include <array>
#include <string>

/*
  1657. Determine if Two Strings Are Close
  https://leetcode.com/problems/determine-if-two-strings-are-close/
  Difficulty: Medium
  Tags: Hash Table, String, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static bool closeStrings(std::string word1, std::string word2) {
    if (word1.size() != word2.size()) {
      return false;
    }

    std::array<int, 26> freq1{}, freq2{};
    for (auto c : word1) {
      ++freq1[c - 'a'];
    }
    for (auto c : word2) {
      if (!freq1[c - 'a']) {
        return false;
      }
      ++freq2[c - 'a'];
    }

    std::sort(freq1.begin(), freq1.end());
    std::sort(freq2.begin(), freq2.end());
    return freq1 == freq2;
  }
};
