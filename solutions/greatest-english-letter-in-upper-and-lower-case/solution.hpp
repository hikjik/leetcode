#pragma once

#include <string>
#include <vector>

/*
  2309. Greatest English Letter in Upper and Lower Case
  https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/
  Difficulty: Easy
  Tags: Hash Table, String, Enumeration
  Time:
  Space:
*/

class Solution {
public:
  static std::string greatestLetter(std::string s) {
    std::vector<int> count(128);
    for (auto c : s) {
      ++count[c];
    }

    for (char c = 'Z'; c >= 'A'; --c) {
      if (count[c] && count[c - 'A' + 'a']) {
        return std::string{c};
      }
    }
    return "";
  }
};
