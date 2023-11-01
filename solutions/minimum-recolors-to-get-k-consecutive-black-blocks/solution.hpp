#pragma once

#include <string>

/*
  2379. Minimum Recolors to Get K Consecutive Black Blocks
  https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
  Difficulty: Easy
  Tags: String, Sliding Window
  Time:
  Space:
*/

class Solution {
public:
  static int minimumRecolors(std::string blocks, int k) {
    const int n = blocks.size();
    int cnt = 0, max = 0;
    for (int i = 0; i < n; ++i) {
      if (blocks[i] == 'B') {
        ++cnt;
      }
      if (i >= k && blocks[i - k] == 'B') {
        --cnt;
      }
      max = std::max(max, cnt);
    }
    return k - max;
  }
};
