#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static std::string longestPalindrome(std::string s) {
    std::string t = "^";
    for (auto c : s) {
      t += '#', t += c;
    }
    t += '#', t += '$';

    std::vector<int> p(t.size());
    for (int i = 1, l = 1, r = 1; i < std::ssize(t) - 1; ++i) {
      const int j = l + r - i;
      p[i] = std::max(0, std::min(r - i, p[j]));

      while (t[i - p[i]] == t[i + p[i]]) {
        ++p[i];
      }

      if (i + p[i] > r) {
        l = i - p[i], r = i + p[i];
      }
    }

    const auto c = std::ranges::max_element(p) - p.begin();
    const auto l = (c - p[c]) / 2, r = (c + p[c]) / 2;
    return s.substr(l, r - l - 1);
  }
};
