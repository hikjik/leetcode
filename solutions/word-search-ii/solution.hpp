#pragma once

#include <array>
#include <memory>
#include <string>
#include <vector>

class Solution {
private:
  static const char kVisited = '#';

  struct TrieNode {
    const static size_t kAlphabetSize = 26;

    std::array<std::unique_ptr<TrieNode>, kAlphabetSize> children;
    std::unique_ptr<std::string> word;
  };

public:
  static std::vector<std::string>
  findWords(std::vector<std::vector<char>> board,
            const std::vector<std::string> &words) {
    const int m = board.size(), n = board.back().size();

    auto root = std::make_unique<TrieNode>();
    for (const auto &word : words) {
      insert(root.get(), word);
    }

    std::vector<std::string> found_words;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        findWords(i, j, board, root.get(), &found_words);
      }
    }
    return found_words;
  }

private:
  static void insert(TrieNode *root, std::string word) {
    auto node = root;
    for (auto c : word) {
      const auto i = c - 'a';
      if (!node->children[i]) {
        node->children[i] = std::make_unique<TrieNode>();
      }
      node = node->children[i].get();
    }
    node->word = std::make_unique<std::string>(std::move(word));
  }

  static void findWords(int i, int j, std::vector<std::vector<char>> &board,
                        TrieNode *node, std::vector<std::string> *found_words) {
    static std::vector<std::pair<int, int>> dirs{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    const char m = board.size(), n = board.back().size();
    if (i < 0 || i >= m || j < 0 || j >= n) {
      return;
    }

    const char symbol = board[i][j];
    if (symbol == kVisited) {
      return;
    }

    node = node->children[symbol - 'a'].get();
    if (!node) {
      return;
    }
    if (node->word) {
      found_words->push_back(*node->word);
      node->word.reset();
    }

    board[i][j] = kVisited;
    for (const auto &[di, dj] : dirs) {
      findWords(i + di, j + dj, board, node, found_words);
    }
    board[i][j] = symbol;
  }
};
