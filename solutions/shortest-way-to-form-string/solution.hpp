#pragma once

#include <array>
#include <string>

// Time: O(AS+T)
// Space: O(AS)

namespace two_pointers {

// Time: O(ST)
// Space: O(1)
class Solution {
public:
  static int shortestWay(std::string source, std::string target) {
    int ans = 0;
    for (int l = 0, r = 0; l < std::ssize(target); l = r) {
      r = l;
      for (auto c : source) {
        if (target[r] == c) {
          ++r;
        }
      }
      if (r == l) {
        return -1;
      }
      ++ans;
    }
    return ans;
  }
};

} // namespace two_pointers

namespace preprocessing {

// Time: O(AS+T)
// Space: O(AS)
class Solution {
public:
  static constexpr int kSize = 1000;

  static int shortestWay(std::string s, std::string t) {
    std::array<std::array<int, 26>, kSize + 1> next;
    next[s.size()].fill(-1);

    for (int i = s.size() - 1; i >= 0; --i) {
      next[i] = next[i + 1];
      next[i][s[i] - 'a'] = i;
    }

    int ans = 0;
    for (int i = 0; auto c : t) {
      if (next[0][c - 'a'] == -1) {
        return -1;
      }
      if (i == std::ssize(s) || next[i][c - 'a'] == -1) {
        i = 0;
        ++ans;
      }
      i = next[i][c - 'a'] + 1;
    }
    return ans + 1;
  }
};

} // namespace preprocessing
