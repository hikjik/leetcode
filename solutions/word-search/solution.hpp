#pragma once

#include <string>
#include <vector>

/*
  79. Word Search
  https://leetcode.com/problems/word-search/
  Difficulty: Medium
  Tags: Array, Backtracking, Matrix
  Time:
  Space:
*/

class Solution {
public:
  static bool exist(const std::vector<std::vector<char>> &board,
                    std::string word) {
    int m = board.size(), n = board.back().size();
    std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (exist(i, j, board, 0, word, &visited)) {
          return true;
        }
      }
    }
    return false;
  }

private:
  static bool exist(int i, int j, const std::vector<std::vector<char>> &board,
                    size_t k, const std::string &word,
                    std::vector<std::vector<bool>> *visited) {
    static std::vector<std::pair<int, int>> directions{
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int m = board.size(), n = board.back().size();
    if (i < 0 || i >= m || j < 0 || j >= n || (*visited)[i][j] ||
        word[k] != board[i][j]) {
      return false;
    }
    if (k + 1 == word.size()) {
      return true;
    }

    (*visited)[i][j] = true;
    for (auto [di, dj] : directions) {
      if (exist(i + di, j + dj, board, k + 1, word, visited)) {
        return true;
      }
    }
    (*visited)[i][j] = false;

    return false;
  }
};
