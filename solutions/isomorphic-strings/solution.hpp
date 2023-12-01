#pragma once

#include <string>
#include <unordered_map>

// Time: O(N)
// Space: O(N)

class Solution {
public:
  static bool isIsomorphic(std::string s1, std::string s2) {
    std::unordered_map<char, int> map1, map2;
    for (int i = 0; i < std::ssize(s1); ++i) {
      if (map1[s1[i]] != map2[s2[i]]) {
        return false;
      }
      map1[s1[i]] = map2[s2[i]] = i + 1;
    }
    return true;
  }
};
