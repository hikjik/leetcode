#include <catch.hpp>

#include <solution.hpp>

#include <tuple>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    REQUIRE(2 == Solution::minimumEffortPath(heights));
  }
  {
    std::vector<std::vector<int>> heights{{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    REQUIRE(1 == Solution::minimumEffortPath(heights));
  }
  {
    std::vector<std::vector<int>> heights{{1, 2, 1, 1, 1},
                                          {1, 2, 1, 2, 1},
                                          {1, 2, 1, 2, 1},
                                          {1, 2, 1, 2, 1},
                                          {1, 1, 1, 2, 1}};
    REQUIRE(0 == Solution::minimumEffortPath(heights));
  }
}
