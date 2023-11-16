#pragma once

#include <ranges>
#include <string>
#include <unordered_map>

// Time:
// Space:

class Solution {
public:
  inline static const std::string kVowels = "AEIOUaeiou";

  static bool isVowel(char c) { return kVowels.find(c) != std::string::npos; }

  static std::string sortVowels(std::string s) {
    std::unordered_map<char, int> counter;
    for (auto c : s) {
      if (isVowel(c)) {
        ++counter[c];
      }
    }

    for (auto vowel = kVowels.begin(); auto &c : s) {
      if (isVowel(c)) {
        while (!counter[*vowel]--) {
          ++vowel;
        };
        c = *vowel;
      }
    }
    return s;
  }
};
