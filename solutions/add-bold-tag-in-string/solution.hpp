#pragma once

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

// Time: O(N^2+MK)
// Space: O(N+MK)

namespace bold {

// Time: O(N^2MK)
// Space: O(N)
class Solution {
public:
  static std::string addBoldTag(const std::string &s,
                                const std::vector<std::string> &words) {
    const int n = s.size();
    std::vector<bool> bold(n);
    for (const auto &word : words) {
      for (auto pos = s.find(word); pos != std::string::npos;
           pos = s.find(word, pos + 1)) {
        std::fill_n(bold.begin() + pos, word.size(), true);
      }
    }

    std::string ans;
    for (int i = 0; i < n; ++i) {
      if (bold[i] && (i == 0 || !bold[i - 1])) {
        ans += "<b>";
      }
      ans += s[i];
      if (bold[i] && (i == n - 1 || !bold[i + 1])) {
        ans += "</b>";
      }
    }
    return ans;
  }
};

} // namespace bold

namespace trie {

// Time: O(N^2+MK)
// Space: O(N+MK)
struct TrieNode {
  std::array<std::unique_ptr<TrieNode>, 128> children;
  bool terminal = false;
};

class Trie : private TrieNode {
public:
  void insert(std::string_view word) {
    TrieNode *node = this;
    for (auto c : word) {
      if (!node->children[c]) {
        node->children[c] = std::make_unique<TrieNode>();
      }
      node = node->children[c].get();
    }
    node->terminal = true;
  }

  int matchLength(std::string_view s) {
    TrieNode *node = this;
    int ans = 0;
    for (int i = 0; i < std::ssize(s); ++i) {
      node = node->children[s[i]].get();
      if (!node) {
        break;
      }
      if (node->terminal) {
        ans = i + 1;
      }
    }
    return ans;
  }
};

class Solution {
public:
  static std::string addBoldTag(const std::string &s,
                                const std::vector<std::string> &words) {
    const int n = s.size();
    const std::string_view sv(s);

    Trie trie;
    for (const auto &word : words) {
      trie.insert(word);
    }

    std::vector<bool> bold(n);
    for (int end = -1, i = 0; i < n; ++i) {
      end = std::max(end, i + trie.matchLength(sv.substr(i)));
      bold[i] = end > i;
    }

    std::string ans;
    for (int i = 0; i < n; ++i) {
      if (bold[i] && (i == 0 || !bold[i - 1])) {
        ans += "<b>";
      }
      ans += s[i];
      if (bold[i] && (i == n - 1 || !bold[i + 1])) {
        ans += "</b>";
      }
    }
    return ans;
  }
};

} // namespace trie
