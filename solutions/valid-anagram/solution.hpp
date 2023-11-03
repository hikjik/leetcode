#pragma once

#include <array>
#include <ranges>
#include <string>

// Time: O(N)
// Space: O(A), where A is the size of the alphabet

class Solution {
public:
  static constexpr size_t kSize = 26;

  static bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) {
      return false;
    }
    std::array<int, kSize> counter{};
    for (size_t i = 0; i < s.size(); ++i) {
      ++counter[s[i] - 'a'];
      --counter[t[i] - 'a'];
    }
    return std::ranges::all_of(counter, [](int a) { return !a; });
  }
};
