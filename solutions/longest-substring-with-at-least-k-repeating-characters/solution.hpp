#pragma once

#include <array>
#include <string>
#include <unordered_set>

// Time: O(NA)
// Space: O(A)

class Solution {
public:
  static int longestSubstring(std::string s, int k) {
    int ans = 0;
    const int maxUniq = std::unordered_set<char>(s.begin(), s.end()).size();
    for (int n = 1; n <= maxUniq; ++n) {
      ans = std::max(ans, longestSubstring(s, k, n));
    }
    return ans;
  }

private:
  static int longestSubstring(const std::string &s, int k, int n) {
    int nAtLeastK = 0;
    int nUniq = 0;
    int ans = 0;
    std::array<int, 128> cnt{};
    for (int l = 0, r = 0; r < std::ssize(s); ++r) {
      nUniq += cnt[s[r]] == 0;
      nAtLeastK += cnt[s[r]] == k - 1;
      ++cnt[s[r]];

      while (nUniq > n) {
        nUniq -= cnt[s[l]] == 1;
        nAtLeastK -= cnt[s[l]] == k;
        --cnt[s[l++]];
      }

      if (nAtLeastK == n) {
        ans = std::max(ans, r - l + 1);
      }
    }
    return ans;
  }
};
