#pragma once

#include <queue>
#include <vector>

/*
  1203. Sort Items by Groups Respecting Dependencies
  https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
  Difficulty: Hard
  Tags: Depth-First Search, Breadth-First Search, Graph, Topological Sort
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<int>
  sortItems(int n, int m, std::vector<int> group,
            const std::vector<std::vector<int>> &beforeItems) {
    for (auto &g : group) {
      if (g == -1) {
        g = m++;
      }
    }

    std::vector<std::vector<int>> group_graph(m);
    std::vector<std::vector<int>> item_graph(n);

    for (int u = 0; u < n; ++u) {
      for (auto v : beforeItems[u]) {
        item_graph[v].push_back(u);
        if (group[u] != group[v]) {
          group_graph[group[v]].push_back(group[u]);
        }
      }
    }

    const auto groups_in_order = sortTopologically(group_graph);
    const auto items_in_order = sortTopologically(item_graph);
    if (groups_in_order.empty() || items_in_order.empty()) {
      return {};
    }

    std::vector<std::vector<int>> groups_items_in_order(m);
    for (auto item : items_in_order) {
      groups_items_in_order[group[item]].push_back(item);
    }

    std::vector<int> items;
    for (auto group_id : groups_in_order) {
      for (auto item : groups_items_in_order[group_id]) {
        items.push_back(item);
      }
    }
    return items;
  }

private:
  static std::vector<int>
  sortTopologically(const std::vector<std::vector<int>> &graph) {
    std::vector<int> in_degree(graph.size());
    for (size_t u = 0; u < graph.size(); ++u) {
      for (auto v : graph[u]) {
        ++in_degree[v];
      }
    }

    std::queue<int> queue;
    for (size_t i = 0; i < in_degree.size(); ++i) {
      if (!in_degree[i]) {
        queue.push(i);
      }
    }

    std::vector<int> visited;
    while (!queue.empty()) {
      const auto u = queue.front();
      queue.pop();

      visited.push_back(u);
      for (auto v : graph[u]) {
        if (!--in_degree[v]) {
          queue.push(v);
        }
      }
    }

    if (visited.size() != graph.size()) {
      visited.clear();
    }
    return visited;
  }
};
