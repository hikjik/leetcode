#pragma once

#include <array>
#include <numeric>
#include <string>

// Time: O(N)
// Space: O(A)

class Solution {
public:
  static bool checkIfCanBreak(std::string s1, std::string s2) {
    const int n = s1.size();

    std::array<int, 26> cnt{};
    for (int i = 0; i < n; ++i) {
      ++cnt[s1[i] - 'a'];
      --cnt[s2[i] - 'a'];
    }
    std::partial_sum(cnt.cbegin(), cnt.cend(), cnt.begin());

    bool le = true, ge = true;
    for (auto a : cnt) {
      le &= a <= 0;
      ge &= a >= 0;
    }
    return le || ge;
  }
};
