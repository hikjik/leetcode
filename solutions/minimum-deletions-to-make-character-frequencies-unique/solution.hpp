#pragma once

#include <string>
#include <unordered_set>
#include <vector>

/*
  1647. Minimum Deletions to Make Character Frequencies Unique
  https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
  Difficulty: Medium
  Tags: Hash Table, String, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int minDeletions(std::string s) {
    std::vector<int> counter(26, 0);
    for (auto c : s) {
      counter[c - 'a']++;
    }

    int cnt = 0;
    std::unordered_set<int> seen;
    for (auto c : counter) {
      while (c && !seen.insert(c).second) {
        c--;
        cnt++;
      }
    }
    return cnt;
  }
};
