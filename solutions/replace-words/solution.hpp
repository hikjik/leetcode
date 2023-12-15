#pragma once

#include <array>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

// M is the number of words in dictionary
// K is the average length of word in dictionary
// N is the length of the sentence
// Time: O(MK+N)
// Space: O(MK)

struct TrieNode {
  std::array<std::unique_ptr<TrieNode>, 26> children;
  bool terminal = false;
};

class Trie : private TrieNode {
public:
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

  std::string search(const std::string &word) const {
    const TrieNode *node = this;
    for (int i = 0; node && i < std::ssize(word); ++i) {
      node = node->children[word[i] - 'a'].get();
      if (!node) {
        return word;
      }
      if (node->terminal) {
        return word.substr(0, i + 1);
      }
    }
    return word;
  }
};

class Solution {
public:
  static std::string replaceWords(const std::vector<std::string> &dictionary,
                                  std::string sentence) {
    Trie trie;
    for (const auto &word : dictionary) {
      trie.insert(word);
    }

    std::string ans;
    std::stringstream sstream(sentence);
    for (std::string word; sstream >> word;) {
      ans += trie.search(word) + " ";
    }
    ans.pop_back();
    return ans;
  }
};
