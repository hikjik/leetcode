#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Dijkstra") {
  int n = 4;
  std::vector<std::vector<int>> edges{
      {0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
  auto graph = dijkstra::Graph(n, edges);

  REQUIRE(6 == graph.shortestPath(3, 2));
  REQUIRE(-1 == graph.shortestPath(0, 3));
  graph.addEdge({1, 3, 4});
  REQUIRE(6 == graph.shortestPath(0, 3));
}

TEST_CASE("Floyd-Warshall") {
  int n = 4;
  std::vector<std::vector<int>> edges{
      {0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
  auto graph = floyd_warshall::Graph(n, edges);

  REQUIRE(6 == graph.shortestPath(3, 2));
  REQUIRE(-1 == graph.shortestPath(0, 3));
  graph.addEdge({1, 3, 4});
  REQUIRE(6 == graph.shortestPath(0, 3));
}
