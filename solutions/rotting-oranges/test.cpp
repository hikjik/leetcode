#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    REQUIRE(4 == Solution::orangesRotting(grid));
  }
  {
    std::vector<std::vector<int>> grid{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    REQUIRE(-1 == Solution::orangesRotting(grid));
  }
  {
    std::vector<std::vector<int>> grid{{0, 2}};
    REQUIRE(0 == Solution::orangesRotting(grid));
  }
}
