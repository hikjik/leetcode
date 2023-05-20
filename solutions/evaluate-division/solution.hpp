#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
private:
  using Graph = std::unordered_map<std::string,
                                   std::vector<std::pair<std::string, double>>>;

public:
  static std::vector<double>
  calcEquation(const std::vector<std::vector<std::string>> &equations,
               const std::vector<double> &values,
               const std::vector<std::vector<std::string>> &queries) {
    Graph graph;
    for (size_t i = 0; i < equations.size(); ++i) {
      graph[equations[i][0]].emplace_back(equations[i][1], values[i]);
      graph[equations[i][1]].emplace_back(equations[i][0], 1.0 / values[i]);
    }

    std::vector<double> ans(queries.size());
    for (size_t i = 0; i < queries.size(); ++i) {
      auto source = queries[i][0], target = queries[i][1];
      std::unordered_set<std::string> visited;
      ans[i] = dfs(1.0, source, target, graph, &visited);
    }
    return ans;
  }

private:
  static double dfs(double value, const std::string &source,
                    const std::string &target, const Graph &graph,
                    std::unordered_set<std::string> *visited) {
    if (!graph.count(source)) {
      return -1.0;
    }
    if (source == target) {
      return value;
    }

    for (const auto &[node, weight] : graph.at(source)) {
      if (!visited->count(node)) {
        visited->insert(node);
        const auto new_value =
            dfs(value * weight, node, target, graph, visited);
        if (new_value >= 0.0) {
          return new_value;
        }
      }
    }

    return -1.0;
  }
};
