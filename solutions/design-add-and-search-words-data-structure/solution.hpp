#pragma once

#include <array>
#include <string>

/*
  211. Design Add and Search Words Data Structure
  https://leetcode.com/problems/design-add-and-search-words-data-structure/
  Difficulty: Medium
  Tags: String, Depth-First Search, Design, Trie
  Time:
  Space:
*/

class WordDictionary {
private:
  struct TrieNode {
    const static size_t ALPHABET_SIZE = 26;

    std::array<TrieNode *, ALPHABET_SIZE> children = {nullptr};
    bool is_end = false;
  };

  TrieNode *root = nullptr;

  void DeleteNode(TrieNode *node) {
    if (!node) {
      return;
    }
    for (auto child : node->children) {
      DeleteNode(child);
    }
    delete node;
  }

public:
  WordDictionary() : root(new TrieNode) {}

  ~WordDictionary() { DeleteNode(root); }

  void addWord(std::string word) {
    auto node = root;
    for (auto c : word) {
      const auto index = c - 'a';
      if (!node->children[index]) {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }
    node->is_end = true;
  }

  bool search(std::string word) { return search(0, word, root); }

private:
  bool search(size_t i, const std::string &word, TrieNode *node) {
    if (i == word.size()) {
      return node->is_end;
    }

    if (word[i] == '.') {
      for (auto child : node->children) {
        if (child && search(i + 1, word, child)) {
          return true;
        }
      }
      return false;
    }

    auto child = node->children[word[i] - 'a'];
    return child && search(i + 1, word, child);
  }
};
