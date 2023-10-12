#pragma once

#include <string>
#include <vector>

class Solution {
public:
  static int maximumRemovals(std::string s, std::string p,
                             const std::vector<int> &removable) {
    int left = 0, right = removable.size();
    while (left < right) {
      const auto middle = left + (right - left + 1) / 2;

      const auto marked = mark(s, removable, middle);
      if (isSubsequence(p, marked)) {
        left = middle;
      } else {
        right = middle - 1;
      }
    }
    return left;
  }

private:
  static std::string mark(const std::string &s,
                          const std::vector<int> &removable, int k) {
    std::string marked(s);
    for (int i = 0; i < k; ++i) {
      marked[removable[i]] = '#';
    }
    return marked;
  }

  static bool isSubsequence(const std::string &s, const std::string &t) {
    size_t i = 0;
    for (auto c : t) {
      if (s[i] == c) {
        if (++i == s.size()) {
          return true;
        }
      }
    }
    return false;
  }
};
