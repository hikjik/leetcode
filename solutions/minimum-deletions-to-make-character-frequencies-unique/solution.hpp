#pragma once

#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  static int minDeletions(std::string s) {
    std::vector<int> counter(26, 0);
    for (auto c : s) {
      counter[c - 'a']++;
    }

    int cnt = 0;
    std::unordered_set<int> seen;
    for (auto c : counter) {
      while (c && !seen.insert(c).second) {
        c--;
        cnt++;
      }
    }
    return cnt;
  }
};
