#include <catch.hpp>

#include <solution.hpp>

TEST_CASE("Simple") {
  {
    std::vector<std::vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    REQUIRE(2 == Solution::findMinArrowShots(points));
  }
  {
    std::vector<std::vector<int>> points{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    REQUIRE(4 == Solution::findMinArrowShots(points));
  }
  {
    std::vector<std::vector<int>> points{{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    REQUIRE(2 == Solution::findMinArrowShots(points));
  }
  {
    std::vector<std::vector<int>> points{{9, 12}, {1, 10}, {4, 11}, {8, 12},
                                         {3, 9},  {6, 9},  {6, 7}};
    REQUIRE(2 == Solution::findMinArrowShots(points));
  }
}
