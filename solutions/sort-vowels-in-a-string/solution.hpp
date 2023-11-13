#pragma once

#include <ranges>
#include <string>
#include <unordered_map>

// Time:
// Space:

class Solution {
public:
  inline static const string kVowels = "AEIOUaeiou";

  bool isVowel(char c) { return kVowels.find(c) != string::npos; }

  string sortVowels(string s) {
    unordered_map<char, int> counter;
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
