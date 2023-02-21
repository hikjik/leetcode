#pragma once

#include <string>
#include <unordered_map>

class Solution {
public:
  static int firstUniqChar(std::string str) {
    std::unordered_map<char, int> umap;
    for (auto c : str) {
      umap[c]++;
    }
    for (size_t i = 0; i < str.size(); ++i) {
      if (umap[str[i]] == 1) {
        return i;
      }
    }
    return -1;
  }
};