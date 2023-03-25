#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int n = 3;
    std::vector<std::vector<int>> edges{{0, 1}, {0, 2}, {1, 2}};
    REQUIRE(0 == Solution::countPairs(n, edges));
  }
  {
    int n = 7;
    std::vector<std::vector<int>> edges{{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
    REQUIRE(14 == Solution::countPairs(n, edges));
  }
}
