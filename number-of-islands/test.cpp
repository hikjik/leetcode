#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<char>> grid{{'1', '1', '1', '1', '0'},
                                        {'1', '1', '0', '1', '0'},
                                        {'1', '1', '0', '0', '0'},
                                        {'0', '0', '0', '0', '0'}};
    REQUIRE(1 == Solution::numIslands(grid));
  }
  {
    std::vector<std::vector<char>> grid{{'1', '1', '0', '0', '0'},
                                        {'1', '1', '0', '0', '0'},
                                        {'0', '0', '1', '0', '0'},
                                        {'0', '0', '0', '1', '1'}};
    REQUIRE(3 == Solution::numIslands(grid));
  }
}
