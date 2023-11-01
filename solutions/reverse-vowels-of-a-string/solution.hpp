#pragma once

#include <algorithm>
#include <string>
#include <unordered_set>

/*
  345. Reverse Vowels of a String
  https://leetcode.com/problems/reverse-vowels-of-a-string/
  Difficulty: Easy
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
private:
  static inline const std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                                                      'A', 'E', 'I', 'O', 'U'};

public:
  static std::string reverseVowels(std::string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      while (left < right && !vowels.count(s[left])) {
        left++;
      }
      while (left < right && !vowels.count(s[right])) {
        right--;
      }
      std::swap(s[left++], s[right--]);
    }
    return s;
  }
};