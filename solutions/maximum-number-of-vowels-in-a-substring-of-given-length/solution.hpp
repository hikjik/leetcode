#pragma once

#include <string>

// Time:
// Space:

class Solution {
public:
  static int maxVowels(std::string s, int k) {
    const int n = s.size();
    int max_vowel_count = 0, vowel_count = 0;
    for (int i = 0; i < n; ++i) {
      vowel_count += isVowel(s[i]);
      if (i >= k - 1) {
        max_vowel_count = std::max(max_vowel_count, vowel_count);
        vowel_count -= isVowel(s[i - k + 1]);
      }
    }
    return max_vowel_count;
  }

private:
  static bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
};
