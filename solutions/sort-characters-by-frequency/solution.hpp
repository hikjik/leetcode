#pragma once

#include <string>
#include <vector>

/*
  451. Sort Characters By Frequency
  https://leetcode.com/problems/sort-characters-by-frequency/
  Difficulty: Medium
  Tags: Hash Table, String, Sorting, Heap (Priority Queue), Bucket Sort,
        Counting
  Time:
  Space:
*/

class Solution {
public:
  static std::string frequencySort(std::string s) {
    std::vector<int> counter(128, 0);
    for (auto c : s) {
      counter[c]++;
    }

    std::vector<std::vector<char>> buckets(s.size() + 1);
    for (size_t i = 0; i < counter.size(); ++i) {
      buckets[counter[i]].push_back(char(i));
    }

    std::string sorted;
    for (int i = s.size(); i > 0; --i) {
      for (auto c : buckets[i]) {
        sorted += std::string(i, c);
      }
    }
    return sorted;
  }
};
