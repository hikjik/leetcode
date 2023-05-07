#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{{0, 1, -1}, {1, 0, -1}, {1, 1, 1}};
    REQUIRE(5 == Solution::cherryPickup(grid));
  }
  {
    std::vector<std::vector<int>> grid{{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}};
    REQUIRE(0 == Solution::cherryPickup(grid));
  }
}
