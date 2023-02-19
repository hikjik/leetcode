#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
  static void reverseString(std::vector<char> &str) {
    std::reverse(str.begin(), str.end());
  }
};
