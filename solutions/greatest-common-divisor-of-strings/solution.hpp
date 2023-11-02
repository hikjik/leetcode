#pragma once

#include <numeric>
#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string gcdOfStrings(std::string str1, std::string str2) {
    if (str1 + str2 != str2 + str1) {
      return "";
    }
    return str1.substr(0, std::gcd(str1.size(), str2.size()));
  }
};
