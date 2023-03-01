#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> graph{{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    REQUIRE_FALSE(Solution::isBipartite(graph));
  }
  {
    std::vector<std::vector<int>> graph{{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    REQUIRE(Solution::isBipartite(graph));
  }
}
