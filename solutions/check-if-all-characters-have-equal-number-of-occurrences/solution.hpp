#pragma once

#include <string>
#include <unordered_map>

/*
  1941. Check if All Characters Have Equal Number of Occurrences
  https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
  Difficulty: Easy
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static bool areOccurrencesEqual(std::string s) {
    std::unordered_map<char, int> counter;
    for (auto c : s) {
      ++counter[c];
    }
    return std::all_of(counter.begin(), counter.end(), [&](const auto &item) {
      return item.second == counter.begin()->second;
    });
  }
};
