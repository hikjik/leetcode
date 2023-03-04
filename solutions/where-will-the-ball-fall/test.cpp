#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> grid{{1, 1, 1, -1, -1},
                                       {1, 1, 1, -1, -1},
                                       {-1, -1, -1, 1, 1},
                                       {1, 1, 1, 1, -1},
                                       {-1, -1, -1, -1, -1}};
    std::vector<int> expected{1, -1, -1, -1, -1};
    REQUIRE(expected == Solution::findBall(grid));
  }
  {
    std::vector<std::vector<int>> grid{{-1}};
    std::vector<int> expected{-1};
    REQUIRE(expected == Solution::findBall(grid));
  }
  {
    std::vector<std::vector<int>> grid{{1, 1, 1, 1, 1, 1},
                                       {-1, -1, -1, -1, -1, -1},
                                       {1, 1, 1, 1, 1, 1},
                                       {-1, -1, -1, -1, -1, -1}};
    std::vector<int> expected{0, 1, 2, 3, 4, -1};
    REQUIRE(expected == Solution::findBall(grid));
  }
}
