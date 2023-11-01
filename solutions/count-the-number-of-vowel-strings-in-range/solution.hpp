#pragma once

#include <string>
#include <vector>

/*
  2586. Count the Number of Vowel Strings in Range
  https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static int vowelStrings(const std::vector<std::string> &words, int left,
                          int right) {
    return std::count_if(words.cbegin() + left, words.cbegin() + right + 1,
                         isVowelString);
  }

private:
  static bool isVowelString(const std::string &word) {
    return isVowelChar(word.front()) && isVowelChar(word.back());
  }

  static bool isVowelChar(char c) {
    return c == 'e' || c == 'o' || c == 'a' || c == 'i' || c == 'u';
  }
};
