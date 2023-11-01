#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  1160. Find Words That Can Be Formed by Characters
  https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
  Difficulty: Easy
  Tags: Array, Hash Table, String
  Time:
  Space:
*/

class Solution {
public:
  static int countCharacters(std::vector<std::string> words,
                             std::string chars) {
    std::sort(chars.begin(), chars.end());
    int ans = 0;
    for (auto word : words) {
      std::sort(word.begin(), word.end());
      if (std::includes(chars.begin(), chars.end(), word.begin(), word.end())) {
        ans += word.size();
      }
    }
    return ans;
  }
};
