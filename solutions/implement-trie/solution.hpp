#pragma once

#include <array>
#include <string>

class Trie {
private:
  struct TrieNode {
    TrieNode() { std::fill(children.begin(), children.end(), nullptr); }

    std::array<TrieNode *, 26> children;
    bool is_end = false;
  };

  TrieNode *root_;

  void FreeNode(TrieNode *node) {
    if (!node) {
      return;
    }
    for (auto child : node->children) {
      FreeNode(child);
    }
    delete node;
  }

public:
  Trie() : root_(new TrieNode()) {}

  ~Trie() { FreeNode(root_); }

  void insert(std::string word) {
    auto node = root_;
    for (auto c : word) {
      const auto i = c - 'a';
      if (!node->children[i]) {
        node->children[i] = new TrieNode();
      }
      node = node->children[i];
    }
    node->is_end = true;
  }

  TrieNode *getPrefix(std::string prefix) {
    auto node = root_;
    for (size_t i = 0; node && i < prefix.size(); ++i) {
      node = node->children[prefix[i] - 'a'];
    }
    return node;
  }

  bool search(std::string word) {
    auto node = getPrefix(word);
    return node && node->is_end;
  }

  bool startsWith(std::string prefix) { return getPrefix(prefix); }
};
