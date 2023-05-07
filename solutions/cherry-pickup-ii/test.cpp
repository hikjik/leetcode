#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{
        {3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    REQUIRE(24 == Solution::cherryPickup(grid));
  }
  {
    std::vector<std::vector<int>> grid{{1, 0, 0, 0, 0, 0, 1},
                                       {2, 0, 0, 0, 0, 3, 0},
                                       {2, 0, 9, 0, 0, 0, 0},
                                       {0, 3, 0, 5, 4, 0, 0},
                                       {1, 0, 2, 3, 0, 0, 6}};
    REQUIRE(28 == Solution::cherryPickup(grid));
  }
}
