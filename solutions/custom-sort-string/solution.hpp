#pragma once

#include <array>
#include <ranges>
#include <string>

// Time: O(N)
// Space: O(A)

namespace sorting {

// Time: O(NAlogNA)
// Space: O(1)
class Solution {
public:
  static std::string customSortString(std::string order, std::string s) {
    std::ranges::sort(
        s, [&](char a, char b) { return order.find(a) < order.find(b); });
    return s;
  }
};

} // namespace sorting

namespace counting {

// Time: O(N)
// Space: O(A)
class Solution {
public:
  static std::string customSortString(std::string order, std::string s) {
    std::array<int, 26> cnt{};
    for (auto c : s) {
      ++cnt[c - 'a'];
    }

    std::string ans;
    for (auto c : order) {
      while (cnt[c - 'a']--) {
        ans += c;
      }
    }
    for (char c = 'a'; c <= 'z'; ++c) {
      while (cnt[c - 'a']-- > 0) {
        ans += c;
      }
    }
    return ans;
  }
};

} // namespace counting
