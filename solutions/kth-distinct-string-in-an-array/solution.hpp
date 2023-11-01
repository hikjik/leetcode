#pragma once

#include <string>
#include <unordered_map>
#include <vector>

/*
  2053. Kth Distinct String in an Array
  https://leetcode.com/problems/kth-distinct-string-in-an-array/
  Difficulty: Easy
  Tags: Array, Hash Table, String, Counting
  Time:
  Space:
*/

class Solution {
public:
  static std::string kthDistinct(const std::vector<std::string> &arr, int k) {
    std::unordered_map<std::string, int> map;
    for (const auto &str : arr) {
      ++map[str];
    }

    for (const auto &str : arr) {
      if (map[str] == 1 && !--k) {
        return str;
      }
    }
    return "";
  }
};
