#pragma once

#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool isPalindrome(std::string s) {
    int left = 0, right = s.size() - 1;
    while (left <= right) {
      if (!std::isalnum(s[left])) {
        ++left;
      } else if (!std::isalnum(s[right])) {
        --right;
      } else if (std::tolower(s[left]) == std::tolower(s[right])) {
        ++left, --right;
      } else {
        return false;
      }
    }
    return true;
  }
};
