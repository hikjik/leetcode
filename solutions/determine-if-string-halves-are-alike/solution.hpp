#pragma once

#include <algorithm>
#include <string>

// Time: O(N)
// Space: O(1)

class Solution {
public:
  static bool halvesAreAlike(std::string s) {
    const auto isVowel = [](char c) {
      static const std::string vowels = "aeiouAEIOU";
      return vowels.find(c) != std::string::npos;
    };
    return std::count_if(s.cbegin(), s.cbegin() + s.size() / 2, isVowel) ==
           std::count_if(s.crbegin(), s.crbegin() + s.size() / 2, isVowel);
  }
};
