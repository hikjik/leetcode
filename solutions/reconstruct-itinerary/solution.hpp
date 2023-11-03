#pragma once

#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

// Time:
// Space:

class Solution {
private:
  using MinHeap = std::priority_queue<std::string, std::vector<std::string>,
                                      std::greater<std::string>>;
  using Graph = std::unordered_map<std::string, MinHeap>;

public:
  static std::vector<std::string>
  findItinerary(const std::vector<std::vector<std::string>> &tickets) {
    Graph graph;
    for (const auto &ticket : tickets) {
      const auto &from = ticket[0];
      const auto &to = ticket[1];
      graph[from].push(to);
    }

    std::vector<std::string> itinerary;
    dfs("JFK", &graph, &itinerary);
    std::reverse(itinerary.begin(), itinerary.end());
    return itinerary;
  }

private:
  static void dfs(const std::string &u, Graph *graph,
                  std::vector<std::string> *itinerary) {
    auto &queue = (*graph)[u];
    while (!queue.empty()) {
      const auto v = queue.top();
      queue.pop();
      dfs(v, graph, itinerary);
    }
    itinerary->push_back(u);
  }
};
