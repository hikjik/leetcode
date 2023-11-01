#pragma once

#include <unordered_map>
#include <vector>

/*
  947. Most Stones Removed with Same Row or Column
  https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
  Difficulty: Medium
  Tags: Hash Table, Depth-First Search, Union Find, Graph
  Time:
  Space:
*/

class Solution {
public:
  static int removeStones(const std::vector<std::vector<int>> &stones) {
    int n = stones.size();
    std::unordered_map<int, std::vector<int>> rows_to_stones;
    std::unordered_map<int, std::vector<int>> cols_to_stones;

    for (int i = 0; i < n; ++i) {
      rows_to_stones[stones[i][0]].push_back(i);
      cols_to_stones[stones[i][1]].push_back(i);
    }

    int components_count = 0;
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        components_count++;
        visited[i] = true;
        dfs(rows_to_stones, cols_to_stones, stones, i, &visited);
      }
    }
    return n - components_count;
  }

private:
  static void
  dfs(const std::unordered_map<int, std::vector<int>> &rows_to_stones,
      const std::unordered_map<int, std::vector<int>> &cols_to_stones,
      const std::vector<std::vector<int>> &stones, int i,
      std::vector<bool> *visited) {
    for (auto j : rows_to_stones.at(stones[i][0])) {
      if (!(*visited)[j]) {
        (*visited)[j] = true;
        dfs(rows_to_stones, cols_to_stones, stones, j, visited);
      }
    }
    for (auto j : cols_to_stones.at(stones[i][1])) {
      if (!(*visited)[j]) {
        (*visited)[j] = true;
        dfs(rows_to_stones, cols_to_stones, stones, j, visited);
      }
    }
  }
};
