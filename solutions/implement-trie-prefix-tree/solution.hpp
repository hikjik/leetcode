#pragma once

#include <array>
#include <memory>
#include <string>

struct TrieNode {
  std::array<std::unique_ptr<TrieNode>, 26> children;
  bool is_end = false;
};

/*
  208. Implement Trie (Prefix Tree)
  https://leetcode.com/problems/implement-trie-prefix-tree/
  Difficulty: Medium
  Tags: Hash Table, String, Design, Trie
  Time:
  Space:
*/

class Trie : private TrieNode {
public:
  void insert(std::string word) {
    TrieNode *node = this;
    for (auto c : word) {
      const auto i = c - 'a';
      if (!node->children[i]) {
        node->children[i] = std::make_unique<TrieNode>();
      }
      node = node->children[i].get();
    }
    node->is_end = true;
  }

  TrieNode *getPrefix(std::string prefix) {
    TrieNode *node = this;
    for (size_t i = 0; node && i < prefix.size(); ++i) {
      node = node->children[prefix[i] - 'a'].get();
    }
    return node;
  }

  bool search(std::string word) {
    auto node = getPrefix(word);
    return node && node->is_end;
  }

  bool startsWith(std::string prefix) { return getPrefix(prefix); }
};
