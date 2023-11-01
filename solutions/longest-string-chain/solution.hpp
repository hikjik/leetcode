#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

/*
  1048. Longest String Chain
  https://leetcode.com/problems/longest-string-chain/
  Difficulty: Medium
  Tags: Array, Hash Table, Two Pointers, String, Dynamic Programming
  Time:
  Space:
*/

class Solution {
public:
  static int longestStrChain(std::vector<std::string> words) {
    std::sort(words.begin(), words.end(), [](const auto &lhs, const auto &rhs) {
      return lhs.size() > rhs.size();
    });

    std::unordered_map<std::string, int> map;
    int chain_length = 0;
    for (const auto &word : words) {
      for (size_t i = 0; i < word.size(); ++i) {
        const auto predecessor = word.substr(0, i) + word.substr(i + 1);
        map[predecessor] = std::max(map[predecessor], map[word] + 1);
        chain_length = std::max(chain_length, map[predecessor]);
      }
    }
    return chain_length;
  }
};
