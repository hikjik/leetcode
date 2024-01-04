#pragma once

#include <string>
#include <string_view>
#include <vector>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static std::string removeVowels(std::string s) {
    std::erase_if(s, [](char c) {
      static constexpr std::string_view kVowels = "aeiou";
      return kVowels.find(c) != std::string::npos;
    });
    return s;
  }
};
