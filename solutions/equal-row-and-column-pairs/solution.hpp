#pragma once

#include <unordered_map>
#include <vector>

struct HashVector {
  size_t operator()(const std::vector<int> &nums) const {
    std::hash<int> hasher;

    size_t res = 0;
    for (int a : nums) {
      res ^= hasher(a) + 0x9e3779b9 + (res << 6) + (res >> 2);
    }
    return res;
  }
};

/*
  2352. Equal Row and Column Pairs
  https://leetcode.com/problems/equal-row-and-column-pairs/
  Difficulty: Medium
  Tags: Array, Hash Table, Matrix, Simulation
  Time:
  Space:
*/

class Solution {
public:
  static int equalPairs(const std::vector<std::vector<int>> &grid) {
    return hashFunction(grid);
  }

private:
  static int hashFunction(const std::vector<std::vector<int>> &grid) {
    std::unordered_map<std::vector<int>, int, HashVector> map;
    for (const auto &row : grid) {
      ++map[row];
    }

    int cnt = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
      std::vector<int> col(grid.size());
      for (size_t j = 0; j < grid.size(); ++j) {
        col[j] = grid[j][i];
      }
      if (auto it = map.find(col); it != map.end()) {
        cnt += it->second;
      }
    }
    return cnt;
  }

  static int bruteForce(const std::vector<std::vector<int>> &grid) {
    const int n = grid.size();

    int cnt = n * n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          if (grid[i][k] != grid[k][j]) {
            --cnt;
            break;
          }
        }
      }
    }
    return cnt;
  }
};
