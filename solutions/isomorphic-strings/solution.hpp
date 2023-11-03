#pragma once

#include <string>
#include <unordered_map>

// Time:
// Space:

class Solution {
public:
  static bool isIsomorphic(std::string s, std::string t) {
    std::unordered_map<char, size_t> s_map;
    std::unordered_map<char, size_t> t_map;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s_map[s[i]] != t_map[t[i]]) {
        return false;
      }
      s_map[s[i]] = i + 1;
      t_map[t[i]] = i + 1;
    }
    return true;
  }
};
