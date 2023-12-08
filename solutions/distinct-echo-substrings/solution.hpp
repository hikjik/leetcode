#pragma once

#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

// Time: O(N^2)
// Space: O(N^2)

namespace lcs {

// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
  static int distinctEchoSubstrings(std::string s) {
    const int n = s.size();
    const std::string_view sv(s);

    std::vector<int> lcs(n + 1);
    std::unordered_set<std::string_view> seen;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        lcs[j] = s[i] == s[j] ? 1 + lcs[j + 1] : 0;
        if (lcs[j] >= j - i) {
          seen.insert(sv.substr(i, j - i));
        }
      }
    }

    return seen.size();
  }
};

} // namespace lcs

namespace sliding_window {

// Time: O(N^3)
// Space: O(N^2)
class Solution {
public:
  static int distinctEchoSubstrings(std::string s) {
    const int n = s.size();
    const std::string_view sv(s);

    std::unordered_set<std::string_view> seen;
    for (int len = 1; len <= n / 2; ++len) {
      int cnt = 0;
      for (int l = 0, r = len; r < n; ++l, ++r) {
        cnt = sv[l] == sv[r] ? cnt + 1 : 0;
        if (cnt == len) {
          seen.insert(sv.substr(l, len));
          --cnt;
        }
      }
    }
    return seen.size();
  }
};

} // namespace sliding_window

namespace hash {

// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
  static constexpr int kMod = 1e9 + 7;
  static constexpr int kPrime = 33;

  static int mul(long long a, long long b) { return a * b % kMod; }
  static int sum(long long a, long long b) { return (a + b + kMod) % kMod; }

  static int distinctEchoSubstrings(std::string s) {
    const int n = s.size();

    std::vector<int> pows(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
      pows[i] = mul(pows[i - 1], kPrime);
    }

    std::vector<int> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = sum(prefix[i], mul(s[i], pows[i]));
    }

    std::unordered_set<int> seen;
    for (int len = 1; len <= n / 2; ++len) {
      int cnt = 0;
      for (int l = 0, r = len; r < n; ++l, ++r) {
        cnt = s[l] == s[r] ? cnt + 1 : 0;
        if (cnt == len) {
          const auto h = mul(sum(prefix[l + len], -prefix[l]), pows[n - l]);
          seen.insert(h);
          --cnt;
        }
      }
    }
    return seen.size();
  }
};

} // namespace hash
