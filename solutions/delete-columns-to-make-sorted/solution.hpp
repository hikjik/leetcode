#pragma once

#include <string>
#include <vector>

/*
  944. Delete Columns to Make Sorted
  https://leetcode.com/problems/delete-columns-to-make-sorted/
  Difficulty: Easy
  Tags: Array, String
  Time:
  Space:
*/

class Solution {
public:
  static int minDeletionSize(const std::vector<std::string> &strs) {
    int cnt = 0;
    for (size_t j = 0; j < strs.back().size(); ++j) {
      for (size_t i = 1; i < strs.size(); ++i) {
        if (strs[i - 1][j] > strs[i][j]) {
          ++cnt;
          break;
        }
      }
    }
    return cnt;
  }
};
