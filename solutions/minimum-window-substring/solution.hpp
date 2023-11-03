#pragma once

#include <string>
#include <unordered_map>

// Time: O(N+M)
// Space: O(A), where A is the size of the alphabet

class Solution {
public:
  static std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> counter;
    for (auto c : t) {
      ++counter[c];
    }

    int need = t.size();
    int min_size = 1 + s.size();
    int pos = -1;
    for (int l = 0, r = 0; r < std::ssize(s); ++r) {
      if (--counter[s[r]] >= 0) {
        --need;
      }
      while (!need) {
        if (r - l + 1 < min_size) {
          min_size = r - l + 1;
          pos = l;
        }
        if (++counter[s[l++]] > 0) {
          ++need;
        }
      }
    }
    return pos == -1 ? "" : s.substr(pos, min_size);
  }
};
