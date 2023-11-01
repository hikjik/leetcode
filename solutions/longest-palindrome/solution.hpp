#pragma once

#include <string>
#include <unordered_map>

/*
  409. Longest Palindrome
  https://leetcode.com/problems/longest-palindrome/
  Difficulty: Easy
  Tags: Hash Table, String, Greedy
  Time:
  Space:
*/

class Solution {
  static const size_t ALPHABET_LENGTH_EN = 26;

public:
  static int longestPalindrome(std::string str) {
    std::unordered_map<char, int> frequencies;
    for (auto c : str) {
      ++frequencies[c];
    }

    int odds_count = 0;
    for (const auto &[c, f] : frequencies) {
      odds_count += f & 1;
    }
    return str.size() - odds_count + (odds_count > 0);
  }
};
