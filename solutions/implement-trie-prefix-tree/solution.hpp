#pragma once

#include <array>
#include <memory>
#include <string>

// Time: O(QM)
// Space: O(QM)

struct TrieNode {
  std::array<std::unique_ptr<TrieNode>, 26> children;
  bool terminal = false;
};

class Trie : private TrieNode {
public:
  // O(M)
  void insert(const std::string &word) {
    TrieNode *node = this;
    for (auto c : word) {
      const auto i = c - 'a';
      if (!node->children[i]) {
        node->children[i] = std::make_unique<TrieNode>();
      }
      node = node->children[i].get();
    }
    node->terminal = true;
  }

  // O(M)
  bool search(const std::string &word) const {
    const auto *node = getPrefix(word);
    return node && node->terminal;
  }

  // O(M)
  bool startsWith(const std::string &prefix) const { return getPrefix(prefix); }

private:
  const TrieNode *getPrefix(const std::string &prefix) const {
    const TrieNode *node = this;
    for (int i = 0; node && i < std::ssize(prefix); ++i) {
      node = node->children[prefix[i] - 'a'].get();
    }
    return node;
  }
};
