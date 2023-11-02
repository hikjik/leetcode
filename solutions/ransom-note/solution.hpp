#pragma once

#include <string>
#include <unordered_map>

// Time:
// Space:

class Solution {
public:
  static bool canConstruct(std::string ransom_note, std::string magazine) {
    std::unordered_map<char, int> umap;
    for (auto c : magazine) {
      umap[c]++;
    }

    for (auto c : ransom_note) {
      if (!umap[c]--) {
        return false;
      }
    }

    return true;
  }
};