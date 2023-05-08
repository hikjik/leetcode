#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 4;
    std::vector<std::vector<int>> edges{{1, 2}, {2, 3}, {2, 4}};
    std::vector<int> expected{3, 4, 0};
    REQUIRE(expected == Solution::countSubgraphsForEachDiameter(n, edges));
  }
  {
    int n = 2;
    std::vector<std::vector<int>> edges{{1, 2}};
    std::vector<int> expected{1};
    REQUIRE(expected == Solution::countSubgraphsForEachDiameter(n, edges));
  }
  {
    int n = 3;
    std::vector<std::vector<int>> edges{{1, 2}, {2, 3}};
    std::vector<int> expected{2, 1};
    REQUIRE(expected == Solution::countSubgraphsForEachDiameter(n, edges));
  }
}
