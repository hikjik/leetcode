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

    int cnt = counter.size();
    int length = s.size() + 1;
    int pos = -1;
    for (int l = 0, r = 0; r < std::ssize(s); ++r) {
      cnt -= --counter[s[r]] == 0;
      while (!cnt) {
        if (r - l + 1 < length) {
          length = r - l + 1;
          pos = l;
        }
        cnt += ++counter[s[l++]] == 1;
      }
    }
    return pos == -1 ? "" : s.substr(pos, length);
  }
};
