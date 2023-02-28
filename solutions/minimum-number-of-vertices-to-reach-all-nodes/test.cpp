#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 6;
    std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    std::vector<int> expected{0, 3};
    REQUIRE(expected == Solution::findSmallestSetOfVertices(n, edges));
  }
  {
    int n = 5;
    std::vector<std::vector<int>> edges{{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}};
    std::vector<int> expected{0, 2, 3};
    REQUIRE(expected == Solution::findSmallestSetOfVertices(n, edges));
  }
}
