#pragma once

#include <queue>
#include <string>
#include <vector>

/*
  2246. Longest Path With Different Adjacent Characters
  https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
  Difficulty: Hard
  Tags: Array, String, Tree, Depth-First Search, Graph, Topological Sort
  Time:
  Space:
*/

class Solution {
public:
  static int longestPath(const std::vector<int> &parent, const std::string &s) {
    const int n = parent.size();

    std::vector<int> in_degree(n, 0);
    for (auto u : parent) {
      if (u != -1) {
        ++in_degree[u];
      }
    }

    std::queue<int> queue;
    for (int u = 0; u < n; ++u) {
      if (!in_degree[u]) {
        queue.push(u);
      }
    }

    int max_length = 1;
    std::vector<int> dp(n, 1);
    while (!queue.empty()) {
      const auto u = queue.front();
      queue.pop();

      const auto p = parent[u];
      if (p == -1) {
        continue;
      }

      if (s[u] != s[p]) {
        max_length = std::max(max_length, dp[u] + dp[p]);
        dp[p] = std::max(dp[p], dp[u] + 1);
      }

      if (!--in_degree[p]) {
        queue.push(p);
      }
    }
    return max_length;
  }
};
