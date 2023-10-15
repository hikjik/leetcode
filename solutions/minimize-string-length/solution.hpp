#pragma once

#include <string>
#include <unordered_set>

class Solution {
public:
  static int minimizedStringLength(std::string s) {
    return std::unordered_set<char>(s.begin(), s.end()).size();
  }
};
