#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    REQUIRE(1 == Solution::equalPairs(grid));
  }
  {
    std::vector<std::vector<int>> grid{
        {3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    REQUIRE(3 == Solution::equalPairs(grid));
  }
}
