#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> graph{{1, 2}, {3}, {3}, {}};
    std::vector<std::vector<int>> paths{{0, 1, 3}, {0, 2, 3}};
    REQUIRE(paths == Solution::allPathsSourceTarget(graph));
  }
  {
    std::vector<std::vector<int>> graph{{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    std::vector<std::vector<int>> paths{
        {0, 4}, {0, 3, 4}, {0, 1, 3, 4}, {0, 1, 2, 3, 4}, {0, 1, 4}};
    REQUIRE(paths == Solution::allPathsSourceTarget(graph));
  }
}
