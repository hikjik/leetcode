#pragma once

#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

// Time: O(NlogN)
// Space: O(1)

class Solution {
public:
  static std::string longestDupSubstring(std::string s) {
    std::string_view sv(s), ans;

    int l = 0, r = s.size() - 1;
    while (l < r) {
      const auto m = l + (r - l + 1) / 2;
      const auto pos = dupSubstring(s, m);
      if (pos != std::string::npos) {
        l = m;
        ans = sv.substr(pos, m);
      } else {
        r = m - 1;
      }
    }
    return std::string(ans);
  }

private:
  using ulong = unsigned long long;

  static constexpr ulong kPrime = 31;

  static size_t dupSubstring(std::string_view s, int k) {
    const int n = s.size();

    ulong pk = 1;
    for (int i = 0; i < k; ++i) {
      pk = pk * kPrime;
    }

    ulong hash = 0;
    std::unordered_set<ulong> seen;
    for (int i = n - 1; i >= 0; --i) {
      hash = hash * kPrime + s[i];
      if (i + k < n) {
        hash = hash - s[i + k] * pk;
      }
      if (i + k <= n && !seen.insert(hash).second) {
        return i;
      }
    }

    return std::string::npos;
  }
};
