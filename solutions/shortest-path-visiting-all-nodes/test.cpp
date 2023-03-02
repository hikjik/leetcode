#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> graph{{1, 2, 3}, {0}, {0}, {0}};
    REQUIRE(4 == Solution::shortestPathLength(graph));
  }
  {
    std::vector<std::vector<int>> graph{{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    REQUIRE(4 == Solution::shortestPathLength(graph));
  }
}
