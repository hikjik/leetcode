#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int maximum69Number(int num) {
    auto str = std::to_string(num);
    if (auto pos = str.find_first_of('6'); pos != std::string::npos) {
      str[pos] = '9';
    }
    return std::stoi(str);
  }
};
