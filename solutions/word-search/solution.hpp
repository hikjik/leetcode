#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

// Time: O(NM4^K), where K is length of the word
// Space: O(K)

class Solution {
public:
  static bool exist(std::vector<std::vector<char>> &board, std::string word) {
    const int m = board.size(), n = board.back().size();

    std::unordered_map<char, int> counter;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ++counter[board[i][j]];
      }
    }

    if (counter[word.front()] > counter[word.back()]) {
      std::ranges::reverse(word);
    }
    for (auto c : word) {
      if (!counter[c]--) {
        return false;
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (exist(i, j, board, std::string_view(word))) {
          return true;
        }
      }
    }
    return false;
  }

private:
  static bool exist(int i, int j, std::vector<std::vector<char>> &board,
                    std::string_view word) {
    const int m = board.size(), n = board.back().size();
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return false;
    }
    if (!word.starts_with(board[i][j])) {
      return false;
    }
    if (word.size() == 1) {
      return true;
    }

    const auto cache = board[i][j];
    board[i][j] = '*';
    const auto exists = exist(i, j + 1, board, word.substr(1)) ||
                        exist(i, j - 1, board, word.substr(1)) ||
                        exist(i + 1, j, board, word.substr(1)) ||
                        exist(i - 1, j, board, word.substr(1));
    board[i][j] = cache;
    return exists;
  }
};
