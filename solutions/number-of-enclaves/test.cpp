#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{
        {0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    REQUIRE(3 == Solution::numEnclaves(grid));
  }
  {
    std::vector<std::vector<int>> grid{
        {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
    REQUIRE(0 == Solution::numEnclaves(grid));
  }
}
