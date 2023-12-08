#pragma once

#include <ranges>
#include <string>
#include <vector>

// Time: O(N)
// Space: O(1)

namespace kmp {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static std::string longestPrefix(std::string s) {
    return s.substr(0, LPS(s).back());
  }

private:
  static std::vector<int> LPS(const std::string &s) {
    std::vector<int> lps(s.size());
    for (int i = 1, j = 0; i < std::ssize(s);) {
      if (s[i] == s[j]) {
        lps[i++] = ++j;
      } else {
        if (j) {
          j = lps[j - 1];
        } else {
          ++i;
        }
      }
    }
    return lps;
  }
};

} // namespace kmp

namespace hash {

// Time: O(N)
// Space: O(1)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;
  static constexpr int kPrime = 31;

  static std::string longestPrefix(std::string s) {
    const int n = s.size();

    int len = 0;
    long long pow = 1;
    long long prefixHash = 0, suffixHash = 0;
    for (int i = 0; i < n - 1; ++i) {
      prefixHash = (prefixHash * kPrime + s[i] - 'a') % kMod;
      suffixHash = ((s[n - i - 1] - 'a') * pow + suffixHash) % kMod;
      pow = pow * kPrime % kMod;
      if (prefixHash == suffixHash) {
        len = i + 1;
      }
    }

    return s.substr(0, len);
  }
};

} // namespace hash
