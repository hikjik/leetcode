#pragma once

#include <string>
#include <unordered_map>

// Time:
// Space:

class Solution {
public:
  static bool checkInclusion(std::string s1, std::string s2) {
    if (s1.size() > s2.size()) {
      return false;
    }

    std::unordered_map<char, int> map1;
    for (auto c : s1) {
      map1[c]++;
    }

    std::unordered_map<char, int> map2;
    for (size_t i = 0; i < s1.size() - 1; ++i) {
      map2[s2[i]]++;
    }

    for (size_t i = s1.size() - 1; i < s2.size(); ++i) {
      map2[s2[i]]++;
      if (map1 == map2) {
        return true;
      }

      auto c = s2[i - s1.size() + 1];
      if (!--map2[c]) {
        map2.erase(c);
      }
    }
    return false;
  }
};
