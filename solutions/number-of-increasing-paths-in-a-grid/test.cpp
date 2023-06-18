#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{{1, 1}, {3, 4}};
    REQUIRE(8 == Solution::countPaths(grid));
  }
  {
    std::vector<std::vector<int>> grid{{1}, {2}};
    REQUIRE(3 == Solution::countPaths(grid));
  }
}
