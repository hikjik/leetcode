#pragma once

#include <climits>
#include <queue>
#include <vector>

// V is number of vertices in the graph
// E is number of edges in the graph
// N is the number of calls made to addEdge.
// M is the number of calls made to shortestPath.
// Time: O(N+M(V+ElogV))
// Space: O(E+V+N)
// Notes: [Dijkstra](https://w.wiki/4xCS), [Floyd-Warshall](https://w.wiki/4xCV)

namespace dijkstra {

// Time: O(N+M(V+ElogV))
// Space: O(E+V+N)
class Graph {
public:
  // O(V+E)
  Graph(int n, const std::vector<std::vector<int>> &edges) : adjacencyList(n) {
    for (const auto &edge : edges) {
      addEdge(edge);
    }
  }

  // O(1)
  void addEdge(const std::vector<int> &edge) {
    adjacencyList[edge[0]].emplace_back(edge[1], edge[2]);
  }

  // O(V+E⋅logV)
  int shortestPath(int source, int target) const {
    std::vector<int> distances(adjacencyList.size(), INT_MAX);
    distances[source] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        minHeap;
    minHeap.push({0, source});

    while (!minHeap.empty()) {
      const auto [distance, vertex] = minHeap.top();
      minHeap.pop();

      if (distance > distances[vertex]) {
        continue;
      }
      if (vertex == target) {
        return distance;
      }

      for (const auto &[adjVertex, weight] : adjacencyList[vertex]) {
        if (distance + weight < distances[adjVertex]) {
          distances[adjVertex] = distance + weight;
          minHeap.push({distances[adjVertex], adjVertex});
        }
      }
    }

    return -1;
  }

private:
  std::vector<std::vector<std::pair<int, int>>> adjacencyList;
};

} // namespace dijkstra

namespace floyd_warshall {

// Time: O(V^3+E+N⋅V^2+M)
// Space: O(V^2)
class Graph {
private:
  static constexpr int kInf = 0x3f3f3f3f;

public:
  // O(V^3+E)
  Graph(int n, const std::vector<std::vector<int>> &edges)
      : dist(n, std::vector<int>(n, kInf)) {
    for (const auto &edge : edges) {
      dist[edge[0]][edge[1]] = edge[2];
    }
    for (int u = 0; u < n; ++u) {
      dist[u][u] = 0;
    }
    for (int w = 0; w < n; ++w) {
      for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
          dist[u][v] = std::min(dist[u][v], dist[u][w] + dist[w][v]);
        }
      }
    }
  }

  // O(V^2)
  void addEdge(const std::vector<int> &edge) {
    const int n = dist.size();
    const auto from = edge[0], to = edge[1], weight = edge[2];
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        dist[u][v] = std::min(dist[u][v], dist[u][from] + weight + dist[to][v]);
      }
    }
  }

  // O(1)
  int shortestPath(int u, int v) const {
    return dist[u][v] == kInf ? -1 : dist[u][v];
  }

private:
  std::vector<std::vector<int>> dist;
};

} // namespace floyd_warshall
