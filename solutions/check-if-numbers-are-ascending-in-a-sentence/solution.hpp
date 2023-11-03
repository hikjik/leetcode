#pragma once

#include <sstream>
#include <string>

// Time:
// Space:

class Solution {
public:
  static bool areNumbersAscending(std::string s) {
    std::istringstream stream(s);
    int prev = 0;
    for (std::string token; stream >> token;) {
      if (std::isdigit(token[0])) {
        const auto number = std::stoi(token);
        if (prev >= number) {
          return false;
        }
        prev = number;
      }
    }
    return true;
  }
};
