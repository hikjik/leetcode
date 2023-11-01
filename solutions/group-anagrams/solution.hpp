#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

/*
  49. Group Anagrams
  https://leetcode.com/problems/group-anagrams/
  Difficulty: Medium
  Tags: Array, Hash Table, String, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<std::string>>
  groupAnagrams(const std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    for (const auto &str : strs) {
      auto key = str;
      std::sort(key.begin(), key.end());
      map[key].push_back(str);
    }

    std::vector<std::vector<std::string>> groups;
    for (const auto &[key, anagrams] : map) {
      groups.push_back(anagrams);
    }
    return groups;
  }
};
