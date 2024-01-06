#pragma once

#include <queue>
#include <ranges>
#include <vector>

// Time: O(N)
// Space: O(N)

namespace uf {

// Time: O(N&alpha;(N))
// Space: O(N)
class DisjointSets {
public:
  explicit DisjointSets(size_t size) : sets_(size), count_(size) {
    for (size_t i = 0; i < sets_.size(); ++i) {
      sets_[i].parent = i;
    }
  }

  size_t Count() { return count_; }

  size_t Parent(size_t i) {
    if (sets_[i].parent != i) {
      sets_[i].parent = Parent(sets_[i].parent);
    }
    return sets_[i].parent;
  }

  bool Merge(size_t u, size_t v) {
    size_t i = Parent(u), j = Parent(v);
    if (i == j) {
      return false;
    }
    count_--;

    if (sets_[i].rank > sets_[j].rank) {
      sets_[j].parent = i;
    } else {
      sets_[i].parent = j;
      if (sets_[i].rank == sets_[j].rank) {
        ++sets_[j].rank;
      }
    }
    return true;
  }

private:
  struct DisjointSetsElement {
    DisjointSetsElement() : parent(0), rank(0) {}

    size_t parent;
    size_t rank;
  };

  std::vector<DisjointSetsElement> sets_;
  size_t count_;
};

class Solution {
public:
  static bool validTree(int n, const std::vector<std::vector<int>> &edges) {
    if (n - 1 != std::ssize(edges)) {
      return false;
    }

    DisjointSets sets(n);
    for (const auto &edge : edges) {
      sets.Merge(edge[0], edge[1]);
    }
    return sets.Count() == 1;
  }
};

} // namespace uf

namespace dfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static bool validTree(int n, const std::vector<std::vector<int>> &edges) {
    if (n - 1 != std::ssize(edges)) {
      return false;
    }

    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    std::vector<bool> seen(n);
    dfs(0, graph, &seen);
    return std::ranges::all_of(seen, std::identity{});
  }

private:
  static void dfs(int u, const std::vector<std::vector<int>> &graph,
                  std::vector<bool> *seen) {
    (*seen)[u] = true;
    for (auto v : graph[u]) {
      if (!(*seen)[v]) {
        dfs(v, graph, seen);
      }
    }
  }
};

} // namespace dfs

namespace bfs {

// Time: O(N)
// Space: O(N)
class Solution {
public:
  static bool validTree(int n, const std::vector<std::vector<int>> &edges) {
    if (n - 1 != std::ssize(edges)) {
      return false;
    }

    std::vector<std::vector<int>> graph(n);
    for (const auto &edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    std::vector<bool> seen(n);
    std::queue<int> queue{{0}};
    while (!queue.empty()) {
      const auto u = queue.front();
      queue.pop();

      seen[u] = true;

      for (auto v : graph[u]) {
        if (!seen[v]) {
          queue.push(v);
        }
      }
    }
    return std::ranges::all_of(seen, std::identity{});
  }
};

} // namespace bfs
