#include <catch.hpp>

#include <solution.hpp>

#include <vector>

TEST_CASE("Simple") {
  {
    Grid2D<int> grid1{{1, 1, 1, 0, 0},
                      {0, 1, 1, 1, 1},
                      {0, 0, 0, 0, 0},
                      {1, 0, 0, 0, 0},
                      {1, 1, 0, 1, 1}};
    Grid2D<int> grid2{{1, 1, 1, 0, 0},
                      {0, 0, 1, 1, 1},
                      {0, 1, 0, 0, 0},
                      {1, 0, 1, 1, 0},
                      {0, 1, 0, 1, 0}};
    REQUIRE(3 == Solution::countSubIslands(grid1, grid2));
  }
  {
    Grid2D<int> grid1{{1, 0, 1, 0, 1},
                      {1, 1, 1, 1, 1},
                      {0, 0, 0, 0, 0},
                      {1, 1, 1, 1, 1},
                      {1, 0, 1, 0, 1}};
    Grid2D<int> grid2{{0, 0, 0, 0, 0},
                      {1, 1, 1, 1, 1},
                      {0, 1, 0, 1, 0},
                      {0, 1, 0, 1, 0},
                      {1, 0, 0, 0, 1}};
    REQUIRE(2 == Solution::countSubIslands(grid1, grid2));
  }
}
