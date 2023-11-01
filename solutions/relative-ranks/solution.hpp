#pragma once

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

/*
  506. Relative Ranks
  https://leetcode.com/problems/relative-ranks/
  Difficulty: Easy
  Tags: Array, Sorting, Heap (Priority Queue)
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::string>
  findRelativeRanks(const std::vector<int> &score) {
    std::vector<int> indexes(score.size());
    std::iota(indexes.begin(), indexes.end(), 0);
    std::sort(indexes.begin(), indexes.end(),
              [&](int i, int j) { return score[i] > score[j]; });

    std::vector<std::string> ans(score.size());
    for (int i = 0; i < std::ssize(score); ++i) {
      ans[indexes[i]] = getRank(i);
    }
    return ans;
  }

private:
  static std::string getRank(int i) {
    switch (i) {
    case 0:
      return "Gold Medal";
    case 1:
      return "Silver Medal";
    case 2:
      return "Bronze Medal";
    default:
      return std::to_string(i + 1);
    }
  }
};
