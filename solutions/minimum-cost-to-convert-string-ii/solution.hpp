#pragma once

#include <optional>
#include <string>
#include <vector>

// M = source.size()
// K = original.size()
// L = original[i].size()
// Time: O(KL+K^3+M^2)
// Space: O(KL+K^2+M)

struct TrieNode {
  TrieNode *children[26]{};
  std::optional<int> id;

  TrieNode *next(char c) const { return children[c - 'a']; }
  bool isTerminal() const { return id.has_value(); }
  int value() const { return id.value(); }
};

class Trie : private TrieNode {
public:
  std::pair<TrieNode *, bool> insert(const std::string &word, int id) {
    auto *node = root();
    for (auto c : word) {
      const auto i = c - 'a';
      if (!node->children[i]) {
        node->children[i] = new TrieNode();
      }
      node = node->next(c);
    }
    if (node->isTerminal()) {
      return {node, false};
    }
    node->id = id;
    return {node, true};
  }

  TrieNode *getPrefix(const std::string &prefix) {
    auto *node = root();
    for (auto c : prefix) {
      if (!node) {
        break;
      }
      node = node->next(c);
    }
    return node;
  }

  TrieNode *root() { return this; }
};

class Solution {
public:
  static constexpr long long kInf = 0x3f3f3f3f3f3f3f3f;
  static constexpr long long kMaxN = 201;

  static long long minimumCost(std::string source, std::string target,
                               const std::vector<std::string> &original,
                               const std::vector<std::string> &changed,
                               const std::vector<int> &cost) {
    int n = 0;
    Trie trie;
    for (int i = 0; i < std::ssize(original); ++i) {
      n += trie.insert(original[i], n).second;
      n += trie.insert(changed[i], n).second;
    }

    long long dist[kMaxN][kMaxN];
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        dist[u][v] = kInf;
      }
      dist[u][u] = 0;
    }
    for (int i = 0; i < std::ssize(original); ++i) {
      const auto u = trie.getPrefix(original[i])->value();
      const auto v = trie.getPrefix(changed[i])->value();
      dist[u][v] = std::min(dist[u][v], cost[i] * 1LL);
    }
    for (int w = 0; w < n; ++w) {
      for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
          dist[u][v] = std::min(dist[u][v], dist[u][w] + dist[w][v]);
        }
      }
    }

    const int m = source.size();
    std::vector<long long> dp(m + 1, kInf);
    dp.back() = 0;

    for (int i = m - 1; i >= 0; --i) {
      if (source[i] == target[i]) {
        dp[i] = std::min(dp[i], dp[i + 1]);
      }
      auto *node1 = trie.root(), *node2 = trie.root();
      for (int j = i; j < m; ++j) {
        node1 = node1->next(source[j]), node2 = node2->next(target[j]);
        if (!node1 || !node2) {
          break;
        }
        if (node1->isTerminal() && node2->isTerminal()) {
          const auto u = node1->value(), v = node2->value();
          dp[i] = std::min(dp[i], dist[u][v] + dp[j + 1]);
        }
      }
    }
    return dp[0] == kInf ? -1 : dp[0];
  }
};
