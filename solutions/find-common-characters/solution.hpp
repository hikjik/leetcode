#pragma once

#include <climits>
#include <string>
#include <vector>

/*
  1002. Find Common Characters
  https://leetcode.com/problems/find-common-characters/
  Difficulty: Easy
  Tags: Array, Hash Table, String
  Time:
  Space:
*/

class Solution {
public:
  static constexpr int kSize = 26;

  static std::vector<std::string>
  commonChars(const std::vector<std::string> &words) {
    std::vector<int> counter(kSize, INT_MAX);

    for (const auto &word : words) {
      std::vector<int> cnt(kSize, 0);
      for (auto c : word) {
        ++cnt[c - 'a'];
      }
      for (int i = 0; i < kSize; ++i) {
        counter[i] = std::min(counter[i], cnt[i]);
      }
    }

    std::vector<std::string> ans;
    for (int i = 0; i < kSize; ++i) {
      ans.insert(ans.end(), counter[i], std::string(1, 'a' + i));
    }
    return ans;
  }
};
