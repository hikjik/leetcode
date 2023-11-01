#pragma once

#include <cmath>
#include <string>
#include <vector>

/*
  2068. Check Whether Two Strings are Almost Equivalent
  https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/
  Difficulty: Easy
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static bool checkAlmostEquivalent(std::string word1, std::string word2) {
    std::vector<int> counter(128);
    for (int i = 0; i < std::ssize(word1); ++i) {
      ++counter[word1[i]], --counter[word2[i]];
    }
    return std::all_of(counter.begin(), counter.end(),
                       [](int a) { return std::abs(a) <= 3; });
  }
};
