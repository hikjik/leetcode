#pragma once

#include <vector>

// Time: O(NlogN)
// Space: O(N)

class Solution {
public:
  static std::vector<long long>
  placedCoins(const std::vector<std::vector<int>> &edges,
              const std::vector<int> &cost) {
    const int n = edges.size() + 1;
    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    std::vector<long long> ans(n);
    dfs(0, -1, graph, cost, &ans);
    return ans;
  }

private:
  static std::vector<int> dfs(int u, int p,
                              const std::vector<std::vector<int>> &graph,
                              const std::vector<int> &cost,
                              std::vector<long long> *ans) {
    std::vector<int> vals{cost[u]};
    for (auto v : graph[u]) {
      if (v == p) {
        continue;
      }
      std::ranges::copy(dfs(v, u, graph, cost, ans), std::back_inserter(vals));
    }

    const int m = vals.size();
    if (m < 3) {
      (*ans)[u] = 1;
      return vals;
    }

    std::ranges::sort(vals);
    (*ans)[u] = std::max({
        0LL,
        1LL * vals[0] * vals[1] * vals[m - 1],
        1LL * vals[m - 3] * vals[m - 2] * vals[m - 1],
    });

    if (m > 5) {
      vals.erase(vals.begin() + 2, vals.begin() + m - 3);
    }
    return vals;
  }
};
