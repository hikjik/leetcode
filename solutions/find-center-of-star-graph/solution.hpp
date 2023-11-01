#pragma once

#include <vector>

/*
  1791. Find Center of Star Graph
  https://leetcode.com/problems/find-center-of-star-graph/
  Difficulty: Easy
  Tags: Graph
  Time:
  Space:
*/

class Solution {
public:
  static int findCenter(const std::vector<std::vector<int>> &edges) {
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
      return edges[0][0];
    }
    return edges[0][1];
  }
};
