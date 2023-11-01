#pragma once

#include <iterator>
#include <sstream>
#include <string>
#include <unordered_set>

/*
  1935. Maximum Number of Words You Can Type
  https://leetcode.com/problems/maximum-number-of-words-you-can-type/
  Difficulty: Easy
  Tags: Hash Table, String
  Time:
  Space:
*/

class Solution {
public:
  static int canBeTypedWords(std::string text, std::string brokenLetters) {
    std::unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
    std::istringstream stream(text);
    return std::count_if(
        std::istream_iterator<std::string>(stream),
        std::istream_iterator<std::string>(), [&](const std::string &word) {
          return std::all_of(word.begin(), word.end(),
                             [&](char c) { return !broken.contains(c); });
        });
  }
};
