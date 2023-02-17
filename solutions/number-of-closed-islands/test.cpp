#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{{1, 1, 1, 1, 1, 1, 1, 0},
                                       {1, 0, 0, 0, 0, 1, 1, 0},
                                       {1, 0, 1, 0, 1, 1, 1, 0},
                                       {1, 0, 0, 0, 0, 1, 0, 1},
                                       {1, 1, 1, 1, 1, 1, 1, 0}};
    REQUIRE(2 == Solution::closedIsland(grid));
  }
  {
    std::vector<std::vector<int>> grid{
        {0, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 1, 1, 0}};
    REQUIRE(1 == Solution::closedIsland(grid));
  }
  {
    std::vector<std::vector<int>> grid{
        {1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1}, {1, 0, 1, 1, 1, 0, 1}, {1, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}};
    REQUIRE(2 == Solution::closedIsland(grid));
  }
}
