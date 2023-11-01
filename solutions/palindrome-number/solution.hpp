#pragma once

#include <algorithm>
#include <string>

/*
  9. Palindrome Number
  https://leetcode.com/problems/palindrome-number/
  Difficulty: Easy
  Tags: Math
  Time:
  Space:
*/

class Solution {
public:
  static bool isPalindrome(int n) {
    const auto str = std::to_string(n);
    return std::equal(str.cbegin(), str.cbegin() + str.size() / 2,
                      str.crbegin());
  }
};
