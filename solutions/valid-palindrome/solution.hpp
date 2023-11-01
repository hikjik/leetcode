#pragma once

#include <string>

/*
  125. Valid Palindrome
  https://leetcode.com/problems/valid-palindrome/
  Difficulty: Easy
  Tags: Two Pointers, String
  Time:
  Space:
*/

class Solution {
public:
  static bool isPalindrome(std::string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      while (left < right && !std::isalnum(s[left])) {
        left++;
      }
      while (left < right && !std::isalnum(s[right])) {
        right--;
      }
      if (std::tolower(s[left++]) != std::tolower(s[right--])) {
        return false;
      }
    }
    return true;
  }
};
