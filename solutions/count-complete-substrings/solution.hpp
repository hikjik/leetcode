#pragma once

#include <array>
#include <cmath>
#include <string>
#include <unordered_set>

// A is the alphabet size, N is the length of the string word
// Time: O(NA)
// Space: O(A)

class Solution {
public:
  static int countCompleteSubstrings(std::string word, int k) {
    int ans = 0;
    const int uniqueCharsCount =
        std::unordered_set<char>(word.begin(), word.end()).size();
    for (int i = 1; i <= uniqueCharsCount; ++i) {
      ans += countCompleteSubstrings(word, k, i * k);
    }
    return ans;
  }

private:
  static int countCompleteSubstrings(const std::string &s, int k,
                                     int windowSize) {
    int ans = 0;
    std::array<int, 26> counter{};
    int exactlyKCount = 0;
    for (int left = 0, right = 0; right < std::ssize(s); ++right) {
      if (right && std::abs(s[right] - s[right - 1]) > 2) {
        counter.fill(0);
        left = right;
        exactlyKCount = 0;
      }

      const auto count = ++counter[s[right] - 'a'];
      exactlyKCount += (count == k) - (count == k + 1);

      if (right - left >= windowSize) {
        const auto count = --counter[s[left++] - 'a'];
        exactlyKCount += (count == k) - (count == k - 1);
      }

      if (right - left + 1 >= windowSize) {
        ans += exactlyKCount * k == windowSize;
      }
    }
    return ans;
  }
};
