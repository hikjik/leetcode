#pragma once

#include <string>

// Time: O(N^2)
// Space: O(1)

class Solution {
private:
  static inline const std::string kVowels = "aeiou";

public:
  static int beautifulSubstrings(std::string s, int k) {
    const int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int consonants = 0, vowels = 0;
      for (int j = i; j < n; ++j) {
        if (kVowels.find(s[j]) != std::string::npos) {
          vowels += 1;
        } else {
          consonants += 1;
        }
        if (consonants == vowels && (consonants * vowels) % k == 0) {
          ans += 1;
        }
      }
    }
    return ans;
  }
};
