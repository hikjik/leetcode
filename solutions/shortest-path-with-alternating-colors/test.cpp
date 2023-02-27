#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 3;
    std::vector<std::vector<int>> red_edges{{0, 1}, {1, 2}};
    std::vector<std::vector<int>> blue_edges{};
    std::vector<int> expected{0, 1, -1};
    REQUIRE(expected ==
            Solution::shortestAlternatingPaths(n, red_edges, blue_edges));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> red_edges{{0, 1}};
    std::vector<std::vector<int>> blue_edges{{2, 1}};
    std::vector<int> expected{0, 1, -1};
    REQUIRE(expected ==
            Solution::shortestAlternatingPaths(n, red_edges, blue_edges));
  }
  {
    int n = 5;
    std::vector<std::vector<int>> red_edges{{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    std::vector<std::vector<int>> blue_edges{{1, 2}, {2, 3}, {3, 1}};
    std::vector<int> expected{0, 1, 2, 3, 7};
    REQUIRE(expected ==
            Solution::shortestAlternatingPaths(n, red_edges, blue_edges));
  }
}
