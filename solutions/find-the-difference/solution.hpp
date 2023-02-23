#pragma once

#include <string>
#include <unordered_map>

class Solution {
public:
  static char findTheDifference(std::string s, std::string t) {
    std::unordered_map<char, int> umap;
    for (auto c : s) {
      umap[c]++;
    }

    for (auto c : t) {
      if (!umap[c]--) {
        return c;
      }
    }
    return '0';
  }
};