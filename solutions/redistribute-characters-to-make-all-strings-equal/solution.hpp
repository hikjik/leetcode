#pragma once

#include <string>
#include <vector>

/*
  1897. Redistribute Characters to Make All Strings Equal
  https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
  Difficulty: Easy
  Tags: Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static bool makeEqual(const std::vector<std::string> &words) {
    std::vector<int> counter(26);
    for (const auto &word : words) {
      for (auto c : word) {
        ++counter[c - 'a'];
      }
    }
    return std::all_of(counter.begin(), counter.end(), [&](auto frequency) {
      return frequency % words.size() == 0;
    });
  }
};
