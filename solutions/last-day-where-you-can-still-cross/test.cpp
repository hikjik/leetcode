#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    int row = 2, col = 2;
    std::vector<std::vector<int>> cells{{1, 1}, {2, 1}, {1, 2}, {2, 2}};
    REQUIRE(2 == Solution::latestDayToCross(row, col, cells));
  }
  {
    int row = 2, col = 2;
    std::vector<std::vector<int>> cells{{1, 1}, {1, 2}, {2, 1}, {2, 2}};
    REQUIRE(1 == Solution::latestDayToCross(row, col, cells));
  }
  {
    int row = 3, col = 3;
    std::vector<std::vector<int>> cells{{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1},
                                        {1, 3}, {2, 3}, {3, 2}, {3, 1}};
    REQUIRE(3 == Solution::latestDayToCross(row, col, cells));
  }
}
