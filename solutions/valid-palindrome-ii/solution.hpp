#pragma once

#include <iostream>
#include <string>

class Solution {
public:
  static bool validPalindrome(std::string s) {
    for (auto first = s.cbegin(), last = s.cend();
         first != last && first != --last;) {
      if (*first++ != *last) {
        return validPalindrome(std::prev(first), last) ||
               validPalindrome(first, std::next(last));
      }
    }
    return true;
  }

private:
  template <typename Iterator>
  static bool validPalindrome(Iterator first, Iterator last) {
    while (first != last && first != --last) {
      if (*first++ != *last) {
        return false;
      }
    }
    return true;
  }
};
