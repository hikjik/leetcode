#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> graph{{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    std::vector<int> safe{2, 4, 5, 6};
    REQUIRE(safe == Solution::eventualSafeNodes(graph));
  }
  {
    std::vector<std::vector<int>> graph{
        {1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}};
    std::vector<int> safe{4};
    REQUIRE(safe == Solution::eventualSafeNodes(graph));
  }
}
