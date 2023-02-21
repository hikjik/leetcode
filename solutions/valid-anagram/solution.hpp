#pragma once

#include <string>
#include <unordered_map>

class Solution {
public:
  static bool isAnagram(std::string ransom_note, std::string magazine) {
    std::unordered_map<char, int> umap;
    for (auto c : magazine) {
      umap[c]++;
    }

    for (auto c : ransom_note) {
      umap[c]--;
    }

    for (const auto &[key, value] : umap) {
      if (value) {
        return false;
      }
    }

    return true;
  }
};