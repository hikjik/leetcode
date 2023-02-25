#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    const std::vector<std::vector<int>> grid{{0, 1}, {1, 0}};
    REQUIRE(2 == Solution::shortestPathBinaryMatrix(grid));
  }
  {
    const std::vector<std::vector<int>> grid{{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    REQUIRE(4 == Solution::shortestPathBinaryMatrix(grid));
  }
  {
    const std::vector<std::vector<int>> grid{{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    REQUIRE(-1 == Solution::shortestPathBinaryMatrix(grid));
  }
  {
    const std::vector<std::vector<int>> grid{{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    REQUIRE(3 == Solution::shortestPathBinaryMatrix(grid));
  }
  {
    const std::vector<std::vector<int>> grid{{0}};
    REQUIRE(1 == Solution::shortestPathBinaryMatrix(grid));
  }
  {
    const std::vector<std::vector<int>> grid{
        {0, 0, 1, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 0}, {1, 0, 0, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 0, 1},
        {0, 0, 1, 0, 0, 0, 0}};
    REQUIRE(10 == Solution::shortestPathBinaryMatrix(grid));
  }
}
