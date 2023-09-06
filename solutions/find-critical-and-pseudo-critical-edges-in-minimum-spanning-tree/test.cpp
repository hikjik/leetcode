#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 5;
    std::vector<std::vector<int>> edges{{0, 1, 1}, {1, 2, 1}, {2, 3, 2},
                                        {0, 3, 2}, {0, 4, 3}, {3, 4, 3},
                                        {1, 4, 6}};
    std::vector<std::vector<int>> expected{{0, 1}, {2, 3, 4, 5}};
    REQUIRE(expected == Solution::findCriticalAndPseudoCriticalEdges(n, edges));
  }
  {
    int n = 5;
    std::vector<std::vector<int>> edges{
        {0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1}};
    std::vector<std::vector<int>> expected{{}, {0, 1, 2, 3}};
    REQUIRE(expected == Solution::findCriticalAndPseudoCriticalEdges(n, edges));
  }
}
