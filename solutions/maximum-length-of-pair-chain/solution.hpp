#pragma once

#include <algorithm>
#include <climits>
#include <vector>

/*
  646. Maximum Length of Pair Chain
  https://leetcode.com/problems/maximum-length-of-pair-chain/
  Difficulty: Medium
  Tags: Array, Dynamic Programming, Greedy, Sorting
  Time:
  Space:
*/

class Solution {
public:
  static int findLongestChain(std::vector<std::vector<int>> pairs) {
    std::sort(pairs.begin(), pairs.end(),
              [](const auto &lhs, const auto &rhs) { return lhs[1] < rhs[1]; });

    int chain_length = 0;
    int end = INT_MIN;
    for (const auto &pair : pairs) {
      if (end < pair[0]) {
        ++chain_length;
        end = pair[1];
      }
    }
    return chain_length;
  }
};
