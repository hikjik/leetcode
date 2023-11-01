#pragma once

#include <algorithm>
#include <string>

/*
  151. Reverse Words in a String
  https://leetcode.com/problems/reverse-words-in-a-string/
  Difficulty: Medium
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static std::string reverseWords(std::string s) {
    RemoveDuplicateSpaces(&s);
    TrimRight(&s);
    std::reverse(s.begin(), s.end());
    TrimRight(&s);
    ReverseWords(&s);
    return s;
  }

private:
  static void RemoveDuplicateSpaces(std::string *s_ptr) {
    s_ptr->erase(std::unique(s_ptr->begin(), s_ptr->end(),
                             [](char lhs, char rhs) {
                               return lhs == rhs && lhs == ' ';
                             }),
                 s_ptr->end());
  }

  static void TrimRight(std::string *s_ptr) {
    while (s_ptr->back() == ' ') {
      s_ptr->pop_back();
    }
  }

  static void ReverseWords(std::string *s_ptr) {
    auto &s = *s_ptr;
    for (size_t i = 0, j = 0; j <= s.size(); ++j) {
      if (j == s.size() || s[j] == ' ') {
        std::reverse(s.begin() + i, s.begin() + j);
        i = j + 1;
      }
    }
  }
};
