#pragma once

#include <string>

class Solution {
public:
  static std::string generateTheString(int n) {
    return n & 1 ? std::string(n, 'a') : std::string(n - 1, 'a') + "b";
  }
};
