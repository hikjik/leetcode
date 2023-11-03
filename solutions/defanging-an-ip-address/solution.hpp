#pragma once

#include <regex>
#include <string>

// Time:
// Space:

class Solution {
public:
  static std::string defangIPaddr(std::string address) {
    static const std::regex regex("\\.");
    return std::regex_replace(address, regex, "[.]");
  }
};
