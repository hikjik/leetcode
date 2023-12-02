#pragma once

#include <array>
#include <memory>
#include <ranges>
#include <string>
#include <string_view>

// Time: O(QM)
// Space: O(QM)

struct TrieNode {
  std::array<std::unique_ptr<TrieNode>, 26> children;
  bool terminal = false;
};

class WordDictionary : private TrieNode {
public:
  // O(M)
  void addWord(const std::string &word) {
    TrieNode *node = this;
    for (auto c : word) {
      const auto index = c - 'a';
      if (!node->children[index]) {
        node->children[index] = std::make_unique<TrieNode>();
      }
      node = node->children[index].get();
    }
    node->terminal = true;
  }

  // O(M)
  bool search(const std::string &word) const { return search(word, this); }

private:
  bool search(std::string_view s, const TrieNode *node) const {
    if (!node) {
      return false;
    }
    if (s.empty()) {
      return node->terminal;
    }

    if (s[0] == '.') {
      return std::ranges::any_of(node->children, [&](const auto &child) {
        return search(s.substr(1), child.get());
      });
    }
    return search(s.substr(1), node->children[s[0] - 'a'].get());
  }
};
