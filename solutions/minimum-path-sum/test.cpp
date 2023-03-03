#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    REQUIRE(7 == Solution::minPathSum(grid));
  }
  {
    std::vector<std::vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
    REQUIRE(12 == Solution::minPathSum(grid));
  }
}
