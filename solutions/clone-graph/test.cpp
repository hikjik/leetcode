#include <catch.hpp>

#include <solution.hpp>

#include <unordered_set>

TEST_CASE("Empty") {
  REQUIRE(nullptr == bfs::Solution::cloneGraph(nullptr));
  REQUIRE(nullptr == dfs::Solution::cloneGraph(nullptr));
}

std::vector<Node *> BuildNodes(const std::vector<std::vector<int>> &graph) {
  int n = graph.size();

  std::vector<Node *> nodes;
  for (int i = 0; i < n; ++i) {
    nodes.push_back(new Node(i));
  }

  for (int i = 0; i < n; ++i) {
    for (auto neighbor : graph[i])
      nodes[i]->neighbors.push_back(nodes[neighbor - 1]);
  }

  return nodes;
}

std::vector<Node *> GetNodes(Node *node) {
  std::unordered_set<Node *> visited{node};
  std::queue<Node *> queue{{node}};

  while (!queue.empty()) {
    auto *u = queue.front();
    queue.pop();

    for (auto *v : u->neighbors) {
      if (!visited.count(v)) {
        visited.insert(v);
        queue.push(v);
      }
    }
  }

  std::vector<Node *> nodes(visited.size());
  for (auto *u : visited) {
    nodes[u->val] = u;
  }
  return nodes;
}

template <typename Solution>
void checkSolution(const std::vector<std::vector<int>> &edges,
                   const Solution &solution) {
  REQUIRE(!edges.empty());

  auto nodes = BuildNodes(edges);

  auto *cloned = solution.cloneGraph(nodes.front());
  auto cloned_nodes = GetNodes(cloned);

  REQUIRE(nodes.size() == cloned_nodes.size());
  for (size_t i = 0; i < nodes.size(); ++i) {
    REQUIRE_FALSE(nodes[i] == cloned_nodes[i]);
  }

  std::vector<std::vector<int>> cloned_graph(cloned_nodes.size());
  for (size_t i = 0; i < nodes.size(); ++i) {
    for (auto *v : cloned_nodes[i]->neighbors) {
      cloned_graph[i].push_back(v->val + 1);
    }
  }

  REQUIRE(edges == cloned_graph);

  for (auto *node : nodes) {
    delete node;
  }
  for (auto *node : cloned_nodes) {
    delete node;
  }
}

TEST_CASE("Simple") {
  struct TestCase {
    std::vector<std::vector<int>> edges;
    std::vector<std::vector<int>> expected;
  };

  std::vector<TestCase> test_cases{
      {
          .edges{{2, 4}, {1, 3}, {2, 4}, {1, 3}},
          .expected{{2, 4}, {1, 3}, {2, 4}, {1, 3}},
      },
      {
          .edges{{}},
          .expected{{}},
      },
  };

  SECTION("BFS") {
    for (const auto &[edges, expected] : test_cases) {
      checkSolution(edges, bfs::Solution());
    }
  }

  SECTION("DFS") {
    for (const auto &[edges, expected] : test_cases) {
      checkSolution(edges, dfs::Solution());
    }
  }
}
