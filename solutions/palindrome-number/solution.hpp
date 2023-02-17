#pragma once

#include <string>

class Solution {
public:
  static bool isPalindrome(int x) {
    const auto str = std::to_string(x);
    for (size_t i = 0; i < str.size() / 2; ++i) {
      if (str[i] != str[str.size() - i - 1]) {
        return false;
      }
    }
    return true;
  }
};
