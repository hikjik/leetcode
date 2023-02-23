#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{
        {4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    REQUIRE(8 == Solution::countNegatives(grid));
  }
  {
    std::vector<std::vector<int>> grid{{3, 2}, {1, 0}};
    REQUIRE(0 == Solution::countNegatives(grid));
  }
  {
    std::vector<std::vector<int>> grid{
        {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
    REQUIRE(9 == Solution::countNegatives(grid));
  }
}
