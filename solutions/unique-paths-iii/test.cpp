#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{
        {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};
    REQUIRE(2 == Solution::uniquePathsIII(grid));
  }
  {
    std::vector<std::vector<int>> grid{
        {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    REQUIRE(4 == Solution::uniquePathsIII(grid));
  }
  {
    std::vector<std::vector<int>> grid{{0, 1}, {2, 0}};
    REQUIRE(0 == Solution::uniquePathsIII(grid));
  }
}
