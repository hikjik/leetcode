#pragma once

#include <sstream>
#include <string>

// Time: O(n)
// Space: O(1)

class Solution {
public:
  static int myAtoi(std::string s) {
    std::stringstream stream(s);
    int number;
    stream >> number;
    return number;
  }
};
