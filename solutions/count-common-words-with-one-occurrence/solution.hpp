#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

/*
  2085. Count Common Words With One Occurrence
  https://leetcode.com/problems/count-common-words-with-one-occurrence/
  Difficulty: Easy
  Tags: Array, Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int countWords(const std::vector<std::string> &words1,
                        const std::vector<std::string> &words2) {
    std::unordered_map<std::string, int> counter;
    for (const auto &word : words1) {
      ++counter[word];
    }

    for (const auto &word : words2) {
      if (auto it = counter.find(word); it != counter.end() && it->second < 2) {
        --it->second;
      }
    }

    return std::count_if(counter.begin(), counter.end(),
                         [](const auto &p) { return p.second == 0; });
  }
};
