#pragma once

#include <ranges>
#include <string>
#include <vector>

/*
  2108. Find First Palindromic String in the Array
  https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
  Difficulty: Easy
  Tags: Array, Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static std::string firstPalindrome(const std::vector<std::string> &words) {
    auto it = std::ranges::find_if(
        words, [](const auto &word) { return isPalindrome(word); });
    return it == words.end() ? "" : *it;
  }

private:
  static bool isPalindrome(const std::string &word) {
    for (size_t i = 0; i <= word.size() / 2; ++i) {
      if (word[i] != word[word.size() - i - 1]) {
        return false;
      }
    }
    return true;
  }
};
