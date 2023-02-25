#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
    REQUIRE(2 == Solution::maxDistance(grid));
  }
  {
    std::vector<std::vector<int>> grid{{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    REQUIRE(4 == Solution::maxDistance(grid));
  }
  {
    std::vector<std::vector<int>> grid{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    REQUIRE(-1 == Solution::maxDistance(grid));
  }
}
