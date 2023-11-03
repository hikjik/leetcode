#pragma once

#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
public:
  static const int ALPHABET_SIZE = 26;

  static int longestPalindrome(const std::vector<std::string> &words) {
    std::vector<std::vector<int>> cnt(ALPHABET_SIZE,
                                      std::vector<int>(ALPHABET_SIZE));
    int total = 0;
    for (const auto &word : words) {
      const auto i = word[0] - 'a', j = word[1] - 'a';
      if (cnt[j][i]) {
        cnt[j][i]--;
        total += 4;
      } else {
        cnt[i][j]++;
      }
    }
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
      if (cnt[i][i]) {
        return total + 2;
      }
    }
    return total;
  }
};
