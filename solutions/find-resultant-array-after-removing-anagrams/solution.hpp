#pragma once

#include <algorithm>
#include <string>
#include <vector>

/*
  2273. Find Resultant Array After Removing Anagrams
  https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
  Difficulty: Easy
  Tags: Array, Hash Table, String, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::string>
  removeAnagrams(const std::vector<std::string> &words) {
    std::vector<std::string> ans;
    for (const auto &word : words) {
      if (ans.empty() || !IsAnagrams(ans.back(), word)) {
        ans.push_back(word);
      }
    }
    return ans;
  }

private:
  static bool IsAnagrams(std::string first, std::string second) {
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
    return first == second;
  }
};
