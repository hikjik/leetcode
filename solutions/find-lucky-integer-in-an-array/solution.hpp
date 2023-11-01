#pragma once

#include <map>
#include <vector>

/*
  1394. Find Lucky Integer in an Array
  https://leetcode.com/problems/find-lucky-integer-in-an-array/
  Difficulty: Easy
  Tags: Array, Hash Table, Counting
  Time:
  Space:
*/

class Solution {
public:
  static int findLucky(const std::vector<int> &arr) {
    std::map<int, int> counter;
    for (auto a : arr) {
      ++counter[a];
    }

    for (auto it = counter.rbegin(); it != counter.rend(); ++it) {
      if (it->first == it->second) {
        return it->first;
      }
    }
    return -1;
  }
};
