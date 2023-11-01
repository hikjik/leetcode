#pragma once

#include <string>
#include <unordered_map>

/*
  387. First Unique Character in a String
  https://leetcode.com/problems/first-unique-character-in-a-string/
  Difficulty: Easy
  Tags: Hash Table, String, Queue, Counting
  Time:
  Space:
*/

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