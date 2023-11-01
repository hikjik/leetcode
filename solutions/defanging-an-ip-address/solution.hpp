#pragma once

#include <regex>
#include <string>

/*
  1108. Defanging an IP Address
  https://leetcode.com/problems/defanging-an-ip-address/
  Difficulty: Easy
  Tags: String
  Time:
  Space:
*/

class Solution {
public:
  static std::string defangIPaddr(std::string address) {
    static const std::regex regex("\\.");
    return std::regex_replace(address, regex, "[.]");
  }
};
