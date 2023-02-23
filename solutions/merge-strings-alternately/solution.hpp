#pragma once

#include <string>

class Solution {
public:
  static std::string mergeAlternately(std::string word1, std::string word2) {
    std::string word;
    word.reserve(word1.size() + word2.size());

    size_t left = 0, right = 0;
    while (left < word1.size() || right < word2.size()) {
      if (left < word1.size()) {
        word += word1[left++];
      }

      if (right < word2.size()) {
        word += word2[right++];
      }
    }

    return word;
  }
};