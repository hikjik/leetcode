#pragma once

#include <memory>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// N = text.size()
// M = words.size()
// K = words[i].size()
// Time: O(N^2+MK)
// Space: O(MK)

namespace match {

// Time: O(MlogM+NMK)
// Space: O(MK)
class Solution {
public:
  static std::vector<std::vector<int>>
  indexPairs(std::string text, std::vector<std::string> words) {
    std::ranges::sort(words, {}, &std::string::size);
    const int n = text.size();
    const std::string_view sv(text);
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < n; ++i) {
      for (const auto &word : words) {
        const int k = word.size();
        if (i + k > n) {
          continue;
        }
        if (sv.substr(i, k) == word) {
          ans.push_back({i, i + k - 1});
        }
      }
    }
    return ans;
  }
};

} // namespace match

namespace hs {

// Time: O(N^3+MK)
// Space: O(M)
class Solution {
public:
  static std::vector<std::vector<int>>
  indexPairs(std::string text, const std::vector<std::string> &words) {
    const std::unordered_set<std::string_view> wordsSet{words.begin(),
                                                        words.end()};
    const std::string_view sv(text);

    std::vector<std::vector<int>> ans;
    for (int i = 0; i < std::ssize(sv); ++i) {
      for (int j = i; j < std::ssize(sv); ++j) {
        if (wordsSet.contains(sv.substr(i, j - i + 1))) {
          ans.push_back({i, j});
        }
      }
    }
    return ans;
  }
};

} // namespace hs

namespace trie {

// Time: O(N^2+MK)
// Space: O(MK)
struct TrieNode {
  std::unordered_map<char, std::unique_ptr<TrieNode>> children;
  bool terminal;
};

class Trie : private TrieNode {
public:
  void insert(std::string_view s) {
    auto *node = Root();
    for (auto c : s) {
      if (!node->children.contains(c)) {
        node->children[c] = std::make_unique<TrieNode>();
      }
      node = node->children[c].get();
    }
    node->terminal = true;
  }

  TrieNode *Root() { return this; }

  TrieNode *next(TrieNode *node, char c) {
    if (!node) {
      return nullptr;
    }
    return node->children[c].get();
  }
};

class Solution {
public:
  static std::vector<std::vector<int>>
  indexPairs(std::string text, const std::vector<std::string> &words) {
    Trie trie;
    for (const auto &word : words) {
      trie.insert(word);
    }

    std::vector<std::vector<int>> ans;
    const int n = text.size();
    for (int i = 0; i < n; ++i) {
      auto *node = trie.Root();
      for (int j = i; j < n; ++j) {
        node = trie.next(node, text[j]);
        if (!node) {
          break;
        }
        if (node->terminal) {
          ans.push_back({i, j});
        }
      }
    }
    return ans;
  }
};

} // namespace trie
