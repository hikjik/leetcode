#pragma once

#include <ranges>
#include <string>
#include <unordered_set>
#include <vector>

/*
  1684. Count the Number of Consistent Strings
  https://leetcode.com/problems/count-the-number-of-consistent-strings/
  Difficulty: Easy
  Tags: Array, Hash Table, String, Bit Manipulation
  Time:
  Space:
*/

class Solution {
public:
  static int countConsistentStrings(std::string allowed,
                                    const std::vector<std::string> &words) {
    std::unordered_set<char> set(allowed.begin(), allowed.end());
    return std::ranges::count_if(words, [&](const auto &word) {
      return std::ranges::all_of(word, [&](char c) { return set.contains(c); });
    });
  }
};
