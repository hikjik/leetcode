#pragma once

#include <ios>
#include <sstream>
#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string toHex(int num) {
    std::stringstream sstream;
    sstream << std::hex << num;
    return sstream.str();
  }
};
