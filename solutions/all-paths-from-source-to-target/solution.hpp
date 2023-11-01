#pragma once

#include <vector>

/*
  797. All Paths From Source to Target
  https://leetcode.com/problems/all-paths-from-source-to-target/
  Difficulty: Medium
  Tags: Backtracking, Depth-First Search, Breadth-First Search, Graph
  Time:
  Space:
*/

class Solution {
public:
  static std::vector<std::vector<int>>
  allPathsSourceTarget(const std::vector<std::vector<int>> &graph) {
    std::vector<std::vector<int>> paths;
    std::vector<int> path;
    dfs(0, graph, &path, &paths);
    return paths;
  }

private:
  static void dfs(int vertex, const std::vector<std::vector<int>> &graph,
                  std::vector<int> *path,
                  std::vector<std::vector<int>> *paths) {
    int n = graph.size();
    path->push_back(vertex);
    if (vertex == n - 1) {
      paths->push_back(*path);
    } else {
      for (auto adj_vertex : graph[vertex]) {
        dfs(adj_vertex, graph, path, paths);
      }
    }
    path->pop_back();
  }
};
